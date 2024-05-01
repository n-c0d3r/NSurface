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

		set_mouse_visible(true);
	}
	void F_windows_mouse_manager::disable_mouse_hook_internal() {

		if (!mouse_hook_)
			return;

		UnhookWindowsHookEx(mouse_hook_);

		mouse_hook_ = 0;

	}

	void F_windows_mouse_manager::update() {
	}

	void F_windows_mouse_manager::set_mouse_position(PA_vector2_i new_mouse_position) {

		SetCursorPos(new_mouse_position.x, new_mouse_position.y);

		mouse_position_ = new_mouse_position;
	}
	void F_windows_mouse_manager::set_mouse_visible(b8 value) {

		ShowCursor(value);

		is_visible_ = value;
	}

}