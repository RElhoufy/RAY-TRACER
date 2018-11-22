#include "camera.h"
#include "plane.h"
#include "sphere.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	string filePath;
	filePath = "C:\\Users\\alway\\Desktop\\COMP371_PROJECT\\scene1.txt";
	camera test;
	test = camera(filePath);
	
	cout << "camera properties" << endl;
	cout << "position(xyz)" << test.getPosition().x << test.getPosition().y << test.getPosition().z << endl;
	cout << "fov : " << test.getFov() << endl;
	cout << "f : " << test.getFocalLength() << endl;
	cout << "a : " << test.getAspectRatio() << endl;
	
	cout << "\n==========================================================\n";
	
	plane planeTest = plane(filePath);
	cout << "plane properties: " << endl;
	cout << "normal (xyz): " <<planeTest.getNormal().x << " " << planeTest.getNormal().y << " " << planeTest.getNormal().z << endl;
	cout << "position (xyz): " << planeTest.getPosition().x << " " << planeTest.getPosition().y << " " << planeTest.getPosition().z << endl;
	cout << "ambient Color (xyz): " << planeTest.getAmbientColor().x << " " <<  planeTest.getAmbientColor().y << " " << planeTest.getAmbientColor().z << endl;
	cout << "diffuse Color (xyz): " << planeTest.getDiffuseColor().x << " " << planeTest.getDiffuseColor().y << " " << planeTest.getDiffuseColor().z << endl;
	cout << "specular Color (xyz): " << planeTest.getSpecularColor().x << " " << planeTest.getSpecularColor().y << " " << planeTest.getSpecularColor().z << endl;
	cout << "shine factor : " << planeTest.getShineFactor();

	cout << "\n==========================================================\n";

	sphere sphereTest = sphere(filePath);
	cout << "position (xyz): " << sphereTest.getPosition().x << " " << sphereTest.getPosition().y << " " << sphereTest.getPosition().z << endl;
	cout << "radius factor : " << sphereTest.getRadius() << endl;



	system("pause");

}