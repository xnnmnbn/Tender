#include "scenes.hpp"
#include <iostream>

#include <thread>
#include <chrono>
#include <atomic>

std::function<void(Scene*& s)> scene_example_init = [](Scene*& s){
	entt::registry& r = s->reg;
	auto& manager = s->manager;
	manager.add_texture("z_d1", "assets/img/zombie_down_1.png");
	manager.add_texture("z_d2", "assets/img/zombie_down_2.png");
	manager.add_texture("water", "assets/img/sewer_water.png");

	auto water = r.create();
	r.emplace<c_pos>(water, glm::vec2(0, -3.5));
	r.emplace<c_rend>(water, manager.textures["water"], glm::vec2(24, 2), glm::vec2(-2, 0));

	auto entity= r.create();
	r.emplace<c_pos>(entity, glm::vec2(0.0, 0.0));
	r.emplace<c_rend>(entity, manager.textures["z_d1"], glm::vec2(1, 1), glm::vec2(0, 0));
	r.emplace<c_anim>(entity);
	r.emplace<c_rect>(entity, glm::vec4(1, 1, 1, 1), 1);
	auto& anim = r.get<c_anim>(entity);
	anim.texs.push_back(manager.textures["z_d1"]);
	anim.texs.push_back(manager.textures["z_d2"]);
	anim.index = 0;
	anim.time = 0.3F;
	anim.timer = 0;

};

std::function<void(Scene*&)> scene_example_update = [](Scene*& s){
	entt::registry& reg = s->reg;

	auto rend_view = reg.view<c_pos, c_rend>();
	auto move_view = reg.view<c_pos>();
	auto anim_view = reg.view<c_anim, c_rend>();
	auto rect_view = reg.view<c_pos, c_rect>();

	for(auto& e : rect_view){
		c_rect& r = rect_view.get<c_rect>(e);
		c_pos& p = rect_view.get<c_pos>(e);

		r.rect.x = p.pos.x;
		r.rect.y = p.pos.y;
	}

	for(auto& e : move_view){
		c_pos& p = move_view.get<c_pos>(e);
		p.pos += p.vel * GetFrameTime();
	}

	for(auto& e : anim_view){
		c_rend& r = anim_view.get<c_rend>(e);
		c_anim& a = anim_view.get<c_anim>(e);

		a.timer += GetFrameTime();

		if(a.timer >= a.time){
			a.index += 1;
			if(a.index >= a.texs.size()){
				a.index = 0;
			}
			r.tex = a.texs[a.index];
			a.timer = 0;
		}
	}

	for(auto& e : rend_view){
		c_rend& r = rend_view.get<c_rend>(e);
		c_pos& p = rend_view.get<c_pos>(e);


		Rectangle src = (Rectangle){
			-(r.pos.x += r.slide.x * GetFrameTime()),
			r.pos.y += r.slide.y * GetFrameTime(),
			r.tex.width,
			r.tex.height
		};

		Rectangle dst = (Rectangle){
			(p.pos.x - s->cam.pos.x - r.scale.x / 2.0f) * METER + GetScreenWidth() / 2.0f,
			-(p.pos.y - s->cam.pos.y + r.scale.y / 2.0f) * METER + GetScreenHeight() / 2.0f,
			r.scale.x * METER,
			r.scale.y * METER
		};


		DrawTexturePro(r.tex, src, dst, {0, 0}, 0, WHITE);
	}
};

Scene* scene_example = new Scene(&scene_example_init, &scene_example_update);







