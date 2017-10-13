#pragma once

namespace intercept
{
	namespace helper
	{
		/*! Vehicle radar rules */
		enum vehicleRadarRule
		{
			automatic = 0,	/**< Unit will automatic turn radar on and off */
			forced_on = 1,	/**< Radar will be forced on */
			forced_off = 2	/**< Radar will be forced off */
		};
	}
}