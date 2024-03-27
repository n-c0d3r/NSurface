#include <nsurface/surface_base.hpp>



namespace nsurface {

	A2_surface::A2_surface(const F_surface_desc& desc) :
		desc_(desc),

		destroy_event_(as_current_platform()),
		destroy_request_event_(as_current_platform()),
		resize_event_(as_current_platform()),
		move_event_(as_current_platform())
	{



	}
	A2_surface::~A2_surface() {



	}

}