CC = gcc
CFLAGS = -Wall
SRC = src/car.c src/game.c src/list.c src/main.c src/map.c src/player.c src/score.c

ifeq ($(OS), Windows_NT)
    TARGET = main.exe
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    CLEAN = del $(TARGET)
    RUN = .\$(TARGET)
else
    TARGET = main
    LIBS = -lraylib -lm -ldl -lpthread
    CLEAN = rm -f $(TARGET)
    RUN = ./$(TARGET)
endif

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run:
	$(RUN)

clean:
	$(CLEAN)
