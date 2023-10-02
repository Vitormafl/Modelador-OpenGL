#include "Visualization/Visualization.h"
#include "Octree/booleans.h"

int main()
{
	Octree testOctree1(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f, 5);
	Sphere testSphere1(0.5f, glm::vec3(0.5f, 0.5f, 0.5f));
	testOctree1.setSphereOctree(testSphere1);

	Octree testOctree2(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f, 5);
	Sphere testSphere2(0.3f, glm::vec3(-0.3f, 0.15f, 0.1f));
	testOctree2.setSphereOctree(testSphere2);

	Octree testOctree(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f, 5);
	Cube testCube(glm::vec3(-0.25f,-0.25f,-0.25f), glm::vec3(glm::vec3(0.25f,0.25f,0.25f)));
	testOctree.setCubeOctree(testCube);
	
	//Octree testOctree3 = octreeUnion(testOctree, testOctree2);

	//testOctree.scaling(2);


	testOctree.setRenderData();
	//testOctree2.octreeData = testOctree3->octreeData;

	runFacesVisualization(testOctree);

	return 0;
}

int main1() {

	//Octree testOctree(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f, 5);
	//Sphere testSphere = Sphere(0.5, glm::vec3(0.0f, 0.0f, 0.0f));
	//testOctree.setSphereOctree(testSphere);
	//
	//cout << "\n\n\n octree: " << testOctree.save() << "\n\n\n";
	//cout << "sphere: " << testSphere.save() << "\n\n\n";

	Octree testOctree = loadOctree("octreeString.txt");
	testOctree.setRenderData();
	runFacesVisualization(testOctree);

	return 0;
}