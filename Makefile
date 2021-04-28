CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU 
OPS=-O3

SRC_FILES=src/*.cpp
MAIN_FILE=main.cpp include/*.hpp
OUTPUT=-o bin/galaxy_simulation.o

build: 
	$(CC) $(MAIN_FILE) $(SRC_FILES) $(OUTPUT) $(LIBS) $(OPS)

run:
	bin/./galaxy_simulation.o
.PHONY: clean
clean:
	rm -rf bin/*.o