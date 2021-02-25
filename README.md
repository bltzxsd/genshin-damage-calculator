# Ganyu-Damage-Calculator

[![CodeFactor](https://www.codefactor.io/repository/github/b1issard/genshin-damage-calculator/badge)](https://www.codefactor.io/repository/github/b1issard/genshin-damage-calculator)

This is a practice project that does nothing (currently)

**much ❤️ to [Honey Impact](<https://genshin.honeyhunterworld.com/>) for the data and the [Genshin Wiki](<https://genshin-impact.fandom.com/wiki/Genshin_Impact_Wiki>) for the DMG calculation formulae!!!**

## Dependencies

`make` and `minGW` / `clang` (if on windows)

## how to build

Why would you want to do this? but either way
this only works if using GNU/Linux

### Donwloading the repository

```shell
git clone https://github.com/b1issard/genshin-damage-calculator.git
```

### Linux

```shell
cd genshin-damage-calculator/
make
```

### Windows

If on Windows, you can get the binary or build it manually :

I would recommend you to install the [LLVM toolchain 64bit](<https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/LLVM-11.0.0-win64.exe>)
or [MinGW](<https://sourceforge.net/projects/mingw-w64/>). I used Clang simply because its already available directly on Windows.

```shell
clang++ -std=c++17 -Wall -O3 -Ofast -pedantic -static *.cpp -o dmg_calc.exe
```
