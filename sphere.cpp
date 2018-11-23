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

std::vector<sphere> sphere::getSphereList()
{
	return sphereList;
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


int sphere::countSpheres(string filePath) //once the file is opened this will count the number of spheres, it will be used when defining each sphere.
{
	string test;
	ifstream myFile(filePath);
	

	while (!myFile.eof()) 
	{
		getline(myFile, test);
		if (test.compare("sphere") == 0)
			count++;
	}
	setCount(count);
	cout << getCount() << endl;
	return count;
}

void sphere::setCount(int c)
{
	sphere::count = c;
}

int sphere::getCount()
{
	return sphere::count;
}

sphere::sphere(string filePath) {
	string test;
	ifstream myFile(filePath);
	countSpheres(filePath); //counts spheres 
	int tempCounter = 0; //break from file when currentCount reaches sphere count.
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
					
		sphere Sphere = sphere();

		//parsing position
		/*getline(myFile, test);
		char delimiter = test.find(' ');
		int x = stoi(test.substr(delimiter, delimiter - 1));
		int y = stoi(test.substr(delimiter + 2, delimiter - 1));
		int z = stoi(test.substr(delimiter + 5, delimiter - 1));	//+5 because of extra - sign 
		Sphere.setPosition(glm::vec3(x, y, z));*/
		getline(myFile, test);
		char delimiter = test.find(' ');
		test = test.substr(delimiter);
		string testx = test.substr(0, delimiter);
		int x = stoi(testx);
		string testy = test.substr(testx.size()-1, delimiter);
		int y = stoi(testy);
		string testz = test.substr(testx.size()-1 + testy.size()-2, delimiter);
		int z = stoi(testz);
		Sphere.setPosition(glm::vec3(x, y, z));

		//parsing radius
		getline(myFile, test);
		delimiter = test.find(' ');
		x = stoi(test.substr(delimiter));
		Sphere.setRadius(x);

		//parsing ambientColor	// the correct for parsing regardless if they change the values in the txt files by alot, if shit fucks up later copy this and implement for all the parsing functions
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		float xf = stof(testx);
		 testy = test.substr(testx.size(),delimiter);
		float yf = stof(testy);
		testz = test.substr(testy.size()+testx.size(), delimiter);
		float zf = stof(testz);
		Sphere.setAmbientColor(glm::vec3(xf, yf, zf));

		//parsing diffuseColor
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testy.size() + testx.size(), delimiter+1);
		zf = stof(testz);
		Sphere.setDiffuseColor(glm::vec3(xf, yf, zf));

		//parsing specular color
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter + 1);
		testx = test.substr(0, delimiter);
		xf = stof(testx);
		testy = test.substr(testx.size(), delimiter);
		yf = stof(testy);
		testz = test.substr(testy.size() + testx.size(), delimiter);
		zf = stof(testz);
		Sphere.setSpecularColor(glm::vec3(xf, yf, zf));

		//parsing shineFactor
		getline(myFile, test);
		delimiter = test.find(' ');
		x = stoi(test.substr(delimiter));
		Sphere.setShineFactor(x);

		sphereList.push_back(Sphere); //add the current sphere object into the sphere vector
		tempCounter += 1;
		if (tempCounter == getCount())
			break;
	}
	myFile.close();
}