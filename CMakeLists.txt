cmake_minimum_required(VERSION 3.1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(RETRoNES)

# Add sources
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Specify include Directory
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(RETRoNES ${SOURCES})
if (WIN32)
    target_link_libraries(RETRoNES -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lwinmm -lstdc++fs)
endif (WIN32)

if (UNIX)
    target_link_libraries(RETRoNES -lX11 -lGL -lpthread -lpng -lasound -lstdc++fs)
endif (UNIX)

set_property(TARGET RETRoNES PROPERTY CXX_STANDARD 17)
set_property(TARGET RETRoNES PROPERTY CXX_STANDARD_REQUIRED ON)
