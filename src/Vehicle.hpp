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
			void set_vehicle_position() // TODO Add decleration and sqf
			{
				
			}
			std::pair<bool,bool> can_vehicle_cargo(object target)
			{
				return sqf::can_vehicle_cargo(this->_obj, target);
			}
			void set_vehicle_radar(vehicleRadarRule rule)
			{
				sqf::set_vehicle_radar(this->_obj, rule);
			}
			object rope_create()
			{
				sqf::rope_create()
			}
		};
	}
}