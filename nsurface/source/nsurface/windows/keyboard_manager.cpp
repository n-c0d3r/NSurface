#include <nsurface/windows/keyboard_manager.hpp>

#include <windowsx.h>



NCPP_DEFINE_SINGLETON(nsurface::F_keyboard_manager);



namespace nsurface {

	F_windows_keyboard_manager::F_windows_keyboard_manager()
	{
	}
	F_windows_keyboard_manager::~F_windows_keyboard_manager()
	{
	}



	void F_windows_keyboard_manager::process_msg(const MSG* msg_p) {

		switch (msg_p->message)
		{

		case WM_KEYDOWN:
		{
			auto& e = key_down_event_;

			e.keycode_ = E_keycode(u32(msg_p->wParam));
			e.invoke();

			break;
		}
		case WM_KEYUP:
		{
			auto& e = key_up_event_;

			e.keycode_ = E_keycode(u32(msg_p->wParam));
			e.invoke();

			break;
		}

		case WM_CHAR:
		{
			auto& e = text_character_event_;

			e.text_character_ = (wchar_t)(msg_p->wParam);
			e.invoke();

			break;
		}

		};
	}

}