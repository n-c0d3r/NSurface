#include <nsurface/windows/surface.hpp>



namespace nsurface {

#ifdef NCPP_WINDOWS_PLATFORM
	windows_surface::windows_surface() {



	}
	windows_surface::windows_surface(const style& src_style) :
		style_(src_style)
	{



	}
	windows_surface::~windows_surface() {



	}
#endif

}