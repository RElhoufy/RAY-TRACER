#include "plane.h"
#include <iostream>
#include <fstream>

using namespace std;

glm::vec3 plane::getNormal()
{
	return normal;
}

glm::vec3 plane::getPosition()
{
	return position;
}

glm::vec3 plane::getAmbientColor()
{
	return ambientColor;
}

glm::vec3 plane::getDiffuseColor()
{
	return diffuseColor;
}

glm::vec3 plane::getSpecularColor()
{
	return specularColor;
}

int plane::getShineFactor()
{
	return shineFactor;
}

void plane::setNormal(glm::vec3 v)
{
	normal = v;
}

void plane::setPosition(glm::vec3 p)
{
	position = p;
}

void plane::setAmbientColor(glm::vec3 a)
{
	ambientColor = a;
}

void plane::setDiffuseColor(glm::vec3 c)
{
	diffuseColor = c;
}

void plane::setSpecularColor(glm::vec3 s)
{
	specularColor = s;
}

void plane::setShineFactor(int s)
{
	shineFactor = s;
}

plane::plane() 
{
	normal = glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 0);
	ambientColor = glm::vec3(0, 0, 0);
	diffuseColor = glm::vec3(0, 0, 0);
	specularColor = glm::vec3(0, 0, 0);
	shineFactor = 0;
}

plane::plane(std::string filePath)
{
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
		while (test.compare("plane") != 0)
		{
			getline(myFile, test);
		}
		
		// parsing normal
		getline(myFile, test);
		char delimiter = test.find(' ');
		int x = stoi(test.substr(delimiter, delimiter-1));
		int y = stoi(test.substr(delimiter+2, delimiter-1 ));
		int z = stoi(test.substr(delimiter+4, delimiter - 1));
		setNormal(glm::vec3(x, y, z));
		
		//parsing position
		getline(myFile, test);
		 delimiter = test.find(' ');
		 x = stoi(test.substr(delimiter, delimiter - 1));
		 y = stoi(test.substr(delimiter + 2, delimiter - 1));
		 z = stoi(test.substr(delimiter + 5, delimiter - 1));	//+5 because of extra - sign 
		 setPosition(glm::vec3(x, y, z));

		 //parsing ambientColor 
		 getline(myFile, test);
		 delimiter = test.find(' ');
		 float xf = stof(test.substr(delimiter , delimiter+1));
		 float yf= stof(test.substr(delimiter +4, delimiter +1));
		 float zf = stof(test.substr(delimiter + 8, delimiter + 1));	
		 setAmbientColor(glm::vec3(xf,yf, zf));

		 //parsing diffuseColor
		 getline(myFile, test);
		 delimiter = test.find(' ');
		 xf = stof(test.substr(delimiter, delimiter + 1));
		 yf = stof(test.substr(delimiter + 4, delimiter + 1));
		 zf = stof(test.substr(delimiter + 8, delimiter + 1));
		 setDiffuseColor(glm::vec3(xf, yf, zf));

		 //parsing specularColor
		 getline(myFile, test);
		 delimiter = test.find(' ');
		 xf = stof(test.substr(delimiter, delimiter + 1));
		 yf = stof(test.substr(delimiter + 4, delimiter + 1));
		 zf = stof(test.substr(delimiter + 8, delimiter + 1));
		 setSpecularColor(glm::vec3(xf, yf, zf));

		 //parsing shineFactor
		 getline(myFile, test);
		 delimiter = test.find(' ');
		 x = stoi(test.substr(delimiter));
		 setShineFactor(x);

		break;
	}
	myFile.close();
}