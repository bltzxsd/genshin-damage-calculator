CC:= g++
CCFLAGS:= -std=c++17 -Wall -O2 -Ofast
COMPILEFLAG:= -c
LINKFLAG:= -o
INCLUDE:= genshin_damage_calculator/include

a.out: main.o inputhandler.o weaponlist.o weapon_level.o
	$(CC) $(CCFLAGS) main.o inputhandler.o weaponlist.o weapon_level.o $(LINKFLAG) a.out

main.o: main.cpp  
	$(CC) $(CCFLAGS) $(COMPILEFLAG) main.cpp

inputhandler.o: inputhandler.cpp $(INCLUDE)/inputhandler.h
	$(CC) $(CCFLAGS) $(COMPILEFLAG) inputhandler.cpp

weaponlist.o: weaponlist.cpp $(INCLUDE)/inputhandler.h $(INCLUDE)/weapon_level.h $(INCLUDE)/weaponlist.h
	$(CC) $(CCFLAGS) $(COMPILEFLAG) weaponlist.cpp

weapon_level.o: weapon_level.cpp $(INCLUDE)/weapon_level.h
	$(CC) $(CCFLAGS) $(COMPILEFLAG) weapon_level.cpp

clean: 
	rm -f *.o 

cleanall:
	rm -f a.out *.o linux_exec program.exe