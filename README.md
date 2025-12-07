![Build & Test](https://github.com/pooyasoleymani/Financial-Analytics-Tool/actions/workflows/ci.yml/badge.svg) ![Docs](https://img.shields.io/badge/docs-online-blue?link=https://pooyasoleymani.github.io/Financial-Analytics-Tool/) ![Benchmarks](https://img.shields.io/badge/benchmarks-passing-brightgreen)
  ![Release](https://img.shields.io/github/v/release/pooyasoleymani/Financial-Analytics-Tool) ![Coverage](https://img.shields.io/codecov/c/github/pooyasoleymani/Financial-Analytics-Tool)
 

# Cross‑Platform Financial Analytics Tool
# Hi, I'm Pooya 👋

- 💼 Software Engineer 
- 📊 Expert in C++ and Pyhton Programming
- 💻 Building template(training) cross‑platform C++/Python projects with CI/CD
- 📈 Focused on performance benchmarking & professional project presentation


## Overview
Financial-Analytics-Tool is a modular C++ application designed for **financial data analysis and visualization** 
Backend (C++): High‑performance analytics (e.g., tax calculations, VAT compliance, benchmarks).

- Frontend (PyQt5): User‑friendly GUI for accountants and analysts.

- Bridge: Expose C++ functions to Python via a shared library (.dll/.so) using pybind11.  q

It demonstrates modern C++ practices including:
- Modular CMake structure
- Thread safety with `std::mutex` and `std::atomic`
- Smart pointers for memory safety
- Automated testing with Catch2 + CTest
- Cross‑platform deployment (Windows, Linux, macOS)
- Performance benchmarking with Google Benchmark and Intel IPP
- PyQt5 GUI for interactive reports

---

## 📂 Project Structure
```

Financial-Analytics-Tool/
│   README.md
├───.github 
│   └───workflows
├───bindings
│       pybind_module.cpp
├───cpp_backend
│   ├───apps
│   │       cli_app.cpp
│   ├───benchmarks
│   │       bench_core.cpp
│   ├───externals
│   │   ├───benchmark
│   │   └───Catch2
│   ├───include
│   │       analytics.hpp.hpp
│   ├───src
│   │       analytics.cpp.cpp      
│   └───tests
│           CMakeLists.txt
│           test_core.cpp    
└───pyqt_frontend
    │   main.py
    │   requirements.txt
    └───ui
        ui_mainwindow.py
        ui_mainwindow.ui
```

## ⚙️ Build Instructions

### Prerequisites
- CMake ≥ 3.16
- C++17 compiler (MSVC, GCC, or Clang)
- Catch2 (for testing)
- Google Benchmark (for performance)
- PyQt5 (for GUI)

### Build
```bash
mkdir build && cd build
cmake .. -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Running Tests

```bash
ctest --output-on-failure
```

- Run only unit tests:

```bash
ctest -L unit
```


### Benchmarks

```bash
./benchmarks/bench_core
```

### 📦 Packaging
Generate installers with CPack:

```bash
cpack
```
- Windows → .zip or NSIS installer
- Linux → .deb or .rpm
- macOS → .dmg