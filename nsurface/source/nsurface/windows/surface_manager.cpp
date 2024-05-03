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



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_windows_surface_manager::process_internal() {

		mouse_.pre_process_msg();
		keyboard_.pre_process_msg();

		while(true) {

			MSG msg = { };

			if(!PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);

			mouse_.process_msg(msg.message, msg.wParam, msg.lParam);
			keyboard_.process_msg(msg.message, msg.wParam, msg.lParam);

		}

        update_functor_(*this);

	}
	void F_windows_surface_manager::run_internal(){

		while(is_there_any_surface_running()){

			process_internal();

		}

	}

}