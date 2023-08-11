
set(NSURFACE_CXX_STANDARD 20 CACHE STRING "CXX Standard")
set(CMAKE_CXX_STANDARD ${NSURFACE_CXX_STANDARD})

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-fpermissive)
endif()



# nsurface options



# nsurface target configure file
configure_file(source/nsurface/.config ${CMAKE_CURRENT_BINARY_DIR}/built_source/nsurface/config.hpp)



set(NSURFACE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source" PARENT_SCOPE)



# nsurface target source files
file(GLOB source_files
    "source/nsurface/*.cpp"
    "source/nsurface/*.hpp"
)
source_group("source\\nsurface" FILES ${source_files})



# Create nsurface target
add_library(nsurface STATIC
    ${source_files}
)



# nsurface target settings
set_target_properties(nsurface
    PROPERTIES 
        FOLDER "nsurface"
)
target_link_libraries(nsurface
    PUBLIC 
        ncpp
)
target_include_directories(nsurface
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_CURRENT_BINARY_DIR}/built_source
)

add_dependencies(nsurface ncpp)



# sub directories
add_subdirectory(samples)



