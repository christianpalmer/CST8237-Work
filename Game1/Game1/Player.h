/**
 * \class Player.h
 * \brief An class that represents a player
 * to be placed and manipulated in the world.
 * \author Christian Andrade
 * \date February 13, 2015
 */

#pragma once

#include "GameObject.h"
#include "GameConstants.h"
#include <SDL_image.h>
#include "MathUtils.h"
#include "Projectile.h"





class Player : public GameObject
{
	private:
	Vector2 _pos;
	float _speed, _angle,_lastDT, _deathTime;
	ShotState _shotState;
	LifeState _lifeState;
	int _score;
	Projectile _projectile;
	SDL_Texture* _texture;
	SDL_Rect* _rect;

public:
	Player();
	Player(int posX, int posY);
	~Player();

	/**
	 * \fn void Initialize()
	 * \brief A virtual function that we値l use as to define how our 
	 * object is initialized.
	 */
	void Initialize();

	/**
	 * \fn void Update(float dt)
	 * \brief A virtual function that we値l use as to define how our 
	 * object is updated
	 * \param dt The time in fractions of a second since the last pass.
	 */

	void Update(float dt);
	
	/**
	 * \fn void Draw(SDL_Renderer *renderer, float dt)
	 * \brief A virtual function that we値l use as to define how our 
	 * object is drawn to the screen.
	 * \param renderer The SDL renderer used to draw the object.
	 * \param dt The time in fractions of a second since the last pass.
	 */

	void Draw(SDL_Renderer *renderer, float dt);
	
	/**
	 * \fn void Rotate(Rotation rotation)
	 * \brief A  function that we値l use as to define how our 
	 * object will rotate based on user input
	 * \param rotation direction
	 */
	void Rotate(Rotation rotation);
	
	/**
	 * \fn void Move(float dt)
	 * \brief A  function that we値l use as to define how our 
	 * object will move based on user input
	 * \param dt the time in fractions of a second since the last pass.
	 */
	void Move(float dt);
	
	/**
	 * \fn void UndoMove()
	 * \brief A  function that we値l use as to define how our 
	 * object will undo the move
	 */
	void UndoMove();
	
	/**
	 * \fn void Shoot()
	 * \brief A function that we値l use as to define how our 
	 * object will shoot
	 */
	void Shoot();

	/**
	 * \fn SDL_Rect& GetPosition()
	 * \brief A function used to return the current SDL_Rect position
	 * of the object
	 */
	SDL_Rect& GetPosition();

	/**
	 * \fn void SetAngle(float angle)
	 * \brief A function used to set the angle of the object
	 * \param angle the angle of the object
	 */
	void SetAngle(float angle);

	/**
	 * \fn bool CheckCollision(SDL_Rect* rect)
	 * \brief A function to check the collision
	 * of the object based on other object
	 * \param rect the SDL_Rect position of the
	 object to be checked
	 */
	bool CheckCollision(SDL_Rect* rect);
	
	/**
	 * \fn bool CheckShootCollision(SDL_Rect* rect)
	 * \brief A function to check the collision
	 * of the projectile of the object based 
	 * on other object
	 * \param rect the SDL_Rect position of the
	 object to be checked
	 */
	bool CheckShootCollision(SDL_Rect* rect);

	/**
	 * \fn void SetLifeState(LifeState lifeState)
	 * \brief A function to set the lifestate
	 * of the object
	 * \param lifeState the lifeState of the object
	 * Alive or Dead
	 */
	void SetLifeState(LifeState lifeState);

	/**
	 * \fn bool IsAlive()
	 * \brief A function to check if the user is alive
	 */
	bool IsAlive();

	/**
	 * \fn void Score()
	 * \brief A function to increment the score of the player
	 */
	void Score();

		/**
	 * \fn int GetScore()
	 * \brief A function that return the score of the player
	 */
	int GetScore();


};