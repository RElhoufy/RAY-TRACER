#include "sphere.h"
#include <iostream>
#include <fstream>

using namespace std;

void sphere::setPosition(glm::vec3 v)
{
	position = v;
}

void sphere::setRadius(int r)
{
	radius = r;
}

void sphere::setAmbientColor(glm::vec3 a)
{
	ambientColor = a;
}

void sphere::setDiffuseColor(glm::vec3 d)
{
	diffuseColor = d;
}

void sphere::setSpecularColor(glm::vec3 s)
{
	specularColor = s;
}

void sphere::setShineFactor(int s)
{
	shineFactor = s;
}

glm::vec3 sphere::getPosition()
{
	return position;
}

int sphere::getRadius()
{
	return radius;
}

glm::vec3 sphere::getAmbientColor()
{
	return ambientColor;
}

glm::vec3 sphere::getDiffuseColor()
{
	return diffuseColor;
}

glm::vec3 sphere::getSpecularColor()
{
	return specularColor;
}

int sphere::getShineFactor()
{
	return shineFactor;
}

sphere::sphere() 
{
	position = glm::vec3(0,0,0);
	radius = 0;
	ambientColor = glm::vec3(0,0,0);
	diffuseColor = glm::vec3(0,0,0);
	specularColor = glm::vec3(0,0,0);
	shineFactor = 0;
}

sphere::sphere(string filePath) {
	std::string test;
	ifstream myFile(filePath);
	if (myFile.is_open())
	{
		cout << "file could be opened" << endl;
	}
	else
		cout << "file could not be opened";

	while (!myFile.eof())
	{
		getline(myFile, test);
		while (test.compare("sphere") != 0)
		{
			getline(myFile, test);
		}
		
		//parsing position
		getline(myFile, test);
		char delimiter = test.find(' ');
		int x = stoi(test.substr(delimiter, delimiter - 1));
		int y = stoi(test.substr(delimiter + 2, delimiter - 1));
		int z = stoi(test.substr(delimiter + 5, delimiter - 1));	//+5 because of extra - sign 
		setPosition(glm::vec3(x, y, z));

		//parsing radius
		getline(myFile, test);
		delimiter = test.find(' ');
		x = stoi(test.substr(delimiter));
		setRadius(x);

		//parsing ambientColor


		break;
	}
}