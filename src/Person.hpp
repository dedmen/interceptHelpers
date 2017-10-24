#pragma once

#include <intercept.hpp>
#include "Object.hpp"
#include "Vehicle.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Person : public Object
		{
		public:
			// Inherit constructor from Object
			using Object::Object;

			void add_magazine(const r_string& name)
			{
				sqf::add_magazine(me(), name);
			}
			void add_magazine(const r_string& name, const int ammo_count)
			{
				sqf::add_magazine(me(), name, ammo_count);
			}
			void play_move(const r_string& name)
			{
				sqf::play_move(me(), name);
			}
			void play_move_now(const r_string& name)
			{
				sqf::play_move_now(me(), name);
			}
			void remove_all_weapons()
			{
				sqf::remove_all_weapons(me());
			}
			void remove_magazine(const r_string& magazine_name)
			{
				sqf::remove_magazine(me(), magazine_name);
			}
			void remove_magazines(const r_string& magazine_name)
			{
				sqf::remove_magazines(me(), magazine_name);
			}
			void remove_weapon(const r_string& weapon)
			{
				sqf::remove_weapon(me(), weapon);
			}
			float hands_hit()
			{
				return sqf::hands_hit(me());
			}
			void move_in_cargo(const Vehicle& vehicle)
			{
				sqf::move_in_cargo(me(), vehicle);
			}
			r_string primary_weapon()
			{
				return r_string(sqf::primary_weapon(me()));
			}
			Vehicle vehicle()
			{
				auto v = sqf::vehicle(me());
				return Vehicle(v);
			}
		};
	}
}