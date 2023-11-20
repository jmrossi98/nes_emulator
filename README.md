<img src="images/logo.png" alt="Title" width="1200">

RETRoNES
=============

<br />

A basic NES emulator written in C++ for learning purposes.

NOTE: The current version of the emulator does not include sound and only supports player one.

The emulator makes use of OneLoneCoder's OLC Pixel Game Engine:

https://github.com/OneLoneCoder/olcPixelGameEngine

## Compiling

Compiled with g++ 13.2 as C++17

On Windows 10:
```
$ git clone https://github.com/jmrossi98/nes_emulator
$ cd nes_emulator
$ make build
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
