# genshin-damage-calculator
this is a practice project that does nothing (currently)

## Dependencies 
```make```

## how to build 
why would you want to do this? but either way 
this only works if using GNU/Linux
```shell
cd genshin-damage-calculator/
make
```
if on windows, you have to compile it manually unfortuantely
```shell
g++ -std=c++17 -Wall -O2 -Ofast main.cpp inputhandler.cpp weaponlist.cpp weapon_level.cpp -o dmg_calculator.exe
```
