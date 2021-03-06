#pragma once

#include <intercept.hpp>
#include "Object.hpp"
#include "vehicleRadarRule.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Vehicle : public Object
		{
		public:
			// Inherit constructor from Object
			using Object::Object;

			void set_vehicle_position() // TODO Add decleration and sqf
			{
				
			}
			std::pair<bool,bool> can_vehicle_cargo(const object& target)
			{
				return sqf::can_vehicle_cargo(me(), target);
			}
			void set_vehicle_radar(const vehicleRadarRule rule)
			{
				sqf::set_vehicle_radar(me(), rule);
			}
			object rope_create() // TODO Add decleration and sqf
			{
				
			}
		};
	}
}