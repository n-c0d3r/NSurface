#include <nsurface/surface_manager_base.hpp>
#include <nsurface/surface.hpp>



namespace nsurface {

	I_surface_manager::I_surface_manager()
	{



	}
	I_surface_manager::~I_surface_manager() {

		release_surfaces_internal();

	}



	void I_surface_manager::release_surfaces_internal() {

		for (auto it = surface_p_list_.begin(); it != surface_p_list_.end();) {

			auto next = it;
			++next;

			delete_surface(*it);

			it = next;

		}

	}



	F_surface* I_surface_manager::create_surface(const F_surface_desc& desc) {

		F_surface* surface_p = new F_surface(reinterpret_cast<F_surface_manager*>(this), desc);

		surface_p_list_.push_back(surface_p);

		surface_p->iterator_ = --surface_p_list_.end();

		return surface_p;
	}
	void I_surface_manager::delete_surface(F_surface* surface_p) {

		surface_p_list_.erase(surface_p->iterator_);

		delete surface_p;

	}

}