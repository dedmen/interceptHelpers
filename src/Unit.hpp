#pragma once

#include <intercept.hpp>
#include "Object.hpp"
#include "Group.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Unit : public Object
		{
		public:
			// Inherit constructor from Object
			using Object::Object;

			Group get_group()
			{
				auto g = sqf::get_group(me());
				return Group(g);
			}
			float get_skill()
			{
				return sqf::skill(me());
			}
			float get_skill(const r_string& skill_type)
			{
				return sqf::skill(me(), skill_type);
			}
			void set_skill(const float skill)
			{
				sqf::set_skill(me(), skill);
			}
			float skill_final(const r_string& sub_skill)
			{
				return sqf::skill_final(me(), sub_skill);
			}
			float knows_about(const object& target)
			{
				return sqf::knows_about(me(), target);
			}
			void move(const vector3 pos)
			{
				sqf::move(me(), pos);
			}
		};
	}
}