#pragma once
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>

#define RATIO (float)GetMonitorWidth(0) / (float)GetScreenWidth()
#define SCREEN_SIZE glm::vec2(GetMonitorWidth(0), GetMonitorHeight(0))

struct c_pos{
	glm::vec2 pos;
	glm::vec2 vel;
};

struct c_rend{
	Texture tex;
	glm::vec2 scale;
	glm::vec2 slide;
	glm::vec2 pos;
};

struct c_anim{
	std::vector<Texture> texs;
	u8 index;
	f32 time;
	f32 timer;
};

struct c_rect{
	glm::vec4 rect;
	u8 id;
};

struct c_memb{
	c_memb* parent;
	std::vector<c_memb*> childs;
};

struct c_cont{

};










