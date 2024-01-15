#include <nsurface/surface_base.hpp>



namespace nsurface {

	A_surface::A_surface(const F_surface_desc& desc) :
		desc_(desc),

		destroy_event_(as_current_platform()),

		post_resize_event_(as_current_platform()),
		resizing_event_(as_current_platform()),

		post_move_event_(as_current_platform()),
		moving_event_(as_current_platform())
	{



	}
	A_surface::~A_surface() {



	}

}