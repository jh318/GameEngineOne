#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>

void Sprite::GetRect(SDL_Rect& rect) const
{
	GetRenderPosition(rect.x, rect.y);
	rect.w = GetWidth();
	rect.h = GetHeight();
}

int Sprite::GetWidth() const
{
	assert(surface);

	return surface->w;
}

int Sprite::GetHeight() const
{
	assert(surface);

	return surface->h;
}

void Sprite::GetRenderPosition(int& x, int& y) const
{
	assert(surface);

	x = (int)position.x - (surface->w / 2);
	y = (int)position.y - (surface->h / 2);
}

