CC:= clang++
CXXFLAGS:= -std=c++17 -Wall -ggdb -g3
LDFLAGS:= -o
INCLUDE:= ${CURDIR}/include
OBJDIR:= ${CURDIR}/objs
OUTPUT:=.out

all: main.o inputhandler.o weapon_stats.o artifact_value.o artifact_set.o ganyu_level.o
	$(CC) $(CXXFLAGS) main.o inputhandler.o weapon_stats.o artifact_value.o artifact_set.o ganyu_level.o $(LDFLAGS) a$(OUTPUT)

main.o: main.cpp 
	$(CC) $(CXXFLAGS) -c main.cpp

inputhandler.o: inputhandler.cpp $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c inputhandler.cpp

weapon_stats.o: weapon_stats.cpp $(INCLUDE)/weapon_level.h $(INCLUDE)/weapon_stats.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c weapon_stats.cpp

artifact_value.o: artifact_value.cpp $(INCLUDE)/artifact_value.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c artifact_value.cpp

artifact_set.o: artifact_set.cpp $(INCLUDE)/artifact_set.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c artifact_set.cpp 

ganyu_level.o: ganyu_level.cpp $(INCLUDE)/ganyu_level.h $(INCLUDE)/inputhandler.h 
	$(CC) $(CXXFLAGS) -c ganyu_level.cpp

.PHONY: clean cleanall
clean: 
	rm -f *.o 

cleanall:
	rm -f a$(OUTPUT) *.o  dmg_calculator.exe