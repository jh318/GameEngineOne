#pragma once
#include "../Application/Game.h"
#include "../Application/Sprite.h"
#include <iostream>
using namespace std;

class SpaceShooter : public Game
{
protected:
	void OnStart();
	bool OnUpdate();
	void OnShutdown();

private:
	Sprite playerShip{};
	SDL_Surface* backgroundImage{};
	SDL_Surface* shipImage{};
	
	Vector2 target{};
	bool moving{ false };
	float arriveDistance{ 3.0f };
	float speed = 5.0f;
};