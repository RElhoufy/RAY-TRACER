#pragma once
#include "..\glm\glm.hpp"
#include <string>
#include <vector>

class triangle {
private:
	std::vector<glm::vec3> vertexList;
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	float shineFactor;

public:
	triangle();
	triangle(std::string filePath);

	void setVertexList(std::vector<glm::vec3>);
	void setAmbientColor(glm::vec3);
	void setDiffuseColor(glm::vec3);
	void setSpecularColor(glm::vec3);
	void setShineFactor(float);
	void printVertexList();

	std::vector<glm::vec3> getVertexList();
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
	float getShineFactor();

};
