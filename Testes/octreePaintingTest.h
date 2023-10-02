//#include "../Primitives/Sphere.h"
//
//void Teste1() {
//
//	Sphere testSphere = Sphere(0.5f, glm::vec3(0.0f, 0.0f, 0.0f));
//	testSphere.setSphereOctree(2);
//	std::cout << testSphere.sphereOctree->octreeData.lineIndices.size() << std::endl;
//	std::cout << testSphere.sphereOctree->octreeData.triangleIndices.size() << std::endl;
//	std::cout << testSphere.sphereOctree->octreeData.vertices.size() << std::endl;
//	testSphere.sphereOctree->setRenderData();
//	std::cout << testSphere.sphereOctree->octreeData.lineIndices.size() / 2 << std::endl;
//	std::cout << testSphere.sphereOctree->octreeData.triangleIndices.size() / 3 << std::endl;
//	std::cout << testSphere.sphereOctree->octreeData.vertices.size() / 3 << std::endl;
	//cout << "Octree root state:" << testSphere.sphereOctree->rootNode->objectIntersect << endl;
	//
	//for (int i = 0; i < 8; i++) {
	//	cout << "Octree child " << i << " state:" << testSphere.sphereOctree->rootNode->childNodes[i]->objectIntersect << endl;
	//	cout << "Octree child " << i << " is leaf:" << testSphere.sphereOctree->rootNode->childNodes[i]->isLeaf << endl;
	//}
	//
	//for (int i = 0; i < 8; i++) {
	//	
	//	cout << "NODE "<< i <<" CHILDS" << endl;
	//	
	//	for (int j = 0; j < 8; j++) {
	//		cout << "Octree child " << j << " state:" << testSphere.sphereOctree->rootNode->childNodes[i]->childNodes[j]->objectIntersect << endl;
	//		cout << "Octree child " << j << " is leaf:" << testSphere.sphereOctree->rootNode->childNodes[i]->childNodes[j]->isLeaf << endl;
	//
	//		cout << "" << endl;
	//	}
	//}



//}