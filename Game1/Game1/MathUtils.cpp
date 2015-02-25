#include "MathUtils.h"

float MathUtils::ToDegrees(float radians)
{
  float radiansToDegrees = 180.0f / 3.1415926535f;
  return radians * radiansToDegrees;
}

float MathUtils::ToRadians(float degrees)
{
  float degreesToRadians = 3.1415926535f / 180.0f;
  return degrees * degreesToRadians;
}


Direction MathUtils::GetDirection(float angle)
{
	Direction direction;
	if (angle == 0 || angle == 360)
	{
		direction = NORTH;
	}
	else if (angle > 0 && angle < 90)
	{
		direction = N_EAST;
	}
	else if (angle == 90)
	{
		direction = EAST;
	}
	else if (angle > 90 && angle < 180)
	{
		direction = S_EAST;
	}
	else if (angle == 180)
	{
		direction = SOUTH;
	}
	else if (angle > 180 && angle < 270)
	{
		direction = S_WEST;
	}
	else if (angle == 270)
	{
		direction = WEST;
	}
	else if (angle > 270 && angle < 360)
	{
		direction = N_WEST;
	}

	return direction;
}