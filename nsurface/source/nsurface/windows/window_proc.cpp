#include <nsurface/windows/window_proc.hpp>
#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>

#include <nsurface/events/.hpp>



namespace nsurface {

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{

		F_surface* surface_p = reinterpret_cast<F_surface*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

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

				surface_p->T_get_event<F_surface_destroy_event>().invoke();

				surface_p->release_window_internal();

				PostQuitMessage(0);
				return 0;
			}

			case WM_SIZE:
			{

				auto& e = surface_p->T_get_event<F_surface_post_resize_event>();

                RECT rect;
                if(GetWindowRect(hwnd, &rect))
                {
                    e.width_ = rect.right - rect.left;
                    e.height_ = rect.bottom - rect.top;
                }

                surface_p->desc_.width = e.width_;
                surface_p->desc_.height = e.height_;

                e.invoke();

				return 0;
			}
			case WM_SIZING:
			{

				auto& e = surface_p->T_get_event<F_surface_resizing_event>();

                RECT rect;
                if(GetWindowRect(hwnd, &rect))
                {
                    e.width_ = rect.right - rect.left;
                    e.height_ = rect.bottom - rect.top;
                }

                surface_p->desc_.width = e.width_;
                surface_p->desc_.height = e.height_;

				e.invoke();

				return 0;
			}

			case WM_MOVE:
			{

				auto& e = surface_p->T_get_event<F_surface_post_move_event>();

				e.offset_x_ = LOWORD(lParam);
				e.offset_y_ = HIWORD(lParam);

				e.invoke();

				return 0;
			}
			case WM_MOVING:
			{

				auto& e = surface_p->T_get_event<F_surface_moving_event>();

				e.offset_x_ = LOWORD(lParam);
				e.offset_y_ = HIWORD(lParam);

				e.invoke();

				return 0;
			}

		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

}