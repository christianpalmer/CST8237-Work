#include "Block.h"
#include "MathUtils.h"
#include <SDL.h>

struct SDL_Renderer;

Block::Block()
{
}
Block::Block(int posX, int posY)
{

	_pos.x = posX;
	_pos.y = posY;
}

Block::~Block()
{
	if (_texture != NULL)
	{
		delete _texture;

	}

	if (_rect != NULL)
	{
		delete _rect;

	}
}

void Block::Initialize()
{
	IMG_Init(IMG_INIT_PNG);
	_texture = NULL;

	_rect = new SDL_Rect();
	_rect->h = _height;
	_rect->w = _width;
	_rect->x = _pos.x;
	_rect->y = _pos.y;

}


void Block::SetPosition(float posX, float posY)
{
	_pos.x = posX;
	_pos.y = posY;
}

void Block::SetSize(int height, int width)
{
	_height = height;
	_width = width;
}


void Block::Update(float dt)
{

}

SDL_Rect& Block:: GetPosition()
{

	return *_rect;
}

void Block::Draw(SDL_Renderer *renderer, float dt)
{

	if (_texture == NULL)
	{
		_texture = IMG_LoadTexture(renderer,"block.png");
	}


	SDL_RenderCopyEx(renderer,_texture,nullptr, _rect,0 ,nullptr,SDL_FLIP_NONE);

}