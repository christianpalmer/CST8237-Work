/**
 * \class Projectile.h
 * \brief An class that represents a projectile
 * to be shoot by a player in the world.
 * \author Christian Andrade
 * \date February 22, 2015
 */

#pragma once

#include "GameObject.h"
#include "GameConstants.h"
#include <SDL_image.h>


class Projectile : public GameObject
{
	private:
	int _bounces;
	Vector2 _pos;
	float _speed, _angle;
	SDL_Texture* _texture;
	SDL_Rect* _rect;

public:
	Projectile();
	~Projectile();

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
	 * \fn void Move(float dt)
	 * \brief A  function that we値l use as to define how our 
	 * object will move based on user input
	 * \param dt the time in fractions of a second since the last pass.
	 */
	void Move(float dt);

	/**
	 * \fn void SetPosition(float posX, float posY, float angle)
	 * \brief A function used to set the coordenates of the projectile
	 * \param angle the angle of the object
	 * \param posX the position X of the projectile
	 * \param posY the position Y of the projectile
	 */
	void SetPosition(float posX, float posY, float angle);
	
	/**
	 * \fn SDL_Rect& GetPosition()
	 * \brief A function that return a SDL_Rect with the position of the projectile
	 */
	SDL_Rect& GetPosition();

	/**
	 * \fn void ResetSpeed()
	 * \brief A function used to reset the speed of the projectile
	 */
	void ResetSpeed();
	
	/**
	 * \fn void GetBounces()
	 * \brief A function that return the number of times that the projectile
	 * bounced
	 */
	int GetBounces();

	/**
	 * \fn void ResetBounces()
	 * \brief A function that reset the number of bounces of the projectile
	 */
	void ResetBounces();

	/**
	 * \fn void Bounce()
	 * \brief A function used to bounce the projectile
	 * \ changing it direction
	 */
	void Bounce();

};