#pragma once

namespace intercept
{
	namespace helper
	{
		/*! Vehicle radar rules */
		enum vehicleRadarRule
		{
			automatic,	/**< Unit will automatic turn radar on and off */
			forced_on,	/**< Radar will be forced on */
			forced_off	/**< Radar will be forced off */
		};
	}
}