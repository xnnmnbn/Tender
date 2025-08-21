#include "scene.hpp"

Scene* Scene::current;


Scene::Scene(std::function<void(Scene*& s)>* init, std::function<void(Scene*& s)>* update){
	this->init = init;
	this->update = update;
}

void Scene::set_scene(Scene*& scene){
	Scene::current = scene;
	if(Scene::current->init){
		(*Scene::current->init)(scene);
	}
}
