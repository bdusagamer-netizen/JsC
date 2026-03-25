#include <js_html_loader.hpp>
#include <webview.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace jshtml {

std::string load_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open HTML file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void load_into_webview(const std::string& path, const std::string& title) {
    std::string html = load_file(path);

    webview::webview w(true, nullptr);
    w.set_title(title);
    w.set_size(800, 600, WEBVIEW_HINT_NONE);
    w.set_html(html);
    w.run();
}

}