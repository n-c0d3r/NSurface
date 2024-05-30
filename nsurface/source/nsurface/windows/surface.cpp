#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>



namespace nsurface {

	F_windows_surface::F_windows_surface(const F_surface_desc& desc) :
        A_surface(desc)
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

			if(desc_.is_has_focus) {
				SetFocus(handle_);
			}
			else {
				if(GetFocus() == handle_) {
					SetFocus(NULL);
				}
				else {
				}
			}

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

	void F_windows_surface::set_offset(PA_vector2_i offset) {

		desc_.offset = offset;

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

	}
	void F_windows_surface::resize(PA_vector2_i size) {

		desc_.size = size;

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

	}
	void F_windows_surface::set_rect(PA_vector2_i offset, PA_vector2_i size) {

		desc_.offset = offset;
		desc_.size = size;

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

	}
	void F_windows_surface::set_title(const G_wstring& title) {

		SetWindowText(
			handle_,
			title.c_str()
		);
	}
	void F_windows_surface::set_focus(b8 value) {

		desc_.is_has_focus = value;

		if(value) {
			SetFocus(handle_);
		}
		else {
			if(GetFocus() == handle_) {
				SetFocus(NULL);
			}
			else {
			}
		}
	}

	void F_windows_surface::set_mouse_capture(b8 value) {

		if(value == is_enable_mouse_capture_)
			return;

		if(value) {
			RECT rect;
			GetWindowRect(
				handle_,
				&rect
			);
			ClipCursor(&rect);
		}
		else {
			ClipCursor(0);
		}

		is_enable_mouse_capture_ = value;
	}



	void F_windows_surface::registry_custom_window_proc_handler(F_custom_window_proc_handler handler) {

		custom_window_proc_handlers_.push_back(handler);
	}

}