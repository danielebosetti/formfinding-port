# formfinding-cmake

Build for form-finding based on VisualStudio2017 and vcpkg

## To build:

Install Microsoft Visual Studio 2017 Community

Install vcpkg from https://github.com/Microsoft/vcpkg

Install the required packages:
```
vcpkg install eigen3:x64-windows
vcpkg install glm:x64-windows
vcpkg install freeglut:x64-windows

Then the project can be built in VisualStudio
