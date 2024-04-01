#pragma once

/** @file nsurface/surface_base.hpp
*
*   Implement base functionalities for surface.
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Includes

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nsurface/prerequisites.hpp>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nsurface/events/.hpp>
#include <nsurface/enums.hpp>
#include <nsurface/surface_desc.hpp>
#include <nsurface/typedef_cross_platform.hpp>

#pragma endregion



 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



namespace nsurface {

	NSURFACE_USING_NLIB_NAMESPACES();



	namespace internal {

		NCPP_FORCE_INLINE b8& surface_inject_is_running(A_surface* surface_p);

	}



	class A_surface {

    public:
        NSURFACE_FRIEND_CLASSES;
        NCPP_OBJECT_FRIEND_CLASSES();



	public:
		friend class A_surface_manager;

		friend b8& internal::surface_inject_is_running(A_surface* surface_p);



    protected:
        F_surface_desc desc_;

        b8 is_running_ = false;

		typename TG_list<TU_valid<F_surface>>::iterator iterator_ = {};

    public:
        NCPP_FORCE_INLINE const F_surface_desc& desc() const { return desc_; }

        NCPP_FORCE_INLINE b8 is_running() const { return is_running_; }



	private:
		F_surface_destroy_event destroy_event_;
		F_surface_user_destroy_request_event destroy_request_event_;
		F_surface_resize_event resize_event_;
		F_surface_move_event move_event_;

	public:
		NCPP_DECLARE_STATIC_EVENTS(
			destroy_event_,
			destroy_request_event_,
			resize_event_,
			move_event_
		);



	protected:
		A_surface(const F_surface_desc& desc);

    public:
		virtual ~A_surface();



	public:
		void set_visibility(E_surface_visibility visibility) {} // for documentations

		void set_offset(PA_vector2_i32 offset) {} // for documentations
		void resize(PA_vector2_i32 size) {} // for documentations
		void set_rect(PA_vector2_i32 offset, PA_vector2_i32 size) {} // for documentations



	public:
		NCPP_FORCE_INLINE F_surface* as_current_platform_p() { return reinterpret_cast<F_surface*>(this); }
        NCPP_FORCE_INLINE F_surface& as_current_platform() { return *reinterpret_cast<F_surface*>(this); }

	};



	namespace internal {

		NCPP_FORCE_INLINE F_surface_desc& surface_inject_desc(A_surface* surface_p){

            return (F_surface_desc&)(surface_p->desc());
		}

		NCPP_FORCE_INLINE b8& surface_inject_is_running(A_surface* surface_p){

			return surface_p->is_running_;
		}

	}

}
