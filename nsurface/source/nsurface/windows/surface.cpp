#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>



namespace nsurface {

	F_windows_surface::F_windows_surface(F_surface_manager* surface_manager_p, const F_surface_desc& desc) :
		I_surface(surface_manager_p, desc)
	{

		create_window_internal();

		set_visibility(desc_.visibility);

	}
	F_windows_surface::~F_windows_surface() {

		release_window_internal();

	}



	void F_windows_surface::create_window_internal() {

		handle_ = CreateWindowEx(
			NULL,
			F_windows_surface_manager::window_class_name_cstr(),
			desc_.title.c_str(),
			WS_OVERLAPPEDWINDOW,

			// Size and position
			desc_.offset_x, desc_.offset_y, desc_.width, desc_.height,

			NULL,
			NULL,
			NULL,
			this 
		);

		if (handle_) {

			is_running_ = true;

		}

	}
	void F_windows_surface::release_window_internal() {

		if (handle_) {



		}

		is_running_ = false;

	}



	void F_windows_surface::set_visibility(E_surface_visibility visibility) {

		switch (visibility)
		{
		case nsurface::E_surface_visibility::VISIBLE:
			desc_.visibility = ShowWindow(handle_, SW_SHOW) ? visibility : desc_.visibility;
			break;
		case nsurface::E_surface_visibility::HIDE:
			desc_.visibility = ShowWindow(handle_, SW_HIDE) ? visibility : desc_.visibility;
			break;
		default:
			break;
		}

	}

}