#pragma once

#include <intercept.hpp>
#include "Object.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Group // : public Object
		{
		private:
			group _grp;
		public:
			Group(group grp) { this->_grp = grp; }
		};
	}
}