#include <nsurface/windows/mouse_manager.hpp>
#include <nsurface/windows/mouse_proc.hpp>



NCPP_DEFINE_SINGLETON(nsurface::F_mouse_manager);



namespace nsurface {

	F_windows_mouse_manager::F_windows_mouse_manager()
	{



	}
	F_windows_mouse_manager::~F_windows_mouse_manager() {

		disable_mouse_hook_internal();

	}



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_windows_mouse_manager::enable_mouse_hook_internal() {

		if (mouse_hook_)
			return;

		mouse_hook_ = SetWindowsHookEx(WH_MOUSE, mouse_proc, GetModuleHandle(0), GetCurrentThreadId());

	}
	void F_windows_mouse_manager::disable_mouse_hook_internal() {

		if (!mouse_hook_)
			return;

		UnhookWindowsHookEx(mouse_hook_);

		mouse_hook_ = 0;

	}

}