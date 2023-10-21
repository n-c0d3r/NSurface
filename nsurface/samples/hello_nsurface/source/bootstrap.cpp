
#include <nsurface/.hpp>

using namespace nsurface;



int main() {
	
	F_windows_surface surface = F_surface_desc {
	
		// title
		eastl::wstring(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR),

		// width
		1024,		
		// height
		1024,

		// offset x
		0, 
		// offset y
		0
	
	};

	while (true) {

		if (!surface.check_input()) {



		}

	}

    ncpp::pause_console();

	return 0;
}
