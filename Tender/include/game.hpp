#pragma once

#include "raylib.h"
#include "numtypes.hpp"
#include "scene.hpp"


class Game{
public:
	static f32 width;
	static f32 height;
	static f32 dwidth;
	static f32 dheight;
	static f32 RATIO;
	static void init(const char* name, f32 w, f32 h);
	static void kill();
	static void update();
};





