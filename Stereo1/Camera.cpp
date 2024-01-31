#include "Camera.h"

glm::mat4 Camera::createFrustum() {
	return glm::frustum(
		this->left, 
		this->right, 
		this->bottom, 
		this->top, 
		this->near, 
		this->far
	);
}

glm::mat4 Camera::createLookAt() {
	return glm::lookAt(
		this->position, 
		this->target, 
		this->up
	);
}

void Camera::setUpEyePosition(float ipd, std::string& eye) {
	float fovby2 = fov / 2.0f;
	if (!eye.compare("left")) { // left eye setup
		left = -(near * aspect * tan(fovby2) - ipd / 2.0f);
		right = (near * aspect * tan(fovby2) + ipd / 2.0f);
	}
	else if (!eye.compare("right")) { // right eye set up
		left = -(near * aspect * tan(fovby2) + ipd / 2.0f);
		right = (near * aspect * tan(fovby2) - ipd / 2.0f);
	}
	top = near * tan(fovby2);
	bottom = -top;
}
