#include <nsurface/macos/surface_backend.h>

#include <nsurface/macos/surface.hpp>



namespace nsurface {

    namespace internal {

        void macos_surface_create_window(F2_surface* surface_p){

            void*& handle = macos_surface_inject_handle(surface_p);

            

            if (handle) {

                surface_inject_is_running(surface_p) = true;

            }

        }
        void macos_surface_release_window(F2_surface* surface_p){

            void*& handle = macos_surface_inject_handle(surface_p);
            
            if (handle) {



            }
            
            handle = 0;
            surface_inject_is_running(surface_p) = false;

        }



        void macos_surface_set_visibility(F2_surface* surface_p, E_surface_visibility visibility){


            
        }

        void macos_surface_set_offset(F2_surface* surface_p, int offset_x, int offset_y){


            
        }
        void macos_surface_resize(F2_surface* surface_p, int width, int height){


            
        }
        void macos_surface_set_rect(F2_surface* surface_p, int offset_x, int offset_y, int width, int height){


            
        }

    }

}
