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

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  vec3 rotationAxis = glm::normalize(glm::cross(up, eye));
  mat3 r = mat3(1);
      /*rotate(0, up) *
      rotate(0, eye) *
      rotate(0, rotationAxis);*/
  return glm::inverse(mat4{{r[0][0], r[0][1], r[0][2], 7},
          {r[1][0], r[1][1], r[1][2], 0},
          {r[2][0], r[2][1], r[2][2], 0},
          {0, 0, 0, 1}});
}

Transform::Transform() {

}

Transform::~Transform() {

}
