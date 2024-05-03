#include <nsurface/windows/window_proc.hpp>
#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>

#include <nsurface/events/.hpp>

#include <locale>
#include <codecvt>
#include <string>



namespace nsurface {

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{

		F_surface* raw_surface_p = reinterpret_cast<F_surface*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        TK<F_surface> surface_p;

        if (raw_surface_p) {
			surface_p = TK<F_surface>::unsafe(raw_surface_p);
		}

		switch (uMsg)
		{

			case WM_CREATE:
			{

				CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);

				SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreate->lpCreateParams));

				return 0;
			}

			case WM_DESTROY:
			{

                auto valid_surface_p = F_valid_requirements::T_forward(surface_p);

                auto& event = surface_p->T_get_event<F_surface_user_destroy_request_event>();

                event.destroyable = true;
                event.invoke();

                if (event.destroyable){

                    valid_surface_p->is_user_delete_ = true;

                    F_surface_manager::instance().delete_surface(valid_surface_p);

                    PostQuitMessage(0);
                }

				return 0;
			}

			case WM_SIZE:
			{

				auto& e = surface_p->T_get_event<F_surface_resize_event>();

                RECT rect;
                if(GetWindowRect(hwnd, &rect))
                {
                    e.size_.x = rect.right - rect.left;
                    e.size_.y = rect.bottom - rect.top;
                }

                surface_p->desc_.size = e.size_;

                e.invoke();

				return 0;
			}
			case WM_SIZING:
			{

				auto& e = surface_p->T_get_event<F_surface_resize_event>();

                RECT rect;
                if(GetWindowRect(hwnd, &rect))
                {
                    e.size_.x = rect.right - rect.left;
                    e.size_.y = rect.bottom - rect.top;
                }

                surface_p->desc_.size = e.size_;

				e.invoke();

				return 0;
			}

			case WM_MOVE:
			{

				auto& e = surface_p->T_get_event<F_surface_move_event>();

				e.offset_.x = LOWORD(lParam);
				e.offset_.y = HIWORD(lParam);

				surface_p->desc_.offset = e.offset_;

				e.invoke();

				return 0;
			}
			case WM_MOVING:
			{

				auto& e = surface_p->T_get_event<F_surface_move_event>();

				e.offset_.x = LOWORD(lParam);
				e.offset_.y = HIWORD(lParam);

				surface_p->desc_.offset = e.offset_;

				e.invoke();

				return 0;
			}

		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

}