#include <nsurface/surface_manager.hpp>
#include <nsurface/macos/surface.hpp>

#include <nsurface/macos/surface_manager_backend.hpp>



NCPP_DEFINE_SINGLETON(nsurface::F_surface_manager);



namespace nsurface {

	F_macos_surface_manager::F_macos_surface_manager() {

		internal::macos_surface_manager_init(this);

	}
	F_macos_surface_manager::~F_macos_surface_manager() {

		internal::macos_surface_manager_release(this);

	}



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_macos_surface_manager::process_internal() {

        

	}
	void F_macos_surface_manager::run_internal(){

		enable_process_internal();

		internal::macos_surface_manager_loop(this);

		disable_process_internal();

	}

	void F_macos_surface_manager::enable_process_internal() {

		mouse_manager().enable_hook_internal();

	}
	void F_macos_surface_manager::disable_process_internal() {

		mouse_manager().disable_hook_internal();

	}

}
