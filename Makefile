CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU -std=c++17
OPS=-O3

SRC_FILES=src/*.cpp include/*.hpp
MAIN_FILE=main.cpp 
OUTPUT=-o bin/galaxy_simulation.o

build: 
	$(CC) $(MAIN_FILE) $(SRC_FILES) $(OUTPUT) $(LIBS) $(OPS)

run:
	bin/./galaxy_simulation.o

rbuild:
	$(CC) $(MAIN_FILE) $(SRC_FILES) $(OUTPUT) $(LIBS) $(OPS)
	bin/./galaxy_simulation.o

.PHONY: clean
clean:
	rm -rf bin/*.o