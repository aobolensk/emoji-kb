# emoji-kb

### Requirements
- [CMake](https://cmake.org/download/)
- [Qt5](https://www.qt.io/download)

### Build and run

#### CMake

```console
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_PREFIX_PATH="/path/to/qt/"
$ cmake --build .
$ ./emoji-keyboard
```

#### QtCreator

1. Open QtCreator
1. `File > Open File or Project...` and select file CMakeLists.txt
1. Select at least one configuration option and press "Configure Project"
1. Wait until configuration is finished and press "Play" button (Ctrl + R)
