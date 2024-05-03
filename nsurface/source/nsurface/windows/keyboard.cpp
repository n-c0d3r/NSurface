#include <nsurface/windows/keyboard.hpp>

#include <windowsx.h>



NCPP_DEFINE_SINGLETON(nsurface::F_keyboard);



namespace nsurface {

	F_windows_keyboard::F_windows_keyboard()
	{
	}
	F_windows_keyboard::~F_windows_keyboard()
	{
	}



	void F_windows_keyboard::process_msg(UINT message, WPARAM wParam, LPARAM lParam) {

		switch (message)
		{

		case WM_KEYDOWN:
		{
			auto& e = key_down_event_;

			e.keycode_ = E_keycode(u32(wParam));
			e.invoke();

			break;
		}
		case WM_KEYUP:
		{
			auto& e = key_up_event_;

			e.keycode_ = E_keycode(u32(wParam));
			e.invoke();

			break;
		}

		case WM_CHAR:
		{
			auto& e = text_character_event_;

			e.text_character_ = (wchar_t)(wParam);
			e.invoke();

			break;
		}

		};
	}

}