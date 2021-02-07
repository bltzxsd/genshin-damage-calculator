CC:= clang++
CXXFLAGS:= -std=c++17 -Wall -O2 -Ofast
LDFLAGS:= -o
INCLUDE:= ${CURDIR}/include
OBJDIR:= ${CURDIR}/objs
OUTPUT:=.out

all: main.o inputhandler.o weapon_stats.o artifact_value.o
	$(CC) $(CXXFLAGS) main.o inputhandler.o weapon_stats.o artifact_value.o $(LDFLAGS) a$(OUTPUT)

main.o: main.cpp 
	$(CC) $(CXXFLAGS) -c main.cpp

inputhandler.o: inputhandler.cpp $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c inputhandler.cpp

weapon_stats.o: weapon_stats.cpp $(INCLUDE)/weapon_level.h $(INCLUDE)/weapon_stats.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c weapon_stats.cpp

artifact_value.o: artifact_value.cpp $(INCLUDE)/artifact_value.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c artifact_value.cpp

.PHONY: clean cleanall
clean: 
	rm -f *.o 

cleanall:
	rm -f a$(OUTPUT) *.o  dmg_calculator.exe