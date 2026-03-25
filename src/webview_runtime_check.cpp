#include <windows.h>
#include <shellapi.h>

void ensure_webview2_runtime() {
    // Try to load the WebView2Loader DLL
    HMODULE h = LoadLibraryA("WebView2Loader.dll");

    if (h == nullptr) {
        MessageBoxA(
            nullptr,
            "WebView2 Runtime is required but not installed.\n\n"
            "Click OK to download it.",
            "Missing Dependency",
            MB_OK | MB_ICONWARNING
        );

        ShellExecuteA(
            nullptr,
            "open",
            "https://go.microsoft.com/fwlink/p/?LinkId=2124703",
            nullptr,
            nullptr,
            SW_SHOWNORMAL
        );

        exit(1);
    }

    // If loaded, free it again
    FreeLibrary(h);
}