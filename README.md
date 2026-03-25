
---

# **JsC – The JavaScript + C++ HTML Runtime**

JsC is a lightweight C++ runtime for embedding modern HTML/CSS/JavaScript interfaces inside native applications.  
It uses **WebView2** under the hood and exposes a clean, minimal API for loading HTML, running JS, and building hybrid apps.

JsC is designed to be:

- **Portable** — works with MSYS2, MinGW, and CMake  
- **Minimal** — no frameworks, no heavy dependencies  
- **Modern** — full Chromium rendering via WebView2  
- **Flexible** — load HTML strings, files, or remote URLs  
- **Fast** — native window + hardware‑accelerated rendering  

---

## 🚀 Features

- Create native windows that render HTML/JS  
- Load HTML from strings, files, or URLs  
- Execute JavaScript from C++  
- Receive messages from JavaScript  
- Auto‑detect WebView2 runtime  
- Zero SDK required at runtime  
- Clean CMake integration  
- Works with your JsLib ecosystem  

---

## 📦 Installation

### **1. Clone the repository**

```bash
git clone https://github.com/<yourname>/JsC.git
cd JsC
```

### **2. Install MSYS2 UCRT64 toolchain**

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

### **3. Install CMake**

```bash
pacman -S mingw-w64-ucrt-x86_64-cmake
```

### **4. Install WebView2 SDK (compile‑time only)**

Download the NuGet package:

```
Microsoft.Web.WebView2.<version>.nupkg
```

Extract it to:

```
C:/WebView2SDK/
```

JsC expects the headers here:

```
C:/WebView2SDK/build/native/include
```

---

## 🛠️ Building JsC

From the project root:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

If successful, you’ll see:

```
[1/1] Linking CXX executable example.exe
```

---

## ▶️ Running the Example

Inside the `build` folder:

```bash
./example.exe
```

If the WebView2 **runtime** is missing, Windows will automatically prompt the user to install it.  
The **SDK is never required at runtime**.

---

## 📚 Using JsC in Your Project

### **1. Add JsC to your CMake project**

```cmake
add_subdirectory(js-c)
target_link_libraries(your_app PRIVATE jshtmlloader)
```

### **2. Include the header**

```cpp
#include <js_html_loader.hpp>
```

### **3. Create a window**

```cpp
JsC::View view("Hello JsC", 800, 600);
view.load_html("<h1>Hello from JsC!</h1>");
view.run();
```

---

## 🧩 API Overview

### **Create a window**

```cpp
JsC::View view("My App", 1024, 768);
```

### **Load HTML**

```cpp
view.load_html("<h1>Welcome to JsC</h1>");
```

### **Load a file**

```cpp
view.load_file("index.html");
```

### **Load a URL**

```cpp
view.navigate("https://example.com");
```

### **Run JavaScript**

```cpp
view.eval("console.log('Hello from C++')");
```

### **Receive messages from JS**

In JavaScript:

```js
chrome.webview.postMessage("ping");
```

In C++:

```cpp
view.on_message([](std::string msg) {
    std::cout << "JS says: " << msg << std::endl;
});
```

---

## 🧪 Troubleshooting

### **Missing WebView2 headers**
Ensure your CMakeLists.txt includes:

```
C:/WebView2SDK/build/native/include
```

### **Undefined reference to GetFileVersionInfoW**
Add:

```cmake
target_link_libraries(jshtmlloader version shlwapi)
```

### **Runtime missing**
Windows will prompt the user automatically.

---

## 🗂 Folder Structure

```
JsC/
 ├─ include/        # Public headers
 ├─ src/            # JsC implementation
 ├─ deps/           # WebView backend
 ├─ examples/       # Example apps
 ├─ CMakeLists.txt
 └─ build/          # Generated build files
```

---


