CFLAGS= -Llib
CLIBS= -lmingw32 -lSDL2main -lSDL2 -mwindows
EXEC=PiwelGameEngine.exe
SRC=$(wildcard src/*.cpp src/init/*.cpp)
OBJ=${SRC:.cpp=.o}
all: $(EXEC)
	
PiwelGameEngine.exe: ${OBJ}
	g++ $(CFLAGS) -o bin/Release/$@ bin/objs/$^ $(CLIBS)
	./bin/Release/PiwelGameEngine.exe
%.o: %.cpp
	g++ -Wall -g -Iinclude -c -o bin/objs\$@ $<