#pragma once

#include <intercept.hpp>

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
			void setPos(vector3 vec)
			{
				sqf::set_pos(this->_obj, vec);
			}
			void setPosAsl(vector3 vec)
			{
				sqf::set_pos_asl(this->_obj, vec);
			}
			void setPosAsl2(vector3 vec)
			{
				sqf::set_pos_asl2(this->_obj, vec);
			}
			void setPosAslw(vector3 vec)
			{
				sqf::set_pos_aslw(this->_obj, vec);
			}
			void setPosAtl(vector3 vec)
			{
				sqf::set_pos_atl(this->_obj, vec);
			}
			void setPosWorld(vector3 vec)
			{
				sqf::set_pos_world(this->_obj, vec);
			}

			vector3 getPos()
			{
				return sqf::get_pos(this->_obj);
			}
			vector3 getPosAsl()
			{
				return sqf::get_pos_asl(this->_obj);
			}
			vector3 getPosAslVisual()
			{
				return sqf::get_pos_asl_visual(this->_obj);
			}
			vector3 getPosAslw()
			{
				return sqf::get_pos_aslw(this->_obj);
			}
			vector3 getPosAtl()
			{
				return sqf::get_pos_atl(this->_obj);
			}
			vector3 getPosAtlVisual()
			{
				return sqf::get_pos_atl_visual(this->_obj);
			}
			vector3 getPosVisual()
			{
				return sqf::get_pos_visual(this->_obj);
			}
			vector3 getPosWorld()
			{
				return sqf::get_pos_world(this->_obj);
			}

			bool isAlive()
			{
				return sqf::alive(this->_obj);
			}
			void detach()
			{
				sqf::detach(this->_obj);
			}
			std::vector<float> actionIds()
			{
				// TODO Add sqf
			}
			void attachTo(object obj, vector3 offset, r_string memPoint)
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
			r_string typeOf()
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
				return sqf::object_parent(this->_obj);
			}
			std::vector<intercept::sqf::rv_container> everyContainer()
			{
				return sqf::every_container(this->_obj);
			}
			std::vector<object> everyBackpack()
			{
				return sqf::every_backpack(this->_obj);
			}
			float damage()
			{
				return sqf::damage(this->_obj);
			}
			void setDamage(float damage)
			{
				sqf::set_damage(this->_obj, damage);
			}
			float getHit(r_string selection)
			{
				return sqf::get_hit(this->_obj, selection);
			}
			float getHitpointDamage(r_string selection)
			{
				return sqf::get_hit_point_damage(this->_obj, selection);
			}
			void setHit(r_string part, float damage, bool useEffects)
			{
				sqf::set_hit(this->_obj, part, damage);
			}
			void setHitpointDamage(r_string selection, float damage, bool usEffects)
			{
				sqf::set_hit_point_damage(this->_obj, selection, damage);
			}
			void allowDamage(bool allow)
			{
				sqf::allow_damage(this->_obj, allow);
			}
			bool isDamageAllowed()
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