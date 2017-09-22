#pragma once

#include <intercept.hpp>
#include "Object.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Unit : public Object
		{
		public:
			group get_group()
			{
				return sqf::get_group(this->_obj);
			}
			float get_skill()
			{
				return sqf::skill(this->_obj);
			}
			float get_skill(r_string skillType)
			{
				return sqf::skill(this->_obj, skillType);
			}
			void set_skill(float skill)
			{
				sqf::set_skill(this->_obj, skill);
			}
			float skill_final(r_string subSkill)
			{
				return sqf::skill_final(this->_obj, subSkill);
			}
			float knows_about(object target)
			{
				return sqf::knows_about(this->_obj, target);
			}
			void move(vector3 pos)
			{
				sqf::move(this->_obj, pos);
			}
		};
	}
}