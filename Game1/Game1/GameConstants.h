/**
 * \ GameConstants.h
 * \brief Used to store all game constants
 * \author Christian Andrade
 * \date February 13, 2015
 */

#pragma once


enum Rotation{RIGHT, LEFT};
enum Direction{NORTH, N_EAST, EAST, S_EAST, SOUTH, S_WEST,WEST, N_WEST};
enum ShotState{Shooting, Idle};
enum LifeState{Alive, Dead};
#define SCREEN_SIZE 640

#define MAX_BLOCKS 3
#define MAX_BOUNCES 3
#define BLOCK_SIZE 100
#define WALL_WIDTH SCREEN_SIZE
#define WALL_HEIGHT 10
#define TANK_SIZE 40
#define TANK_WIDTH 25
#define PROJECTILE_H 20
#define PROJECTILE_W 5
#define MAX_DEATH_TIME 2
#define MAX_WALLS 4

