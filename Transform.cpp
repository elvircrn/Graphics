// Transform.cpp: implementation of the Transform class.

#include <iostream>
#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3 &axis) {
  // YOUR CODE FOR HW1 HERE
  mat3 axisCross{
      {0, -axis[2], axis[1]},
      {axis[2], 0, -axis[0]},
      {-axis[1], axis[0], 0}};

  return (mat3(1) + (float) sin(glm::radians(degrees)) * axisCross)
      + (1.0f - (float) cos(glm::radians(degrees))) * (axisCross * axisCross);
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3 &eye, vec3 &up) {
  eye = rotate(degrees, vec3{0, 1, 0}) * eye;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3 &eye, vec3 &up) {
  vec3 rotationAxis = glm::normalize(glm::cross(up, eye));
  up = rotate(degrees, rotationAxis) * up;
  eye = rotate(degrees, rotationAxis) * eye;
}

// Your implementation of the glm::lookAt matrixg
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  vec3 rotationAxis = glm::normalize(glm::cross(up, eye));
  auto z = glm::normalize(eye);
  auto x = glm::normalize(glm::cross(up, eye));
  auto y = glm::normalize(glm::cross(z, x));
  return glm::transpose(mat4{{x.x, y.x, z.x, -glm::dot(eye, x)},
          {x.y, y.y, z.y, -glm::dot(eye, y)},
          {x.z, y.z, z.z, -glm::dot(eye, z)},
          {0, 0, 0, 1}});
}

Transform::Transform() {

}

Transform::~Transform() {

}
