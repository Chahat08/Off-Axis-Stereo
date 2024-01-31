#pragma once

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	// camera axes
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;

	// frustum data
	float near = 0.1f;
	float far = 0.1f;
	float left = -50.0f;
	float right = 50.0f;
	float top = 50.0f;
	float bottom = 50.0f;
	float fov = glm::radians(45.0f);
	float aspect = 800.0f / 600.0f;

	Camera() {};

	Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upDirection) :
		position(cameraPosition), target(cameraTarget), up(upDirection) {};

	Camera(float left, float right, float bottom, float top, float near, float far, float fovDegrees, float aspectRatio) :
		near(near), far(far), left(left), right(right), top(top), bottom(bottom), fov(glm::radians(fovDegrees)), aspect(aspectRatio) {};

	Camera(
		glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upDirection,
		float left, float right, float bottom, float top, float near, float far, float fovDegrees, float aspectRatio
	) : near(near), far(far), left(left), right(right), top(top), bottom(bottom), fov(glm::radians(fovDegrees)), aspect(aspectRatio),
		position(cameraPosition), target(cameraTarget), up(upDirection) {};

	void setUpEyePosition(float ipd, std::string& eye);
	glm::mat4 createLookAt();
	glm::mat4 createFrustum();
};