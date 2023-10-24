#include <nsurface/surface_manager.hpp>
#include <nsurface/windows/surface.hpp>



namespace nsurface {

	const wchar_t F_windows_surface_manager::window_class_name_cstr_s_[] = L"nsurface::window_class";



	F_windows_surface_manager::F_windows_surface_manager() {

		create_window_class_internal();

	}
	F_windows_surface_manager::~F_windows_surface_manager() {



	}



	void F_windows_surface_manager::create_window_class_internal() {

		WNDCLASS wc = { };

		wc.lpfnWndProc = window_proc;
		wc.lpszClassName = window_class_name_cstr_s_;

		RegisterClass(&wc);

	}

	b8 F_windows_surface_manager::process() {

		MSG msg = { };

		b8 has_msg = PeekMessage(&msg, 0, 0, 0, PM_REMOVE);

		TranslateMessage(&msg);
		DispatchMessage(&msg);

		return !has_msg;
	}

	void F_windows_surface_manager::enable_process() {

		mouse_manager().enable_mouse_hook();

	}
	void F_windows_surface_manager::disable_process() {

		mouse_manager().disable_mouse_hook();

	}

}