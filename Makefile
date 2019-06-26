CFLAGS= -Llib
CLIBS= -lmingw32 -lSDL2 -lSDL2main -mwindows "lib/glew32.lib" -lopengl32 -lglu32

SRC = src
TEMPDIR = bin/objs
FILES = main.cpp init/windowkernel.cpp
SOURCES = $(patsubst %,$(SRC)/%,$(FILES))
OBJECTS = $(patsubst %.cpp,$(TEMPDIR)/%.o,$(FILES))

NAMEAPP = PiwelGameCreator
VERSION = indev-1

EXEC=$(NAMEAPP)_$(VERSION).exe

all: clean $(EXEC)
	
$(NAMEAPP)_$(VERSION).exe: $(OBJECTS)
	g++ $(CFLAGS) -o bin/Release/$@ $(OBJECTS) $(CLIBS)
	./bin/Release/$(NAMEAPP)_$(VERSION).exe
$(TEMPDIR)/%.o: $(SRC)/%.cpp
	g++ -Wall -g -Iinclude -o $@ -c $<
clean:
	rm -rf bin/objs/*.o
	rm -rf bin/objs/init/*.o