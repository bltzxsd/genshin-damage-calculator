CC:= clang++
CXXFLAGS:= -std=c++17 -Wall -O2 -Ofast
COMPILEFLAG:= -c
LDFLAGS:= -o
INCLUDE:= ${CURDIR}/include
OUTPUT:=.out

output: main.o inputhandler.o weaponlist.o weapon_level.o
	$(CC) $(CXXFLAGS) main.o inputhandler.o weaponlist.o weapon_level.o $(LDFLAGS) program$(OUTPUT)

main.o: main.cpp  
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) main.cpp

inputhandler.o: inputhandler.cpp $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) inputhandler.cpp

weaponlist.o: weaponlist.cpp $(INCLUDE)/inputhandler.h $(INCLUDE)/weapon_level.h $(INCLUDE)/weaponlist.h
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) weaponlist.cpp

weapon_level.o: weapon_level.cpp $(INCLUDE)/weapon_level.h
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) weapon_level.cpp

winoutput: main.o inputhandler.o weaponlist.o weapon_level.o
	$(CC) $(CXXFLAGS) main.o inputhandler.o weaponlist.o weapon_level.o $(LDFLAGS) program.exe

.PHONY: clean cleanall
clean: 
	rm -f *.o 

cleanall:
	rm -f program$(OUTPUT) *.o 