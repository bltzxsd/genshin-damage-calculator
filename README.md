# genshin-damage-calculator

this is a practice project that does nothing (currently)

## Dependencies

`make` and `minGW` / `clang` (if on windows)

## how to build

why would you want to do this? but either way
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

if on windows, you have to compile it manually unfortunately
**( you can also run linux way if you have WSL :) )**

```shell
g++ -std=c++17 -Wall -O2 -Ofast *.cpp -o dmg_calc.exe
```
