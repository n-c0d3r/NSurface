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

                    auto& e = F_mouse_manager::instance().T_get_event<F_mouse_move_event>();
                    e.position_.x = pMouseStruct->pt.x;
                    e.position_.y = pMouseStruct->pt.y;
                    e.invoke();
                    break;
                }

            }

        }

        return CallNextHookEx(0, nCode, wParam, lParam);
	}

}