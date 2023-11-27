
#include <nsurface/.hpp>

using namespace nsurface;



int main() {
	
	F_surface_manager surface_manager;



	// create surface
	F_surface* surface_p = surface_manager.create_surface(
		F_surface_desc {
	
			// title
			ncpp::F_text(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR)
	
		}
	);



	// surface events
	surface_p->T_get_event<F_surface_destroy_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "surface is destroyed" << std::endl;

		}
	);

	surface_p->T_get_event<F_surface_resizing_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "resizing " << ((F_surface_resizing_event&)e).width() << " " << ((F_surface_resizing_event&)e).height() << std::endl;

		}
	);
	surface_p->T_get_event<F_surface_post_resize_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "post resize " << ((F_surface_post_resize_event&)e).width() << " " << ((F_surface_post_resize_event&)e).height() << std::endl;

		}
	);

	surface_p->T_get_event<F_surface_moving_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "moving " << ((F_surface_moving_event&)e).offset_x() << " " << ((F_surface_moving_event&)e).offset_y() << std::endl;

		}
	);
	surface_p->T_get_event<F_surface_post_move_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "post move " << ((F_surface_post_move_event&)e).offset_x() << " " << ((F_surface_post_move_event&)e).offset_y() << std::endl;

		}
	);



	// get mouse manager
	auto& mouse_manager = surface_manager.mouse_manager();



	// mouse events
	mouse_manager.T_get_event<F_mouse_button_down_event>().T_push_back_listener(
		[](auto& e) {

			switch (((I_mouse_button_event&)e).button_flag())
			{
			case E_mouse_button_flag::LEFT:
				std::cout << "mouse button down L" << std::endl;
				break;
			case E_mouse_button_flag::MIDDLE:
				std::cout << "mouse button down M" << std::endl;
				break;
			case E_mouse_button_flag::RIGHT:
				std::cout << "mouse button down R" << std::endl;
				break;
			}

		}
	);
	mouse_manager.T_get_event<F_mouse_button_up_event>().T_push_back_listener(
		[](auto& e) {

			switch (((I_mouse_button_event&)e).button_flag())
			{
			case E_mouse_button_flag::LEFT:
				std::cout << "mouse button up L" << std::endl;
				break;
			case E_mouse_button_flag::MIDDLE:
				std::cout << "mouse button up M" << std::endl;
				break;
			case E_mouse_button_flag::RIGHT:
				std::cout << "mouse button up R" << std::endl;
				break;
			}

		}
	);
	mouse_manager.T_get_event<F_mouse_move_event>().T_push_back_listener(
		[](auto& e) {

			std::cout << "mouse move " << ((F_mouse_move_event&)e).position_x() << " " << ((F_mouse_move_event&)e).position_y() << std::endl;

		}
	);



    surface_manager.T_run([](F_surface_manager* surface_manager_p){
        
        std::cout << surface_manager_p << std::endl;
        
    });



	ncpp::pause_console();

	return 0;
}
