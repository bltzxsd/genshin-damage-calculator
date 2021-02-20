# Ganyu-Damage-Calculator

This is a practice project that does nothing (currently)

## Dependencies

`make` and `minGW` / `clang` (if on windows)

## how to build

Why would you want to do this? but either way
this only works if using GNU/Linux

### Donwloading the repository

```shell
git clone https://github.com/b1issard/genshin-damage-calculator.git
```

### Linux way

```shell
cd genshin-damage-calculator/
make
```

### Windows way

If on Windows, you have to compile it manually unfortunately :
I would recommend you to install the [LLVM toolchain 64bit](<https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/LLVM-11.0.0-win64.exe>) for this since MSVC needs VS20XX and MinGW is dumb ( i couldnt get it to compile successfully on win but it worked on wsl ) 

**UPDATE: compiling on windows is a nono since it doesn't let me write unsafe code (auto get -> second.x) : (std::unordered_map<int, Talent>::const_iterator get -> second.x)**

**( you can also run linux way if you have WSL :) )**

```shell
clang++ -std=c++17 -Wall -O2 -Ofast *.cpp -o dmg_calc.exe
```
