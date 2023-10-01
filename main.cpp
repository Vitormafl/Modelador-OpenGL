#include "Visualization/Visualization.h"

int main()
{
	Sphere testSphere = Sphere(0.5f, glm::vec3(0.0f, 0.0f, 0.0f));
	testSphere.setSphereOctree(4);
	testSphere.sphereOctree->setRenderData();

	//std::cout << testSphere.sphereOctree->octreeData.lineIndices.size() / 2 << std::endl;
	//std::cout << testSphere.sphereOctree->octreeData.triangleIndices.size() / 3 << std::endl;
	//std::cout << testSphere.sphereOctree->octreeData.vertices.size() / 6 << std::endl;

	//runFacesVisualization(testSphere);
	runWireframeVisualization(testSphere);

	return 0;
}