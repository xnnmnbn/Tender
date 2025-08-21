#include "assetmanager.hpp"

void AssetManager::add_texture(const std::string& name, const std::string& path){
	this->textures[name] = LoadTexture(path.c_str());
}
void AssetManager::add_sound(const std::string& name, const std::string& path){
	this->sounds[name] = LoadSound(path.c_str());
}
void AssetManager::add_music(const std::string& name, const std::string& path){
	this->musics[name] = LoadMusicStream(path.c_str());
}






