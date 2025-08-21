#pragma once
#include "raylib.h"
#include <string>
#include <unordered_map>

class AssetManager{
public:
	std::unordered_map<std::string, Texture2D> textures;
	std::unordered_map<std::string, Sound> sounds;
	std::unordered_map<std::string, Music> musics;

	void add_texture(const std::string& name, const std::string& path);
	void add_sound(const std::string& name, const std::string& path);
	void add_music(const std::string& name, const std::string& path);
};
