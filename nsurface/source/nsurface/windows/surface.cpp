#include <nsurface/windows/surface.hpp>



namespace nsurface {

	b8 F_windows_surface::is_class_created_s_ = false;
	const wchar_t F_windows_surface::class_name_cstr_s_[] = L"nsurface::window_class";



	LRESULT CALLBACK window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}



	F_windows_surface::F_windows_surface(const F_surface_desc& desc) :
		desc_(desc)
	{

		if (!is_class_created_s_)
			create_window_class_internal();

		create_window_internal();

	}
	F_windows_surface::~F_windows_surface() {

		release_window_internal();

	}



	void F_windows_surface::create_window_class_internal() {

		is_class_created_s_ = true;

		WNDCLASS wc = { };

		wc.lpfnWndProc = window_proc;
		wc.lpszClassName = class_name_cstr_s_;

		RegisterClass(&wc);

	}

	void F_windows_surface::create_window_internal() {

		handle_ = CreateWindowEx(
			NULL,
			class_name_cstr_s_,
			desc_.title.c_str(),
			WS_OVERLAPPEDWINDOW,

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			NULL,
			NULL,
			NULL,
			NULL 
		);

	}
	void F_windows_surface::release_window_internal() {



	}



	b8 F_windows_surface::check_input() {



		return false;
	}

}