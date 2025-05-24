# EasyLearner

EasyLearner is a Qt-based C++ application designed to manage and learn topics through interactive content management modules.

## Features

- Modular topic management system  
- Support for topic definitions and questions  
- Intuitive UI built with Qt Widgets  

## Requirements

- Qt 5.15.2 (tested with mingw81_64)  
- C++17 compatible compiler (MinGW or MSVC)  
- CMake for build system  
- CLion or other C++ IDE recommended  

## Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/without-eyes/EasyLearner
   cd EasyLearner
   ```

2. Configure and build with CMake:

   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. Run the application:

   * On Windows, run the generated executable in the `build` folder.

## Project Structure

* `src/` — Source code, including core application
* `include/` — Header files
* `assets/` — Icons and sounds

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.
