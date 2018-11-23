#pragma once
#include "..\glm\glm.hpp"
#include <string>
#include <vector>

class light {

private:
	glm::vec3 position;
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	std::vector<light> lightList;

public:
	light();
	light(std::string filePath);

	void setPosition(glm::vec3);
	void setAmbientColor(glm::vec3);
	void setDiffuseColor(glm::vec3);
	void setSpecularColor(glm::vec3);
	
	glm::vec3 getPosition();
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();



};

