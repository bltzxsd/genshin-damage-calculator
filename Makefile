CC:= clang++
CXXFLAGS:= -std=c++17 -Wall -ggdb -g3
INCLUDE:= ${CURDIR}/include
OBJDIR:= ${CURDIR}/objs
OUTPUT:=.out

all: main.o inputhandler.o weapon_stats.o artifact_value.o artifact_set.o ganyu_level.o talent_level.o dmg_calculation.o attack_output.o
	$(CC) $(CXXFLAGS) main.o \
	inputhandler.o weapon_stats.o \
	artifact_value.o artifact_set.o \
	ganyu_level.o talent_level.o \
	attack_output.o dmg_calculation.o -o a$(OUTPUT)

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

talent_level.o: talent_level.cpp $(INCLUDE)/talent_level.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c talent_level.cpp

dmg_calculation.o: dmg_calculation.cpp $(INCLUDE)/dmg_calculation.h $(INCLUDE)/inputhandler.h
	$(CC) $(CXXFLAGS) -c dmg_calculation.cpp

attack_output.o: attack_output.cpp $(INCLUDE)/attack_output.h $(INCLUDE)/weapon_level.h $(INCLUDE)/artifact_set.h $(INCLUDE)/talent_level.h
	$(CC) $(CXXFLAGS) -c attack_output.cpp

.PHONY: clean cleanall
clean: 
	rm -f *.o *.obj

cleanall:
	rm -f a$(OUTPUT) *.o *.obj *.exe