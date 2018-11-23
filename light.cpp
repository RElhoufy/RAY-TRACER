#include "light.h"
#include <iostream>
#include <fstream>


using namespace std;

light::light()
{
	position = glm::vec3(0, 0, 0);
	ambientColor = glm::vec3(0, 0, 0);
	diffuseColor = glm::vec3(0, 0, 0);
	specularColor = glm::vec3(0, 0, 0);
}

void light::setPosition(glm::vec3 v)
{
	position = v;
}

void light::setAmbientColor(glm::vec3 a)
{
	ambientColor = a;
}

void light::setDiffuseColor(glm::vec3 d)
{
	diffuseColor = d;
}

void light::setSpecularColor(glm::vec3 s)
{
	specularColor = s;
}

glm::vec3 light::getPosition()
{
	return position;
}

glm::vec3 light::getAmbientColor()
{
	return ambientColor;
}

glm::vec3 light::getDiffuseColor()
{
	return diffuseColor;
}

glm::vec3 light::getSpecularColor()
{
	return specularColor;
}

light::light(string filePath) {
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
		while (test.compare("light") != 0)
		{
			getline(myFile, test);
		}

		//parsing position
		getline(myFile, test);
		char delimiter = test.find(" ");
		test = test.substr(delimiter);
		string testx = test.substr(0,delimiter - 1);
		int x = stoi(testx);
		string testy = test.substr(testx.size(), delimiter);
		int y = stoi(testy);
		string testz = test.substr(testx.size() + testy.size(), delimiter);
		int z = stoi(testz);
		setPosition(glm::vec3(x, y, z));

		//parsing ambientColor
		getline(myFile, test);
		test = test.substr(delimiter);
		testx = test.substr(0, delimiter);
		float xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		float yf = stof(testy);
		testz = test.substr(testx.size() + testy.size(), delimiter);
		float zf = stof(testz);
		setAmbientColor(glm::vec3(xf, yf, zf));

		//parsing diffuseColor
		getline(myFile, test);
		test = test.substr(delimiter);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testx.size() + testy.size(), delimiter);
		zf = stof(testz);
		setDiffuseColor(glm::vec3(xf, yf, zf));

		//parsing specularColor
		getline(myFile, test);
		test = test.substr(delimiter);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testx.size() + testy.size(), delimiter);
		zf = stof(testz);
		setSpecularColor(glm::vec3(xf, yf, zf));

		break;
	}
	myFile.close();
}
