#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>



namespace nsurface {

	F_windows_surface::F_windows_surface(const F_surface_desc& desc) :
		I_surface(desc)
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

	void F_windows_surface::set_offset(int offset_x, int offset_y) {

		if (
			SetWindowPos(
				handle_,
				0,
				offset_x,
				offset_y,
				0,
				0,
				SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW
			)
		) {

			desc_.offset_x = offset_x;
			desc_.offset_y = offset_y;

		}

	}
	void F_windows_surface::resize(int width, int height) {

		if (
			SetWindowPos(
				handle_,
				0,
				0,
				0,
				width,
				height,
				SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW
			)
		) {

			desc_.width = width;
			desc_.height = height;

		}

	}
	void F_windows_surface::set_rect(int offset_x, int offset_y, int width, int height) {

		if (
			SetWindowPos(
				handle_,
				0,
				offset_x,
				offset_y,
				width,
				height,
				SWP_NOZORDER | SWP_SHOWWINDOW
			)
		) {

			desc_.offset_x = offset_x;
			desc_.offset_y = offset_y;
			desc_.width = width;
			desc_.height = height;

		}

	}

}