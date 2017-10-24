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
			// Inherit constructor from Object
			using Object::Object;

			vector3 building_exit(const int index)
			{
				return sqf::building_exit(me(), index);
			}
			vector3 building_pos(const int index)
			{
				if (index < 0) // Invalid call!
				{
					throw std::invalid_argument("index cannot be negative!");
				}
				return sqf::building_pos(me(), index).front();
			}
		};
	}
}