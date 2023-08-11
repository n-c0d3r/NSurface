
# nsurface.samples.first_sample target source files
file(GLOB source_files
    "source/*.cpp"
    "source/*.hpp"
)
source_group("source" FILES ${source_files})



# Create nsurface.samples.first_sample target
add_executable(nsurface.samples.first_sample
    ${source_files}
)



# nsurface.samples.first_sample target settings
set_target_properties(nsurface.samples.first_sample
    PROPERTIES 
        FOLDER "nsurface/samples"
        PROJECT_LABEL "first_sample"
)
target_link_libraries(nsurface.samples.first_sample
    PRIVATE nsurface
)
target_include_directories(nsurface.samples.first_sample
    PUBLIC 
        nsurface
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)



# nsurface.samples.first_sample target dependencies
add_dependencies(nsurface.samples.first_sample 
    nsurface
)