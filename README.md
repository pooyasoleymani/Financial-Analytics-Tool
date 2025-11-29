# MyProject – Cross‑Platform Financial Analytics Tool

## Overview
MyProject is a modular C++ application designed for **financial data analysis and visualization**.  
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
MyProject/ 
├── src/ # Core libraries 
├── include/ # Public headers 
├── apps/ # CLI and GUI applications 
├── tests/ # Unit tests (Catch2) 
├── benchmarks/ # Performance benchmarks 
└── CMakeLists.txt


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