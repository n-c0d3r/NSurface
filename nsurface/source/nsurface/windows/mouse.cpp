#include <nsurface/windows/mouse.hpp>
#include <nsurface/windows/surface.hpp>

#include <windowsx.h>



NCPP_DEFINE_SINGLETON(nsurface::F_mouse);



namespace nsurface {

	F_windows_mouse::F_windows_mouse()
	{
		// register raw input device
		RAWINPUTDEVICE raw_input_device;
		raw_input_device.usUsagePage = 0x1 /* HID_USAGE_PAGE_GENERIC */;
		raw_input_device.usUsage = 0x2 /* HID_USAGE_GENERIC_MOUSE */;
		raw_input_device.dwFlags = 0;
		raw_input_device.hwndTarget = 0;
		if (!RegisterRawInputDevices(&raw_input_device, 1, sizeof(RAWINPUTDEVICE)))
		{
			NCPP_ASSERT(false) << "can't register raw input device for mouse";
		}
	}
	F_windows_mouse::~F_windows_mouse()
	{
	}



	void F_windows_mouse::process_msg(UINT message, WPARAM wParam, LPARAM lParam) {

		switch (message)
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

//		case WM_MOUSEMOVE:
//		{
//			break;
//		}

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

		case WM_INPUT:
		{
			RAWINPUT raw_input;
			u32 raw_input_size = sizeof(RAWINPUT);

			if(
				GetRawInputData(
					reinterpret_cast<HRAWINPUT>(lParam),
					RID_INPUT,
					&raw_input,
					&raw_input_size,
					sizeof(RAWINPUTHEADER)
				)
				== u32(-1)
			)
			{
				NCPP_ASSERT(false) << "can't get raw input data";
			}

			if (raw_input.header.dwType == RIM_TYPEMOUSE) {

				auto& e = move_event_;

				if(!(raw_input.data.mouse.usFlags & MOUSE_MOVE_ABSOLUTE)) {

					delta_position_.x = raw_input.data.mouse.lLastX;
					delta_position_.y = raw_input.data.mouse.lLastY;
				}

				POINT p;
				GetCursorPos(&p);
				position_.x = p.x;
				position_.y = p.y;

				e.invoke();
			}

			break;
		}

		};
	}



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_windows_mouse::set_mouse_position(PA_vector2_i new_mouse_position) {

		SetCursorPos(new_mouse_position.x, new_mouse_position.y);

		position_ = new_mouse_position;
	}
	void F_windows_mouse::pre_process_msg() {

		delta_position_ = F_vector2_i::zero();
	}
	void F_windows_mouse::set_mouse_visible(b8 value) {

		if(value) {

			while(ShowCursor(value) < 0);
		}
		else {

			while(ShowCursor(value) >= 0);
		}

		is_visible_ = value;
	}

}