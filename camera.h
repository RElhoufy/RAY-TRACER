#pragma once
#include "..\glm\glm.hpp"
#include <string>

class camera {
private:
	glm::vec3 position;	//position of camera, holds x y z
	int fov;	//field of view, theta
	int focalLength;	//focal length
	float aspectRatio;	//aspect ratio

public:
	camera();
	camera(std::string filePath);
	
	glm::vec3 getPosition();
	int getFov();
	int getFocalLength();
	float getAspectRatio();

	void setPosition(glm::vec3);
	void setFov(int);
	void setFocalLength(int);
	void setAspectRatio(float);


};
