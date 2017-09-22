#pragma once

#include <intercept.hpp>

using namespace intercept::types;

namespace intercept
{
	namespace helper
	{
		class Object
		{
		private:
			object _obj;
		public:
			void setPos(vector3 vec)
			{
				sqf::set_pos(_obj, vec);
			}
			void setPosAsl(vector3 vec)
			{
				sqf::set_pos_asl(_obj, vec);
			}
			void setPosAsl2(vector3 vec)
			{
				sqf::set_pos_asl2(_obj, vec);
			}
			void setPosAslw(vector3 vec)
			{
				sqf::set_pos_aslw(_obj, vec);
			}
			void setPosAtl(vector3 vec)
			{
				sqf::set_pos_atl(_obj, vec);
			}
			void setPosWorld(vector3 vec)
			{
				sqf::set_pos_world(_obj, vec);
			}

			vector3 getPos()
			{
				return sqf::get_pos(_obj);
			}
			vector3 getPosAsl()
			{
				return sqf::get_pos_asl(_obj);
			}
			vector3 getPosAslVisual()
			{
				return sqf::get_pos_asl_visual(_obj);
			}
			vector3 getPosAslw()
			{
				return sqf::get_pos_aslw(_obj);
			}
			vector3 getPosAtl()
			{
				return sqf::get_pos_atl(_obj);
			}
			vector3 getPosAtlVisual()
			{
				return sqf::get_pos_atl_visual(_obj);
			}
			vector3 getPosVisual()
			{
				return sqf::get_pos_visual(_obj);
			}
			vector3 getPosWorld()
			{
				return sqf::get_pos_world(_obj);
			}

			bool isAlive()
			{
				return sqf::alive(_obj);
			}
			void detach()
			{
				sqf::detach(_obj);
			}
			std::vector<float> actionIds()
			{
				// TODO Add sqf
			}
			void attachTo(object obj, vector3 offset, r_string memPoint)
			{
				sqf::attach_to(_obj, obj, offset, memPoint);
			}
			vector3 velocity()
			{
				return sqf::velocity(_obj);
			}
			r_string name()
			{
				return sqf::name(_obj);
			}
			r_string typeOf()
			{
				return sqf::type_of(_obj);
			}
			void inflame(bool burn)
			{
				sqf::inflame(_obj, burn);
			}
			bool inflamed()
			{
				return sqf::inflamed(_obj);
			}
			void removeAction(float index)
			{
				// TODO add sqf
			}
			void reveal(object target)
			{
				// TODO add sqf
			}
			object objectParent()
			{
				return sqf::object_parent(_obj);
			}
			std::vector<intercept::sqf::rv_container> everyContainer()
			{
				return sqf::every_container(_obj);
			}
			std::vector<object> everyBackpack()
			{
				return sqf::every_backpack(_obj);
			}
			float damage()
			{
				return sqf::damage(_obj);
			}
			void setDamage(float damage)
			{
				sqf::set_damage(_obj, damage);
			}
			float getHit(r_string selection)
			{
				return sqf::get_hit(_obj, selection);
			}
			float getHitpointDamage(r_string selection)
			{
				return sqf::get_hit_point_damage(_obj, selection);
			}
			void setHit(r_string part, float damage, bool useEffects)
			{
				sqf::set_hit(_obj, part, damage);
			}
			void setHitpointDamage(r_string selection, float damage, bool usEffects)
			{
				sqf::set_hit_point_damage(_obj, selection, damage);
			}
			void allowDamage(bool allow)
			{
				sqf::allow_damage(_obj, allow);
			}
			bool isDamageAllowed()
			{
				return sqf::is_damage_allowed(_obj);
			}
			bool local()
			{
				return sqf::local(_obj);
			}
		};
	}
}