// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include <cstdint>
#include "../ecs/ecs.h"

using msgId_type = uint8_t;
enum msgId : msgId_type {
	_m_PACMAN_GHOST_COLLISION,
	_m_IMMUNITY_START, 
	_m_IMMUNITY_END,
	_m_NEW_GAME, 
	_m_ROUND_START, 
	_m_ROUND_OVER, 
	_m_GAME_OVER,
	_m_PACMAN_FOOD_COLLISION,

};


struct Message {
	msgId_type id;

	// if we use union we save memory, but then use only primitive
	// types, otherwise you will need to define constructors almost
	// every where.

	union {

		// _m_REGISTER_TIME
		struct {
			unsigned int new_current_time;
		} register_time_data;
		
		// _m_PACMAN_GHOST_COLLISION
		struct {
			bool pacman_wins;
		} pacman_ghost_collision_data;

		//_m_PACMAN_FOOD_COLLISION
		struct {
			unsigned int foodLeft;
		} pacman_food_collision_data;
	};
};
