cmake_minimum_required(VERSION 3.16)
project(js_html_loader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------
# Include paths
# ---------------------------------------------------------
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/deps/webview/core/include
    "C:/WebView2SDK/build/native/include"
)

# ---------------------------------------------------------
# Library: jshtmlloader
# ---------------------------------------------------------
add_library(jshtmlloader STATIC
    src/js_html_loader.cpp
)

# Link required Windows libraries
target_link_libraries(jshtmlloader
    version
    shlwapi
)

# ---------------------------------------------------------
# Example executable
# ---------------------------------------------------------
add_executable(example
    examples/basic_view.cpp
)

target_link_libraries(example
    jshtmlloader
    version
    shlwapi
)