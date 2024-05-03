#include <nsurface/macos/mouse.hpp>

#include <nsurface/macos/mouse_backend.hpp>



NCPP_DEFINE_SINGLETON(nsurface::F_mouse);



namespace nsurface {

	F_macos_mouse::F_macos_mouse()
	{



	}
	F_macos_mouse::~F_macos_mouse() {

		disable_hook_internal();

	}



    ////////////////////////////////////////////////////////////////////////////////////
    //  Internal platform specific interface
    ////////////////////////////////////////////////////////////////////////////////////

	void F_macos_mouse::enable_hook_internal() {

		// if (mouse_hook_)
		// 	return;

		// mouse_hook_ = SetWindowsHookEx(WH_MOUSE_LL, mouse_proc, NULL, 0);

	}
	void F_macos_mouse::disable_hook_internal() {

		// if (!mouse_hook_)
		// 	return;

		// UnhookWindowsHookEx(mouse_hook_);

		// mouse_hook_ = 0;

	}

}