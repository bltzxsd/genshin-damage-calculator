CC:= clang++
CXXFLAGS:= -std=c++17 -Wall -O2 -Ofast
COMPILEFLAG:= -c
LDFLAGS:= -o
INCLUDE:= ${CURDIR}/include
OBJDIR:= ${CURDIR}/obj
OUTPUT:=.out

all: main.o inputhandler.o weapon_stats.o 
	$(CC) $(CXXFLAGS) main.o inputhandler.o weapon_stats.o $(LDFLAGS) a$(OUTPUT)

main.o: main.cpp  
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) main.cpp

inputhandler.o: inputhandler.cpp $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) inputhandler.cpp

weapon_stats.o: weapon_stats.cpp $(INCLUDE)/inputhandler.h $(INCLUDE)/weapon_level.h $(INCLUDE)/weapon_stats.h
	$(CC) $(CXXFLAGS) $(COMPILEFLAG) weapon_stats.cpp

.PHONY: clean cleanall
clean: 
	rm -f *.o 

cleanall:
	rm -f a$(OUTPUT) *.o  dmg_calculator.exe