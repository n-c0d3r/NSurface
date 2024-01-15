
#include <nsurface/.hpp>

using namespace nsurface;



NCPP_ENTRY_POINT() {
	
	F_surface_manager surface_manager;



	// create surface
	F_surface* surface_p = surface_manager.create_surface(
		F_surface_desc {
	
			// title
			ncpp::G_text(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR)
	
		}
	);



	// surface events
	surface_p->T_get_event<F_surface_destroy_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "surface is destroyed";

		}
	);

	surface_p->T_get_event<F_surface_resizing_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "resizing " << ((F_surface_resizing_event&)e).width() << " " << ((F_surface_resizing_event&)e).height();

		}
	);
	surface_p->T_get_event<F_surface_post_resize_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "post resize " << ((F_surface_post_resize_event&)e).width() << " " << ((F_surface_post_resize_event&)e).height();

		}
	);

	surface_p->T_get_event<F_surface_moving_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "moving " << ((F_surface_moving_event&)e).offset_x() << " " << ((F_surface_moving_event&)e).offset_y();

		}
	);
	surface_p->T_get_event<F_surface_post_move_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "post move " << ((F_surface_post_move_event&)e).offset_x() << " " << ((F_surface_post_move_event&)e).offset_y();

		}
	);



	// get mouse manager
	auto& mouse_manager = surface_manager.mouse_manager();



	// mouse events
	mouse_manager.T_get_event<F_mouse_button_down_event>().T_push_back_listener(
		[](auto& e) {

			switch (((F_mouse_button_event&)e).button_flag())
			{
			case E_mouse_button_flag::LEFT:
				NCPP_INFO() << "mouse button down L";
				break;
			case E_mouse_button_flag::MIDDLE:
				NCPP_INFO() << "mouse button down M";
				break;
			case E_mouse_button_flag::RIGHT:
				NCPP_INFO() << "mouse button down R";
				break;
            case E_mouse_button_flag::NONE:
                NCPP_ASSERT() << "unknown mouse button down";
                break;
			}

		}
	);
	mouse_manager.T_get_event<F_mouse_button_up_event>().T_push_back_listener(
		[](auto& e) {

			switch (((F_mouse_button_event&)e).button_flag())
			{
			case E_mouse_button_flag::LEFT:
				NCPP_INFO() << "mouse button up L";
				break;
			case E_mouse_button_flag::MIDDLE:
				NCPP_INFO() << "mouse button up M";
				break;
			case E_mouse_button_flag::RIGHT:
				NCPP_INFO() << "mouse button up R";
				break;
            case E_mouse_button_flag::NONE:
                NCPP_ASSERT() << "unknown mouse button up";
                break;
			}

		}
	);
	mouse_manager.T_get_event<F_mouse_move_event>().T_push_back_listener(
		[](auto& e) {

			NCPP_INFO() << "mouse move " << ((F_mouse_move_event&)e).position_x() << " " << ((F_mouse_move_event&)e).position_y();

		}
	);



    surface_manager.T_run([](F_surface_manager* surface_manager_p){
        
        NCPP_INFO() << "update, surface manager: " << T_cout_value(surface_manager_p);
        
    });



	ncpp::pause_console();

	return 0;
}
