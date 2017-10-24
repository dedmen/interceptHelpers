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

			object& me() { return _obj; }
		public:
			Object(object& obj) { me() = obj; }

			// Cast operator to 'object'. Needs testing.
			operator const object&() const { return  _obj; }

			void set_pos(const vector3 vec)
			{
				sqf::set_pos(me(), vec);
			}
			void set_pos_asl(const vector3 vec)
			{
				sqf::set_pos_asl(me(), vec);
			}
			void set_pos_asl2(const vector3 vec)
			{
				sqf::set_pos_asl2(me(), vec);
			}
			void set_pos_aslw(const vector3 vec)
			{
				sqf::set_pos_aslw(me(), vec);
			}
			void set_pos_atl(const vector3 vec)
			{
				sqf::set_pos_atl(me(), vec);
			}
			void set_pos_world(const vector3 vec)
			{
				sqf::set_pos_world(me(), vec);
			}

			vector3 get_pos()
			{
				return sqf::get_pos(me());
			}
			vector3 get_pos_asl()
			{
				return sqf::get_pos_asl(me());
			}
			vector3 get_pos_asl_visual()
			{
				return sqf::get_pos_asl_visual(me());
			}
			vector3 get_pos_aslw()
			{
				return sqf::get_pos_aslw(me());
			}
			vector3 get_pos_atl()
			{
				return sqf::get_pos_atl(me());
			}
			vector3 get_pos_atl_visual()
			{
				return sqf::get_pos_atl_visual(me());
			}
			vector3 get_pos_visual()
			{
				return sqf::get_pos_visual(me());
			}
			vector3 get_pos_world()
			{
				return sqf::get_pos_world(me());
			}

			bool is_alive()
			{
				return sqf::alive(me());
			}
			void detach()
			{
				sqf::detach(me());
			}
			std::vector<float> action_ids()
			{
				// TODO Add sqf
			}
			void attach_to(const Object& obj, const vector3 offset, const r_string& memPoint)
			{
				sqf::attach_to(me(), obj, offset, memPoint);
			}
			vector3 velocity()
			{
				return sqf::velocity(me());
			}
			r_string name()
			{
				return r_string(sqf::name(me()));
			}
			r_string type_of()
			{
				return r_string(sqf::type_of(me()));
			}
			void inflame(const bool burn)
			{
				sqf::inflame(me(), burn);
			}
			bool inflamed()
			{
				return sqf::inflamed(me());
			}
			void remove_action(float index)
			{
				// TODO add sqf
			}
			void reveal(Object& target)
			{
				auto variant = std::variant<object, group>(me());
				sqf::reveal(variant, target);
			}
			object object_parent()
			{
				return sqf::object_parent(me());
			}
			std::vector<Container> every_container() // Should propably use pointers here
			{
				auto sqfResult = sqf::every_container(me());
				auto result = std::vector<Container>();
				std::transform(sqfResult.begin(), sqfResult.end(), std::back_inserter(result), [](sqf::rv_container c) -> Container { return Container(c.container, c.type); });
				return result;
			}
			std::vector<Container> every_backpack()
			{
				auto sqfResult = sqf::every_backpack(me());
				auto result = std::vector<Container>();
				std::transform(sqfResult.begin(), sqfResult.end(), std::back_inserter(result), [](object c) -> Container { return Container(c); });
				return result;
			}
			float damage()
			{
				return sqf::damage(me());
			}
			void set_damage(const float damage)
			{
				sqf::set_damage(me(), damage);
			}
			float get_hit(const r_string& selection)
			{
				return sqf::get_hit(me(), selection);
			}
			float get_hitpoint_damage(const r_string& selection)
			{
				return sqf::get_hit_point_damage(me(), selection);
			}
			void set_hit(const r_string& part, const float damage, const bool useEffects)
			{
				sqf::set_hit(me(), part, damage);
			}
			void set_hitpoint_damage(const r_string& selection, const float damage, const bool usEffects)
			{
				sqf::set_hit_point_damage(me(), selection, damage);
			}
			void allow_damage(const bool allow)
			{
				sqf::allow_damage(me(), allow);
			}
			bool is_damage_allowed()
			{
				return sqf::is_damage_allowed(me());
			}
			bool local()
			{
				return sqf::local(me());
			}
		};
	}
}