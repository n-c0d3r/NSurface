
#include <nsurface/.hpp>

using namespace nsurface;



NCPP_ENTRY_POINT() {

    {

        F_surface_manager surface_manager;



        // create surface
        TK_valid<F_surface> surface_p = surface_manager.create_surface(
            F_surface_desc{

                // title
                .title = ncpp::G_text(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR)

            }
        );



        // surface events
        surface_p->T_get_event<F_surface_destroy_event>().T_push_back_listener(
            [](auto &e) {

                NCPP_INFO() << "surface is destroyed";

            }
        );
        surface_p->T_get_event<F_surface_resize_event>().T_push_back_listener(
            [](auto &e) {

                F_vector2_i size = ((F_surface_resize_event &) e).size();

                NCPP_INFO() << "surface is resized " << size.x << " " << size.y;

            }
        );
        surface_p->T_get_event<F_surface_move_event>().T_push_back_listener(
            [](auto &e) {

                F_vector2_i offset = ((F_surface_move_event &) e).offset();

                NCPP_INFO() << "surface is moved " << offset.x << " " << offset.y;

            }
        );



		// get keyboard
		auto& keyboard = surface_manager.keyboard();

		// keyboard events
		keyboard.T_get_event<F_key_down_event>().T_push_back_listener(
			[](auto &e) {

				if(((F_key_down_event&)e).keycode() == E_keycode::A)
			  		NCPP_INFO() << "A key pressed";

			}
		);
		keyboard.T_get_event<F_text_character_event>().T_push_back_listener(
			[](auto &e) {

				NCPP_WINFO() << ((F_text_character_event&)e).text_character();
			}
		);



        // get mouse
        auto& mouse = surface_manager.mouse();

        // mouse events
        mouse.T_get_event<F_mouse_button_down_event>().T_push_back_listener(
            [&](auto &e) {

                switch (((F_mouse_button_event &) e).button_flag()) {
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
        mouse.T_get_event<F_mouse_button_up_event>().T_push_back_listener(
            [&](auto &e) {

                switch (((F_mouse_button_event &) e).button_flag()) {
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
        mouse.T_get_event<F_mouse_move_event>().T_push_back_listener(
            [&](auto &e) {

                F_vector2_i position = mouse.position();

                NCPP_INFO() << "mouse move " << position.x << " " << position.y;

            }
        );


        surface_manager.T_run(
            [](F_surface_manager &surface_manager) {
            }
        );

    }



	ncpp::pause_console();

	return 0;
}
