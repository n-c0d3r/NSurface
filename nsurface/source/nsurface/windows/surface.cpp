#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>



namespace nsurface {

	F_windows_surface::F_windows_surface(const F_surface_desc& desc) :
        A2_surface(desc)
	{

		create_window_internal();

		set_visibility(desc_.visibility);

	}
	F_windows_surface::~F_windows_surface() {

        T_get_event<F_surface_destroy_event>().invoke();

		release_window_internal();

        is_running_ = false;

	}



	void F_windows_surface::create_window_internal() {

		handle_ = CreateWindowEx(
			NULL,
			F_windows_surface_manager::window_class_name_cstr(),
			desc_.title.c_str(),
			WS_OVERLAPPEDWINDOW,

			// Size and position
			desc_.offset.x, desc_.offset.y, desc_.size.x, desc_.size.y,

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

		if (handle_ && !is_user_delete_) {

            CloseWindow(handle_);

		}

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

	void F_windows_surface::set_offset(PA_vector2_i32 offset) {

        NCPP_ASSERT(
            SetWindowPos(
                handle_,
                0,
                offset.x,
                offset.y,
                0,
                0,
                SWP_NOZORDER | SWP_NOSIZE | SWP_SHOWWINDOW
            )
        ) << "can't set surface's offset";

        desc_.offset = offset;

	}
	void F_windows_surface::resize(PA_vector2_i32 size) {

        NCPP_ASSERT(
			SetWindowPos(
				handle_,
				0,
				0,
				0,
                size.x,
                size.y,
				SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW
			)
		) << "can't resize surface";

        desc_.size = size;

	}
	void F_windows_surface::set_rect(PA_vector2_i32 offset, PA_vector2_i32 size) {

		NCPP_ASSERT(
			SetWindowPos(
				handle_,
				0,
				offset.x,
				offset.y,
                size.x,
                size.y,
				SWP_NOZORDER | SWP_SHOWWINDOW
			)
		) << "can't set surface's rect";

        desc_.offset = offset;
        desc_.size = size;

	}

}