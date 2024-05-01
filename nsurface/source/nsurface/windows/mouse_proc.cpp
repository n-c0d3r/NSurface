#include <nsurface/windows/mouse_proc.hpp>
#include <nsurface/mouse_manager.hpp>
#include <nsurface/enums.hpp>



namespace nsurface {

	LRESULT CALLBACK mouse_proc(int nCode, WPARAM wParam, LPARAM lParam)
	{

        if (nCode >= 0) {

            switch (wParam)
			{

			case WM_LBUTTONDOWN:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_down_event>();
				e.button_flag_ = E_mouse_button_flag::LEFT;
				e.invoke();
				break;
			}
			case WM_MBUTTONDOWN:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_down_event>();
				e.button_flag_ = E_mouse_button_flag::MIDDLE;
				e.invoke();
				break;
			}
			case WM_RBUTTONDOWN:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_down_event>();
				e.button_flag_ = E_mouse_button_flag::RIGHT;
				e.invoke();
				break;
			}

			case WM_LBUTTONUP:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_up_event>();
				e.button_flag_ = E_mouse_button_flag::LEFT;
				e.invoke();
				break;
			}
			case WM_MBUTTONUP:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_up_event>();
				e.button_flag_ = E_mouse_button_flag::MIDDLE;
				e.invoke();
				break;
			}
			case WM_RBUTTONUP:
			{
				auto& e = F_mouse_manager::instance().T_get_event<F_mouse_button_up_event>();
				e.button_flag_ = E_mouse_button_flag::RIGHT;
				e.invoke();
				break;
			}

			case WM_MOUSEMOVE:
			{
				MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;

				auto& mouse_manager = F_mouse_manager::instance();

				auto& e = mouse_manager.T_get_event<F_mouse_move_event>();
				e.position_.x = pMouseStruct->pt.x;
				e.position_.y = pMouseStruct->pt.y;

				inject_mouse_position(mouse_manager) = e.position_;

				e.invoke();
				break;
			}

			case WM_SETCURSOR:
			{

				// mouse visibility change
				{
					auto& mouse_manager = F_mouse_manager::instance();

					CURSORINFO ci = { sizeof(CURSORINFO) };
					b8 new_visibility = GetCursorInfo(&ci);
					if(new_visibility != mouse_manager.is_visible()) {

						auto& e = mouse_manager.T_get_event<F_mouse_visibility_change_event>();

						e.is_visible_ = new_visibility;
						e.invoke();
					}
				}

				break;
			}

			};

        }

        return CallNextHookEx(0, nCode, wParam, lParam);
	}

}