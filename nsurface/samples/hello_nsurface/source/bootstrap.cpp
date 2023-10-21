
#include <nsurface/.hpp>

using namespace nsurface;



int main() {
	
	F_windows_surface surface = F_surface_desc {
	
		// title
		L"Hello NSurface " + NCPP_TEXT(NSURFACE_VERSION_STR)
	
	};

    ncpp::pause_console();

	return 0;
}
