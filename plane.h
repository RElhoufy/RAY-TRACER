#pragma once
#include "..\glm\glm.hpp"
#include <string>

class plane {

private:
	glm::vec3 normal;
	glm::vec3 position;
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	int shineFactor;

public:
	plane();
	plane(std::string filePath);

	glm::vec3 getNormal();
	glm::vec3 getPosition();
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
	int getShineFactor();

	void setNormal(glm::vec3);
	void setPosition(glm::vec3);
	void setAmbientColor(glm::vec3);
	void setDiffuseColor(glm::vec3);
	void setSpecularColor(glm::vec3);
	void setShineFactor(int);
};