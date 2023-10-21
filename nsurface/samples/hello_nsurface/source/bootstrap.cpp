
#include <nsurface/.hpp>

using namespace nsurface;



int main() {
	
	F_surface_manager surface_manager;

	F_surface* surface_p = surface_manager.create_surface(
		F_surface_desc {
	
			// title
			eastl::wstring(L"Hello NSurface ") + NCPP_TEXT(NSURFACE_VERSION_STR)
	
		}
	);

	while (surface_p->is_running()) {

		if (!surface_manager.check_input()) {



		}

	}

    ncpp::pause_console();

	return 0;
}
