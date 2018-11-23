#include "camera.h"
#include "plane.h"
#include "sphere.h"
#include "light.h"
#include "triangle.h"
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
	vector<sphere> sphereListTest = sphereTest.getSphereList();
	cout << "sphere Properties" << endl;
	
	for (int i = 0; i < sphereListTest.size(); i++) 
	{
		cout << "sphere " << i + 1 << " properties: " << endl;
		cout << "position (xyz): " << sphereListTest.at(i).getPosition().x << " " << sphereListTest.at(i).getPosition().y << " " << sphereListTest.at(i).getPosition().z << endl;
		cout << "radius factor : " << sphereListTest.at(i).getRadius() << endl;
		cout << "ambientColor (xyz): " << sphereListTest.at(i).getAmbientColor().x << " " << sphereListTest.at(i).getAmbientColor().y << " " << sphereListTest.at(i).getAmbientColor().z << endl;
		cout << "diffuseColor (xyz): " << sphereListTest.at(i).getDiffuseColor().x << " " << sphereListTest.at(i).getDiffuseColor().y << " " << sphereListTest.at(i).getDiffuseColor().z << endl;
		cout << "specularColor (xyz): " << sphereListTest.at(i).getSpecularColor().x << " " << sphereListTest.at(i).getSpecularColor().y << " " << sphereListTest.at(i).getSpecularColor().z << endl;
		cout << "shine factor : " << sphereListTest.at(i).getShineFactor() << endl; 

	}
	/*cout << "position (xyz): " << sphereTest.getPosition().x << " " << sphereTest.getPosition().y << " " << sphereTest.getPosition().z << endl;
	cout << "radius factor : " << sphereTest.getRadius() << endl;
	cout << "ambientColor (xyz): " << sphereTest.getAmbientColor().x << " " << sphereTest.getAmbientColor().y << " " << sphereTest.getAmbientColor().z << endl;
	cout << "diffuseColor (xyz): " << sphereTest.getDiffuseColor().x << " " << sphereTest.getDiffuseColor().y << " " << sphereTest.getDiffuseColor().z << endl;
	cout << "specularColor (xyz): " << sphereTest.getSpecularColor().x << " " << sphereTest.getSpecularColor().y << " " << sphereTest.getSpecularColor().z << endl;
	cout << "shine factor : " << sphereTest.getShineFactor() << endl;*/

	cout << "\n==========================================================\n";

	light lightTest = light(filePath);
	cout << "light Properties: " << endl;
	cout << "position (xyz): " << lightTest.getPosition().x << " " << lightTest.getPosition().y << " " << lightTest.getPosition().z << endl;
	cout << "ambientColor (xyz): " << lightTest.getAmbientColor().x << " " << lightTest.getAmbientColor().y << " " << lightTest.getAmbientColor().z << endl;
	cout << "diffuseColor (xyz): " << lightTest.getDiffuseColor().x << " " << lightTest.getDiffuseColor().y << " " << lightTest.getDiffuseColor().z << endl;
	cout << "specularColor (xyz): " << lightTest.getSpecularColor().x << " " << lightTest.getSpecularColor().y << " " << lightTest.getSpecularColor().z << endl;

	cout << "\n==========================================================\n";
	triangle triangleTest = triangle(filePath);
	triangleTest.printVertexList();
	cout << "ambientColor (xyz): " << triangleTest.getAmbientColor().x << " " << triangleTest.getAmbientColor().y << " " << triangleTest.getAmbientColor().z << endl;
	cout << "diffuseColor (xyz): " << triangleTest.getDiffuseColor().x << " " << triangleTest.getDiffuseColor().y << " " << triangleTest.getDiffuseColor().z << endl;
	cout << "specularColor (xyz): " << triangleTest.getSpecularColor().x << " " << triangleTest.getSpecularColor().y << " " << triangleTest.getSpecularColor().z << endl;
	cout << "shine factor : " << triangleTest.getShineFactor() << endl;


	system("pause");

}