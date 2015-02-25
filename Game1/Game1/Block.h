/**
 * \class Block.h
 * \brief An class that represents a block
 * to be placed in the world.
 * \author Christian Andrade
 * \date February 18, 2015
 */


#pragma once

#include "GameObject.h"
#include "MathUtils.h"
#include <SDL_image.h>

class Block : public GameObject
{
private:
	Vector2 _pos;
	int _height, _width;
	SDL_Rect* _rect;

	SDL_Texture* _texture;

public:
	Block::Block();
	Block(int posX, int posY);
	~Block();

	/**
	 * \fn void Initialize()
	 * \brief A virtual function that we’ll use as to define how our 
	 * object is initialized.
	 */
	void Initialize();

		
	/**
	 * \fn SDL_Rect& GetPosition()
	 * \brief A function used to return the current SDL_Rect position
	 * of the object
	 */
	SDL_Rect& GetPosition();

	/**
	 * \fn void Update(float dt)
	 * \brief A virtual function that we’ll use as to define how our 
	 * object is updated
	 * \param dt The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn void Draw(SDL_Renderer *renderer, float dt)
	 * \brief A virtual function that we’ll use as to define how our 
	 * object is drawn to the screen.
	 * \param renderer The SDL renderer used to draw the object.
	 * \param dt The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

		/**
	 * \fn void SetPosition(float posX, float posY)
	 * \brief A function used to set the position of the block
	 * \param posX the X position of the block
	 * \param posY the Y position of the block
	 */
	void SetPosition(float posX, float posY);

	/**
	 * \fn void SetSize(int height, int width)
	 * \brief A function used to set the size of the block
	 * \param height the height position of the block
	 * \param width the width position of the block
	 */
	void SetSize(int height, int width);

	/**
	 * \fn bool CheckCollision(SDL_Rect* rect)
	 * \brief A function to check the collision
	 * of the object based on other object
	 * \param rect the SDL_Rect position of the
	 object to be checked
	 */
	bool CheckCollision(SDL_Rect* rect);
};