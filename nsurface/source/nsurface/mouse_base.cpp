#include <nsurface/mouse_base.hpp>



namespace nsurface {

	A_mouse::A_mouse() :
		button_down_event_(),
		button_up_event_(),
		move_event_(),
		visibility_change_event_()
	{
	}
	A_mouse::~A_mouse() {
	}

}