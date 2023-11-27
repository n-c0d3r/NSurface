#include <nsurface/surface_manager.hpp>
#include <nsurface/macos/surface.hpp>

#include <nsurface/macos/surface_manager_backend.hpp>



namespace nsurface {

	F_macos_surface_manager::F_macos_surface_manager() {

		internal::macos_surface_manager_init(this);

	}
	F_macos_surface_manager::~F_macos_surface_manager() {

		internal::macos_surface_manager_release(this);

	}



	void F_macos_surface_manager::process_internal() {

        

	}
	void F_macos_surface_manager::run_internal(){

		enable_process();

		internal::macos_surface_manager_loop(this);

		disable_process();

	}

	void F_macos_surface_manager::enable_process() {

		mouse_manager().enable_mouse_hook();

	}
	void F_macos_surface_manager::disable_process() {

		mouse_manager().disable_mouse_hook();

	}

}
