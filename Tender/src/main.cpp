#include "raylib.h"
#include <iostream>
#include <glm/glm.hpp>

#include "../include/game.hpp"
#include "game/scenes.hpp"



int main(){


	Game::init("Shit", 1280, 720);
	Scene::set_scene(scene_example);
	Game::update();
	Game::kill();

	return 0;
}








