#include "game.hpp"

#include <iostream>

f32 Game::width;
f32 Game::height;
f32 Game::dwidth;
f32 Game::dheight;
f32 Game::RATIO;

void Game::init(const char* name, f32 w, f32 h){
	Game::width = w;
	Game::height = h;
	InitWindow(w, h, name);
	InitAudioDevice();
	SetTargetFPS(60);
	Game::dwidth = GetMonitorWidth(0);
	Game::dheight = GetMonitorHeight(0);
	Game::RATIO = Game::dwidth / w;

	std::cout << Game::dwidth << ", " << Game::dheight << std::endl;
}

void Game::kill(){
	CloseWindow();
	CloseAudioDevice();
}


void Game::update(){
	while(!WindowShouldClose()){
	if(Scene::current == nullptr){
		continue;
	}


	BeginDrawing();
	ClearBackground(BLACK);

	//if(!Scene::current->update) return;

	(*Scene::current->update)(Scene::current);



	EndDrawing();
	}
}






