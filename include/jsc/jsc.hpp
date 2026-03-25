#pragma once
#include <string>

namespace jshtml {

/// Load an HTML file into a std::string
std::string load_file(const std::string& path);

/// Load an HTML file into a native webview window
void load_into_webview(const std::string& path,
                       const std::string& title = "Js-Html-Loader");

}