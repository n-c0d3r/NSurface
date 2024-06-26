#pragma once

/** @file nsurface/windows/keycode.hpp
*
*   Implement keycode.
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma region Includes

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include <nsurface/prerequisites.hpp>

#pragma endregion



namespace nsurface {

	enum class E_windows_keycode {

		NONE = 0,

		WINDOWS_L = (u32)VK_LWIN,
		WINDOWS_R = (u32)VK_RWIN,

		BACKSPACE = (u32)VK_BACK,
		TAB = (u32)VK_TAB,
		ENTER = (u32)VK_RETURN,
		SHIFT_L = (u32)VK_LSHIFT,
		CONTROL_L = (u32)VK_LCONTROL,
		ALT_L = (u32)VK_LMENU,
		SHIFT_R = (u32)VK_RSHIFT,
		CONTROL_R = (u32)VK_RCONTROL,
		ALT_R = (u32)VK_RMENU,
		PAUSE = (u32)VK_PAUSE,
		CAPSLOCK = (u32)VK_CAPITAL,
		ESCAPE = (u32)VK_ESCAPE,
		SPACE = (u32)VK_SPACE,
		PAGE_UP = (u32)VK_PRIOR,
		PAGE_DOWN = (u32)VK_NEXT,
		END = (u32)VK_END,
		HOME = (u32)VK_HOME,
		ARROW_LEFT = (u32)VK_LEFT,
		ARROW_UP = (u32)VK_UP,
		ARROW_RIGHT = (u32)VK_RIGHT,
		ARROW_DOWN = (u32)VK_DOWN,
		INSERT = (u32)VK_INSERT,
		DEL = (u32)VK_DELETE,
		SEPARATOR = (u32)VK_SEPARATOR,
		ADD = (u32)VK_ADD,
		SUBTRACT = (u32)VK_SUBTRACT,
		MULTIPLY = (u32)VK_MULTIPLY,
		DIVIDE = (u32)VK_DIVIDE,
		F1 = (u32)VK_F1,
		F2 = (u32)VK_F2,
		F3 = (u32)VK_F3,
		F4 = (u32)VK_F4,
		F5 = (u32)VK_F5,
		F6 = (u32)VK_F6,
		F7 = (u32)VK_F7,
		F8 = (u32)VK_F8,
		F9 = (u32)VK_F9,
		F10 = (u32)VK_F10,
		F11 = (u32)VK_F11,
		F12 = (u32)VK_F12,
		NUMLOCK = (u32)VK_NUMLOCK,
		NUMPAD0 = (u32)VK_NUMPAD0,
		NUMPAD1 = (u32)VK_NUMPAD1,
		NUMPAD2 = (u32)VK_NUMPAD2,
		NUMPAD3 = (u32)VK_NUMPAD3,
		NUMPAD4 = (u32)VK_NUMPAD4,
		NUMPAD5 = (u32)VK_NUMPAD5,
		NUMPAD6 = (u32)VK_NUMPAD6,
		NUMPAD7 = (u32)VK_NUMPAD7,
		NUMPAD8 = (u32)VK_NUMPAD8,
		NUMPAD9 = (u32)VK_NUMPAD9,
		_0 = 0x30,
		_1 = 0x31,
		_2 = 0x32,
		_3 = 0x33,
		_4 = 0x34,
		_5 = 0x35,
		_6 = 0x36,
		_7 = 0x37,
		_8 = 0x38,
		_9 = 0x39,
		A = 0x41,
		B = 0x42,
		C = 0x43,
		D = 0x44,
		E = 0x45,
		F = 0x46,
		G = 0x47,
		H = 0x48,
		I = 0x49,
		J = 0x4A,
		K = 0x4B,
		L = 0x4C,
		M = 0x4D,
		N = 0x4E,
		O = 0x4F,
		P = 0x50,
		Q = 0x51,
		R = 0x52,
		S = 0x53,
		T = 0x54,
		U = 0x55,
		V = 0x56,
		W = 0x57,
		X = 0x58,
		Y = 0x59,
		Z = 0x5A

	};

}