#include <nsurface/macos/surface_manager_backend.h>

#include <nsurface/macos/surface_manager.hpp>



namespace nsurface {

    namespace internal {

        void macos_surface_manager_init(F_surface_manager* surface_manager_p) {
            
            void*& handle = macos_surface_manager_inject_handle(surface_manager_p);

        }

        void macos_surface_manager_loop(F_surface_manager* surface_manager_p) {
            
            void*& handle = macos_surface_manager_inject_handle(surface_manager_p);

        }

    }
    
}



 @implementation F_surface_manager_backend



 @end
