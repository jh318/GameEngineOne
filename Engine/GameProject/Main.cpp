#include "SpaceShooter.h"
#include "RenderDemo.h"

int main(int argCount, char* args[])
{
	//SpaceShooter game;

	//game.Start(1920, 1080);
	//game.Run();
	//game.Shutdown();

	RenderDemo demo;
	demo.Start(1920, 1080);
	demo.Run();
	demo.Shutdown();

	return 0;
}