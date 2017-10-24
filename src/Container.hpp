#pragma once

#include <intercept.hpp>
#include "Object.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Container
		{
		private:
			std::string _type;
			object _obj;
		public:
			Container (const object& obj)
			{
				this->_type = "";
				this->_obj = obj;
			}
			explicit Container(const object& obj, const std::string& type)
			{
				this->_type = type;
				this->_obj = obj;
			}
		};
	}
}