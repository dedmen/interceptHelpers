#pragma once

#include <intercept.hpp>
#include "Object.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Building : public Object
		{
		public:
			vector3 building_exit(int index)
			{
				return sqf::building_exit(this->_obj, index);
			}
			vector3 building_pos(int index)
			{
				if (index < 0) // Invalid call!
				{
					throw std::invalid_argument("index cannot be negative!");
				}
				return sqf::building_pos(this->_obj, index).front();
			}
		};
	}
}