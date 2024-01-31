<img src="images/logo.png" alt="Title" width="1200">

RETRoNES
=============

<br />

A basic NES emulator written in C++ for learning purposes.

NOTE: The current version of the emulator does not include sound and only supports player one.

The emulator makes use of OneLoneCoder's OLC Pixel Game Engine:

https://github.com/OneLoneCoder/olcPixelGameEngine

## Installation

You'll need to install the required build tools and libraries

On Ubuntu 20.04/22.04 and distros based on each:
```
$ sudo apt update
$ sudo apt install build-essential libgl-dev libx11-dev libxi-dev libglu1-mesa-dev libpng-dev
```

## Compiling

You'll need:
* C++17 compliant compiler
* CMake

```
$ git clone https://github.com/jmrossi98/nes_emulator
$ cd nes_emulator
$ mkdir build/ && cd build/
$ cmake ..
$ make -j$(nproc)
```

## Running

Specify the ROM path

```
$ ./RETRoNES ~/Games/Super Mario Bros.nes
```

## Controller

To end emulation, press ESC.

 Button        | Mapped to
 --------------|-------------
 Start         | Enter
 Select        | Shift
 A             | X
 B             | Z
 Up            | ↑
 Down          | ↓
 Left          | ←
 Right         | →
