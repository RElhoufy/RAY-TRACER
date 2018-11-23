#include "camera.h"
#include <iostream>
#include <fstream>

using namespace std;
camera::camera()
{
	position = glm::vec3(0, 0, 0);
	fov = 0;
	focalLength = 0;
	aspectRatio = 0;
}

camera::camera(string filePath)
{
	string test;
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
		while (test.compare("camera")!=0 )	//if input file reader didnt reach camera keep reading
		{
			getline(myFile, test);	
		}	//at this point my reader should be at the line that describes the attributes of the camera
		
		//parsing position
		getline(myFile, test);
		int x = test.at(5) - '0';	//converts from char to int. x value for vec3 position
		int y = test.at(7) - '0';	//	y value for vec3 position
		int z = test.at(9) - '0';	//	z value for vec3 position
		
		setPosition(glm::vec3(x, y, z));

		//parsing field of view
		getline(myFile, test);
		char delimiter = test.find(' ');  
		test = test.substr(delimiter);	//cuts string from ' ' till the end of the string
		setFov(stoi(test));

		//parsing focal length
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter);
		setFocalLength(stoi(test));

		//parsing aspect ratio
		getline(myFile, test);
		delimiter = test.find(' ');
		test = test.substr(delimiter);
		setAspectRatio(stof(test));
	
		break; // now that we have all that we need get out of the while loop
	}

	myFile.close();
}

glm::vec3 camera::getPosition()
{
	return position;
}

int camera::getFov()
{
	return fov;
}

int camera::getFocalLength()
{
	return focalLength;
}

float camera::getAspectRatio()
{
	return aspectRatio;
}

void camera::setPosition(glm::vec3 position)
{
	camera::position = position ;
}

void camera::setFov(int f)
{
	camera::fov = f;
}

void camera::setFocalLength(int f)
{
	camera::focalLength = f;
}

void camera::setAspectRatio(float a)
{
	camera::aspectRatio = a;
}
