#include <nsurface/windows/window_proc.hpp>
#include <nsurface/windows/surface.hpp>
#include <nsurface/windows/surface_manager.hpp>



namespace nsurface {

	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{

			case WM_CREATE:
			{

				CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
				F_surface* surface_p = reinterpret_cast<F_surface*>(pCreate->lpCreateParams);

				SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(surface_p));

				break;
			}

			case WM_DESTROY:
			{

				F_surface* surface_p = reinterpret_cast<F_surface*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

				surface_p->release_window_internal();

				PostQuitMessage(0);
				return 0;
			}

		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

}