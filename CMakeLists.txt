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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static")

add_executable(RETRoNES ${SOURCES})
target_link_libraries(RETRoNES ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set_property(TARGET RETRoNES PROPERTY CXX_STANDARD 17)
set_property(TARGET RETRoNES PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(RETRoNES user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs)
