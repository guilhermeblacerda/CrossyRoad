CC = gcc

CFLAGS = -Wall

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = src/car.c src/game.c src/list.c src/main.c src/map.c src/player.c src/score.c

TARGET = main.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run:
	.\$(TARGET)

clean:
	del $(TARGET)