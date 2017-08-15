#pragma once
#include "../Core/Vector2.h"

struct SDL_Surface;
struct SDL_Rect;

class Sprite
{
public:
	void GetRect(SDL_Rect& rect) const;

	Vector2 position{};
	float speed{ 3.0f };
	SDL_Surface* surface{};

private:
	int GetWidth() const;
	int GetHeight() const;
	void GetRenderPosition(int& x, int& y) const;
};