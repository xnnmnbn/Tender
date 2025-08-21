#pragma once
#include "raylib.h"
#include <entt/entt.hpp>
#include <functional>
#include "assetmanager.hpp"
#include "numtypes.hpp"
#include "camera.hpp"

class Scene{
public:
	entt::registry reg;
	AssetManager manager;

	std::function<void(Scene*& s)>* init;
	std::function<void(Scene*& s)>* update;

	CameraOrtho cam;

	Scene(std::function<void(Scene*& s)>* init, std::function<void(Scene*& s)>* update);

	static Scene* current;
	static void set_scene(Scene*& scene);
};
