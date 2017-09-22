#pragma once

#include <intercept.hpp>
#include "Object.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Person : public Object
		{
		public:
			void add_magazine(r_string name)
			{
				sqf::add_magazine(this->_obj, name);
			}
			void add_magazine(r_string name, int ammoCount)
			{
				sqf::add_magazine(this->_obj, name, ammoCount);
			}
			void play_move(r_string name)
			{
				sqf::play_move(this->_obj, name);
			}
			void play_move_now(r_string name)
			{
				sqf::play_move_now(this->_obj, name);
			}
			void remove_all_weapons()
			{
				sqf::remove_all_weapons(this->_obj);
			}
			void remove_magazine(r_string magazineName)
			{
				sqf::remove_magazine(this->_obj, magazineName);
			}
			void remove_magazines(r_string magazineName)
			{
				sqf::remove_magazines(this->_obj, magazineName);
			}
			void remove_weapon(r_string weapon)
			{
				sqf::remove_weapon(this->_obj, weapon);
			}
			float hands_hit()
			{
				return sqf::hands_hit(this->_obj);
			}
			void move_in_cargo(object vehicle)
			{
				sqf::move_in_cargo(this->_obj, vehicle);
			}
			r_string primary_weapon()
			{
				return sqf::primary_weapon(this->_obj);
			}
			object vehicle()
			{
				return sqf::vehicle(this->_obj);
			}
		};
	}
}