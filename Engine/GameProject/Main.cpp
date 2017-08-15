#include "SpaceShooter.h"

int main(int argCount, char* args[])
{
	SpaceShooter game;
	
	game.Start(1920, 1080);
	game.Run();
	game.Shutdown();

	return 0;
}