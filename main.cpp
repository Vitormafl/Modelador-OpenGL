#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

// Vertex Shader
const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec2 aPos;
    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
    }
)";

// Fragment Shader
const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    uniform vec3 pointColor;
    void main()
    {
        FragColor = vec4(pointColor, 1.0);
    }
)";

int main()
{
    // Inicializar GLFW
    if (!glfwInit())
    {
        std::cerr << "Falha ao inicializar GLFW" << std::endl;
        return -1;
    }

    // Configurar as opções da janela GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Criar uma janela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Desenhar Pontos", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Falha ao criar janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Tornar a janela o contexto principal do OpenGL   
    glfwMakeContextCurrent(window);

    // Inicializar GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Falha ao inicializar GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    //testing commit

    // Compilar o Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // Checar erros de compilação do Vertex Shader
    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "Erro ao compilar Vertex Shader: " << infoLog << std::endl;
        glfwTerminate();
        return -1;
    }

    // Compilar o Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Checar erros de compilação do Fragment Shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "Erro ao compilar Fragment Shader: " << infoLog << std::endl;
        glfwTerminate();
        return -1;
    }

    // Vincular os shaders em um programa
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Checar erros de vinculação do programa
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Erro ao vincular programa: " << infoLog << std::endl;
        glfwTerminate();
        return -1;
    }

    // Limpar os shaders que já foram vinculados
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Definir os vértices dos pontos
    std::vector<float> points = {
        -0.5f,  0.5f,   // Coordenadas do primeiro ponto
         0.5f,  0.5f,   // Coordenadas do segundo ponto
         0.5f, -0.5f,    // Coordenadas do terceiro ponto
        -0.5f, -0.5f,
        0.0f, 0.65f
    };

    // Criar um buffer de vértices
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(float), points.data(), GL_STATIC_DRAW);

    // Criar um VAO (Vertex Array Object)
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Loop principal da aplicação
    while (!glfwWindowShouldClose(window))
    {
        // Processar eventos GLFW
        glfwPollEvents();

        // Limpar o buffer de cor
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Usar o programa de shaders
        glUseProgram(shaderProgram);

        // Desenhar os pontos
        glBindVertexArray(VAO);
        for (int i = 0; i < points.size() / 2; ++i)
        {
            GLint pointColorLocation = glGetUniformLocation(shaderProgram, "pointColor");
            glUniform3f(pointColorLocation, 1.0f, 1.0f, 1.0f); // Cor branca para todos os pontos
            glDrawArrays(GL_POINTS, i, 1);
        }

        // Trocar os buffers de tela
        glfwSwapBuffers(window);
    }

    // Limpar os recursos alocados
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Encerrar GLFW
    glfwTerminate();

    return 0;
}