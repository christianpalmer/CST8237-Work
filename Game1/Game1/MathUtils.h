/**
 * \ MathUtils.h
 * \brief Used as a helper to math calculations and position
 * \author Christian Andrade
 * \date February 13, 2015
 */

#pragma once
#include "GameConstants.h"
// A structure to hold two floats. Similar to SDL_Point (though it contains ints).



enum Acceleration {FW, BW, STOP};
struct Vector2
{
  float x;
  float y;
};

struct Vector3
{
  float x;
  float y;
  float z;
};

struct Vector4
{
  float x;
  float y;
  float z;
  float w;
};

struct Transform
{
  Vector3 position;
  Vector3 rotation;
  Vector3 scale;
};

class MathUtils
{
public:
  static float ToRadians(float degrees);
  static float ToDegrees(float radians);
  static Direction GetDirection(float angle);
};