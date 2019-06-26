CFLAGS= -Llib
CLIBS= -lmingw32 -lSDL2 -lSDL2main -mwindows "lib/glew32.lib" -lopengl32 -lglu32
EXEC=PiwelGameEngine.exe
SRC = src
TEMPDIR = bin/objs
FILES = main.cpp init/windowkernel.cpp
SOURCES = $(patsubst %,$(SRC)/%,$(FILES))
OBJECTS = $(patsubst %.cpp,$(TEMPDIR)/%.o,$(FILES))
all: $(EXEC)
	
 PiwelGameEngine.exe: $(OBJECTS)
	g++ $(CFLAGS) -o bin/Release/$@ $(OBJECTS) $(CLIBS)
	./bin/Release/PiwelGameEngine.exe
$(TEMPDIR)/%.o: $(SRC)/%.cpp
	g++ -Wall -g -Iinclude -c -o $@ $<
clean:
	rm -rf bin/objs/*.o
	rm -rf bin/objs/init/*.o