#include <nsurface/surface_manager.hpp>
#include <nsurface/windows/surface.hpp>



NCPP_DEFINE_SINGLETON(nsurface::F_surface_manager);



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

	void F_windows_surface_manager::process_internal() {

		b8 has_msg = true;

		do {

			MSG msg = { };

			has_msg = PeekMessage(&msg, 0, 0, 0, PM_REMOVE);

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		} while (!has_msg);



        update_functor_(this);

	}
	void F_windows_surface_manager::run_internal(){

		enable_process();

		while(is_there_any_surface_running()){

			process_internal();

		}

		disable_process();

	}

	void F_windows_surface_manager::enable_process() {

		mouse_manager().enable_mouse_hook();

	}
	void F_windows_surface_manager::disable_process() {

		mouse_manager().disable_mouse_hook();

	}

}