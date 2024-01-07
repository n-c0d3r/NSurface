#include <nsurface/macos/mouse_manager.hpp>

#include <nsurface/macos/mouse_manager_backend.hpp>



NCPP_DEFINE_SINGLETON(nsurface::F_mouse_manager);



namespace nsurface {

	F_macos_mouse_manager::F_macos_mouse_manager()
	{



	}
	F_macos_mouse_manager::~F_macos_mouse_manager() {

		disable_mouse_hook();

	}



	void F_macos_mouse_manager::enable_mouse_hook() {

		// if (mouse_hook_)
		// 	return;

		// mouse_hook_ = SetWindowsHookEx(WH_MOUSE_LL, mouse_proc, NULL, 0);

	}
	void F_macos_mouse_manager::disable_mouse_hook() {

		// if (!mouse_hook_)
		// 	return;

		// UnhookWindowsHookEx(mouse_hook_);

		// mouse_hook_ = 0;

	}

}