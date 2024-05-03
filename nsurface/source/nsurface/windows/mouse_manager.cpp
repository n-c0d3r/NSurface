#include <nsurface/windows/mouse_manager.hpp>

#include <windowsx.h>



NCPP_DEFINE_SINGLETON(nsurface::F_mouse_manager);



namespace nsurface {

	F_windows_mouse_manager::F_windows_mouse_manager()
	{
	}
	F_windows_mouse_manager::~F_windows_mouse_manager()
	{
	}



	void F_windows_mouse_manager::process_msg(const MSG* msg_p) {

		switch (msg_p->message)
		{

		case WM_LBUTTONDOWN:
		{
			auto& e = button_down_event_;
			e.button_flag_ = E_mouse_button_flag::LEFT;
			e.invoke();
			break;
		}
		case WM_MBUTTONDOWN:
		{
			auto& e = button_down_event_;
			e.button_flag_ = E_mouse_button_flag::MIDDLE;
			e.invoke();
			break;
		}
		case WM_RBUTTONDOWN:
		{
			auto& e = button_down_event_;
			e.button_flag_ = E_mouse_button_flag::RIGHT;
			e.invoke();
			break;
		}

		case WM_LBUTTONUP:
		{
			auto& e = button_up_event_;
			e.button_flag_ = E_mouse_button_flag::LEFT;
			e.invoke();
			break;
		}
		case WM_MBUTTONUP:
		{
			auto& e = button_up_event_;
			e.button_flag_ = E_mouse_button_flag::MIDDLE;
			e.invoke();
			break;
		}
		case WM_RBUTTONUP:
		{
			auto& e = button_up_event_;
			e.button_flag_ = E_mouse_button_flag::RIGHT;
			e.invoke();
			break;
		}

		case WM_MOUSEMOVE:
		{
			auto& e = move_event_;
			e.position_.x = GET_X_LPARAM(msg_p->lParam);
			e.position_.y = GET_Y_LPARAM(msg_p->lParam);

			mouse_position_ = e.position_;

			e.invoke();
			break;
		}

		case WM_SETCURSOR:
		{
			// mouse visibility change
			{
				CURSORINFO ci = { sizeof(CURSORINFO) };
				b8 new_visibility = GetCursorInfo(&ci);
				if(new_visibility != is_visible_) {

					auto& e = visibility_change_event_;

					e.is_visible_ = new_visibility;

					is_visible_ = new_visibility;

					e.invoke();
				}
			}

			break;
		}

		};
	}



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_windows_mouse_manager::set_mouse_position(PA_vector2_i new_mouse_position) {

		SetCursorPos(new_mouse_position.x, new_mouse_position.y);

		mouse_position_ = new_mouse_position;
	}
	void F_windows_mouse_manager::set_mouse_visible(b8 value) {

		ShowCursor(value);

		is_visible_ = value;
	}

}