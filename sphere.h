#pragma once
#include "..\glm\glm.hpp"
#include <string>
#include <vector>

class sphere 
{
private:
	glm::vec3 position;
	int radius;
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	int shineFactor;
	std::vector<sphere> sphereList; //since there can be more than 1 spehere in a scene
	int count; // keeps track of how many spheres.
	

public:
	
	sphere();
	sphere(std::string filePath);

	void setPosition(glm::vec3);
	void setRadius(int);
	void setAmbientColor(glm::vec3);
	void setDiffuseColor(glm::vec3);
	void setSpecularColor(glm::vec3);
	void setShineFactor(int);

	glm::vec3 getPosition();
	int getRadius();
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
	int getShineFactor();
	std::vector<sphere> getSphereList();
	
	int countSpheres(std::string filePath);
	void setCount(int);
	int getCount();
};