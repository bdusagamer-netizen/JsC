cmake_minimum_required(VERSION 3.16)
project(JsC VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(JsC STATIC
    src/jsc.cpp
    include/jsc/jsc.hpp
)

target_include_directories(JsC
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(JsC
    PUBLIC
        version
        shlwapi
)

include(GNUInstallDirs)

install(TARGETS JsC
    EXPORT JsCTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT JsCTargets
    FILE JsCConfig.cmake
    NAMESPACE JsC::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/JsC
)