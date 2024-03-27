
#include <nsurface/.hpp>

using namespace nsurface;



NCPP_ENTRY_POINT() {
	
	F_surface_manager surface_manager;



	// create surface
	F_surface* surface_p = surface_manager.create_surface(
		F_surface_desc {
	
			// title
			.title = ncpp::G_text(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR)
	
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

            F_vector2_i32 size = ((F_surface_resizing_event&)e).size();

			NCPP_INFO() << "resizing " << size.x << " " << size.y;

		}
	);
	surface_p->T_get_event<F_surface_post_resize_event>().T_push_back_listener(
		[](auto& e) {

            F_vector2_i32 size = ((F_surface_post_resize_event&)e).size();

            NCPP_INFO() << "post resize " << size.x << " " << size.y;

		}
	);

	surface_p->T_get_event<F_surface_moving_event>().T_push_back_listener(
		[](auto& e) {

            F_vector2_i32 offset = ((F_surface_moving_event&)e).offset();

			NCPP_INFO() << "moving " << offset.x << " " << offset.y;

		}
	);
	surface_p->T_get_event<F_surface_post_move_event>().T_push_back_listener(
		[](auto& e) {

            F_vector2_i32 offset = ((F_surface_post_move_event&)e).offset();

			NCPP_INFO() << "post move " << offset.x << " " << offset.y;

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

            F_vector2_i32 position = ((F_mouse_move_event&)e).position();

			NCPP_INFO() << "mouse move " << position.x << " " << position.y;

		}
	);



    surface_manager.T_run([](F_surface_manager& surface_manager){
        
        NCPP_INFO() << "update, surface manager: " << T_cout_value(&surface_manager);
        
    });



	ncpp::pause_console();

	return 0;
}
