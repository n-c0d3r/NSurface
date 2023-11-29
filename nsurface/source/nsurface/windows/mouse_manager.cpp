#include <nsurface/windows/mouse_manager.hpp>
#include <nsurface/windows/mouse_proc.hpp>



namespace nsurface {

	F_windows_mouse_manager::F_windows_mouse_manager()
	{



	}
	F_windows_mouse_manager::~F_windows_mouse_manager() {

		disable_mouse_hook();

	}



	void F_windows_mouse_manager::enable_mouse_hook() {

		if (mouse_hook_)
			return;

		mouse_hook_ = SetWindowsHookEx(WH_MOUSE_LL, mouse_proc, NULL, 0);

	}
	void F_windows_mouse_manager::disable_mouse_hook() {

		if (!mouse_hook_)
			return;

		UnhookWindowsHookEx(mouse_hook_);

		mouse_hook_ = 0;

	}

}