#include <nsurface/surface_manager_base.hpp>
#include <nsurface/surface.hpp>
#include <nsurface/surface_manager.hpp>



namespace nsurface {

	A_surface_manager::A_surface_manager()
	{



	}
	A_surface_manager::~A_surface_manager() {

		release_surfaces_internal();

	}



    b8 A_surface_manager::is_there_any_surface_running() const {
        
        for (auto it = surface_p_list_.begin(); it != surface_p_list_.end(); ++it) {

            if((*it)->is_running()) {

                return true;
            }

        }

        return false;
    }



    void A_surface_manager::run_internal(){
        
        as_current_platform_p()->run_internal();
        
    }



	void A_surface_manager::release_surfaces_internal() {

		for (auto it = surface_p_list_.begin(); it != surface_p_list_.end();) {

			auto next = it;
			++next;

			delete_surface(*it);

			it = next;

		}

	}



	TK2_valid<F2_surface> A_surface_manager::create_surface(const F_surface_desc& desc) {

		auto unique_surface_p = TU2_valid<F2_surface>::T_make(desc);
		auto surface_p = unique_surface_p.keyed();

		surface_p_list_.push_back(std::move(unique_surface_p));

        surface_p->iterator_ = --surface_p_list_.end();

		return surface_p;
	}
	void A_surface_manager::delete_surface(TK2_valid<F2_surface> surface_p) {

		surface_p_list_.erase(surface_p->iterator_);

	}

}
