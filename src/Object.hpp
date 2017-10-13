#pragma once

#include <intercept.hpp>
#include "Container.hpp"

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Object
		{
		protected:
			object _obj;
		public:
			Object(object obj) { this->_obj = obj; }

			// Cast operator to 'object'. Needs testing.
			operator object() const { return _obj; }

			void set_pos(vector3 vec)
			{
				sqf::set_pos(this->_obj, vec);
			}
			void set_pos_asl(vector3 vec)
			{
				sqf::set_pos_asl(this->_obj, vec);
			}
			void set_pos_asl2(vector3 vec)
			{
				sqf::set_pos_asl2(this->_obj, vec);
			}
			void set_pos_aslw(vector3 vec)
			{
				sqf::set_pos_aslw(this->_obj, vec);
			}
			void set_pos_atl(vector3 vec)
			{
				sqf::set_pos_atl(this->_obj, vec);
			}
			void set_pos_world(vector3 vec)
			{
				sqf::set_pos_world(this->_obj, vec);
			}

			vector3 get_pos()
			{
				return sqf::get_pos(this->_obj);
			}
			vector3 get_pos_asl()
			{
				return sqf::get_pos_asl(this->_obj);
			}
			vector3 get_pos_asl_visual()
			{
				return sqf::get_pos_asl_visual(this->_obj);
			}
			vector3 get_pos_aslw()
			{
				return sqf::get_pos_aslw(this->_obj);
			}
			vector3 get_pos_atl()
			{
				return sqf::get_pos_atl(this->_obj);
			}
			vector3 get_pos_atl_visual()
			{
				return sqf::get_pos_atl_visual(this->_obj);
			}
			vector3 get_pos_visual()
			{
				return sqf::get_pos_visual(this->_obj);
			}
			vector3 get_pos_world()
			{
				return sqf::get_pos_world(this->_obj);
			}

			bool is_alive()
			{
				return sqf::alive(this->_obj);
			}
			void detach()
			{
				sqf::detach(this->_obj);
			}
			std::vector<float> action_ids()
			{
				// TODO Add sqf
			}
			void attach_to(Object obj, vector3 offset, r_string memPoint)
			{
				sqf::attach_to(this->_obj, obj, offset, memPoint);
			}
			vector3 velocity()
			{
				return sqf::velocity(this->_obj);
			}
			r_string name()
			{
				return sqf::name(this->_obj);
			}
			r_string type_of()
			{
				return sqf::type_of(this->_obj);
			}
			void inflame(bool burn)
			{
				sqf::inflame(this->_obj, burn);
			}
			bool inflamed()
			{
				return sqf::inflamed(this->_obj);
			}
			void remove_action(float index)
			{
				// TODO add sqf
			}
			void reveal(Object target)
			{
				// TODO add sqf
			}
			object object_parent()
			{
				return sqf::object_parent(this->_obj);
			}
			std::vector<Container> every_container() // Should propably use pointers here
			{
				auto sqfResult = sqf::every_container(this->_obj);
				auto result = std::vector<Container>();
				std::transform(sqfResult.begin(), sqfResult.end(), std::back_inserter(result), [](sqf::rv_container c) -> Container { return Container(c.container, c.type); });
				return result;
			}
			std::vector<Container> every_backpack()
			{
				auto sqfResult = sqf::every_backpack(this->_obj);
				auto result = std::vector<Container>();
				std::transform(sqfResult.begin(), sqfResult.end(), std::back_inserter(result), [](object c) -> Container { return Container(c); });
				return result;
			}
			float damage()
			{
				return sqf::damage(this->_obj);
			}
			void set_damage(float damage)
			{
				sqf::set_damage(this->_obj, damage);
			}
			float get_hit(r_string selection)
			{
				return sqf::get_hit(this->_obj, selection);
			}
			float get_hitpoint_damage(r_string selection)
			{
				return sqf::get_hit_point_damage(this->_obj, selection);
			}
			void set_hit(r_string part, float damage, bool useEffects)
			{
				sqf::set_hit(this->_obj, part, damage);
			}
			void set_hitpoint_damage(r_string selection, float damage, bool usEffects)
			{
				sqf::set_hit_point_damage(this->_obj, selection, damage);
			}
			void allow_damage(bool allow)
			{
				sqf::allow_damage(this->_obj, allow);
			}
			bool is_damage_allowed()
			{
				return sqf::is_damage_allowed(this->_obj);
			}
			bool local()
			{
				return sqf::local(this->_obj);
			}
		};
	}
}