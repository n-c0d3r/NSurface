#pragma once

/** @file nsurface/surface_manager_base.hpp
*
*   Implement base functionalities for surface manager.
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

#include <nsurface/enums.hpp>
#include <nsurface/surface_desc.hpp>
#include <nsurface/typedef_cross_platform.hpp>

#include <nsurface/mouse_manager.hpp>
#include <nsurface/keyboard_manager.hpp>

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



	class NSURFACE_API A_surface_manager {

    public:
        NSURFACE_FRIEND_CLASSES;
        NCPP_OBJECT_FRIEND_CLASSES();



	public:
		using F_update = void(F_surface_manager&);
		using F_update_functor = eastl::function<F_update>;



	private:
		TF_list<TU<F_surface>> surface_p_list_;

		F_mouse_manager mouse_manager_;
		F_keyboard_manager keyboard_manager_;

	protected:
		F_update_functor update_functor_;

	public:
		NCPP_FORCE_INLINE F_mouse_manager& mouse_manager() { return mouse_manager_; }
		NCPP_FORCE_INLINE F_keyboard_manager& keyboard_manager() { return keyboard_manager_; }

        b8 is_there_any_surface_running() const;



	protected:
		A_surface_manager();

    public:
		virtual ~A_surface_manager();



	private:
		void release_surfaces_internal();



	public:
		TK_valid<F_surface> create_surface(const F_surface_desc& desc);
		void delete_surface(TKPA_valid<F_surface>);



        ////////////////////////////////////////////////////////////////////////////////////
        //  Internal platform specific interface
        ////////////////////////////////////////////////////////////////////////////////////

	private:
		void process_internal(); // for documentations
        void run_internal(); // for documentations



	public:
		template<typename F_update_functor__>
        inline void T_run(F_update_functor__&& update_functor) {

			update_functor_ = std::forward<F_update_functor__>(update_functor);

            run_internal();

		}



	public:
		NCPP_FORCE_INLINE F_surface_manager* as_current_platform_p() { return reinterpret_cast<F_surface_manager*>(this); }
		NCPP_FORCE_INLINE F_surface_manager& as_current_platform() { return *reinterpret_cast<F_surface_manager*>(this); }

	};

}
