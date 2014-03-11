
all: eular_integrator

CC = gcc 
FLAGS = -lm -O3

BIN_DIR = ./bin
APP_DIR = ./src

eular_integrator:
	$(CC) $(APP_DIR)/eular_integrator.c -o $(BIN_DIR)/eular_integrator $(FLAGS)

clean:
	rm $(BIN_DIR)/eular_integrator