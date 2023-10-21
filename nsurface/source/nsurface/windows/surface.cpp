#include <nsurface/windows/surface.hpp>



namespace nsurface {

	F_windows_surface::F_windows_surface(const F_surface_desc& desc) :
		desc_(desc)
	{

		create_window_internal();

	}
	F_windows_surface::~F_windows_surface() {

		release_window_internal();

	}



	void F_windows_surface::create_window_internal() {



	}
	void F_windows_surface::release_window_internal() {



	}

}