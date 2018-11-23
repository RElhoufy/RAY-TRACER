#include "triangle.h"
#include <iostream>
#include <fstream>
using namespace std;

triangle::triangle()
{
	ambientColor = glm::vec3(0, 0, 0);
	diffuseColor = glm::vec3(0, 0, 0);
	specularColor = glm::vec3(0, 0, 0);
	shineFactor = 0;
}

void triangle::setVertexList(std::vector<glm::vec3> v)
{
	triangle::vertexList = v;
}

void triangle::setAmbientColor(glm::vec3 a)
{
	triangle::ambientColor = a;
}

void triangle::setDiffuseColor(glm::vec3 d)
{
	diffuseColor = d;
}

void triangle::setSpecularColor(glm::vec3 s)
{
	specularColor = s;
}

void triangle::setShineFactor(float s)
{
	triangle::shineFactor = s;
}

void triangle::printVertexList()
{
	for (int i = 0; i < getVertexList().size(); i++) {
		cout <<" v"<< i+1 << " : " << getVertexList().at(i).x << " " << getVertexList().at(i).y << " " << getVertexList().at(i).z << endl;
	}
}

std::vector<glm::vec3> triangle::getVertexList()
{
	return triangle::vertexList;
}

glm::vec3 triangle::getAmbientColor()
{
	return ambientColor;
}

glm::vec3 triangle::getDiffuseColor()
{
	return diffuseColor;
}

glm::vec3 triangle::getSpecularColor()
{
	return specularColor;
}

float triangle::getShineFactor()
{
	return shineFactor;
}


triangle::triangle(string filePath)
{
	std::string test;
	ifstream myFile(filePath);
	vector<glm::vec3> testVertexList;
	if (myFile.is_open())
	{
		cout << "file could be opened" << endl;
	}
	else
		cout << "file could not be opened";

	while (!myFile.eof())
	{
		getline(myFile, test);
		while (test.compare("triangle") != 0)
		{
			getline(myFile, test);
		}
		//parsing v1
		getline(myFile, test);
		char delimiter = test.find(" ");
		test = test.substr(delimiter);
		string testx = test.substr(0, delimiter - 1);
		int x = stoi(testx);
		string testy = test.substr(testx.size(), delimiter);
		int y = stoi(testy);
		string testz = test.substr(testx.size() + testy.size(), delimiter);
		int z = stoi(testz);
		testVertexList.push_back(glm::vec3(x, y, z));

		//parsing v2
		getline(myFile, test);
		delimiter = test.find(" ");
		test = test.substr(delimiter);
		testx = test.substr(0, delimiter - 1);
		int x2 = stoi(testx);
		testy = test.substr(testx.size(), delimiter);
		int y2 = stoi(testy);
		testz = test.substr(testx.size() + testy.size(), delimiter);
		int z2 = stoi(testz);
		testVertexList.push_back(glm::vec3(x2, y2, z2));

		//parsing v3
		getline(myFile, test);
		delimiter = test.find(" ");
		test = test.substr(delimiter);
		testx = test.substr(0, delimiter - 1);
		int x3 = stoi(testx);
		testy = test.substr(testx.size(), delimiter);
		int y3 = stoi(testy);
		testz = test.substr(testx.size() + testy.size(), delimiter);
		int z3 = stoi(testz);
		testVertexList.push_back(glm::vec3(x3, y3, z3));
		//setting the vertexlist
		setVertexList(testVertexList);

		//parsing ambientColor
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		float xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		float yf = stof(testy);
		testz = test.substr(testy.size() + testx.size(), delimiter);
		float zf = stof(testz);
		setAmbientColor(glm::vec3(xf, yf, zf));

		//parsing diffuseColor
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testy.size() + testx.size(), delimiter);
		zf = stof(testz);
		setDiffuseColor(glm::vec3(xf, yf, zf));

		//parsing specularColor
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testy.size() + testx.size(), delimiter);
		zf = stof(testz);
		setSpecularColor(glm::vec3(xf, yf, zf));

		//parsing shineFactor
		getline(myFile, test);
		delimiter = test.find(' ');
		xf = stof(test.substr(delimiter));
		setShineFactor(xf);


		break;
	}
}
