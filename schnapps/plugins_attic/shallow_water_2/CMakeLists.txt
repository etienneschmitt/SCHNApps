project(plugin_shallow_water_2
	LANGUAGES CXX
)

find_package(cgogn_io REQUIRED)
find_package(cgogn_modeling REQUIRED)
find_package(cgogn_topology REQUIRED)
find_package(cgogn_geometry REQUIRED)


set(HEADER_FILES
	dll.h
	shallow_water.h
	dialog_shallow_water.h
)

set(SOURCE_FILES
	shallow_water.cpp
	dialog_shallow_water.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
target_compile_definitions(${PROJECT_NAME} PRIVATE "-DSCHNAPPS_PLUGIN_SHALLOW_WATER_2_DLL_EXPORT")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CGOGN_SOURCE_DIR}>
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
	schnapps_core
	${cgogn_core_LIBRARIES}
	${cgogn_io_LIBRARIES}
	${cgogn_modeling_LIBRARIES}
	${cgogn_topology_LIBRARIES}
	${cgogn_geometry_LIBRARIES}
	${Qt5Core_LIBRARIES}
	${Qt5Widgets_LIBRARIES}
)

set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER plugins)
