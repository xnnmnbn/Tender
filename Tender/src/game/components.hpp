#pragma once
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>

#define RATIO (float)GetMonitorWidth(0) / (float)GetScreenWidth()

struct c_pos{
	glm::vec2 pos;
	glm::vec2 scale;
};

struct c_vel{
	glm::vec2 v;
};

struct c_rend{
	Texture tex;
	glm::vec2 pos;
	glm::vec2 scale;
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










