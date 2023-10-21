#include <nsurface/surface_base.hpp>



namespace nsurface {

	I_surface::I_surface(F_surface_manager* surface_manager_p, const F_surface_desc& desc) :
		desc_(desc),
		manager_p_(surface_manager_p)
	{



	}
	I_surface::~I_surface() {



	}

}