#include <nsurface/macos/surface_manager_backend.h>

#include <nsurface/macos/surface_manager.hpp>



namespace nsurface {

    namespace internal {

        void macos_surface_manager_init(F_surface_manager* surface_manager_p) {
            
            void*& handle = macos_surface_manager_inject_handle(surface_manager_p);
            
            F_surface_manager_backend* backend_p = [F_surface_manager_backend sharedApplication];
            
            handle = backend_p;

        }

        void macos_surface_manager_loop(F_surface_manager* surface_manager_p) {
            
            void*& handle = macos_surface_manager_inject_handle(surface_manager_p);
            
            F_surface_manager_backend* backend_p = reinterpret_cast<F_surface_manager_backend*>(handle);
            
            [backend_p run];

        }
        
        void macos_surface_manager_release(F_surface_manager* surface_manager_p) {
            
            void*& handle = macos_surface_manager_inject_handle(surface_manager_p);
            
            F_surface_manager_backend* backend_p = reinterpret_cast<F_surface_manager_backend*>(handle);
            
            
            
            handle = 0;

        }

    }
    
}



 @implementation F_surface_manager_backend



 @end
