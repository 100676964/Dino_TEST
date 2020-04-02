CC = g++
include = ../../../
lib_path = ../../../nanabin
cpp = EnvironmentTest.cpp ../../../Dino.cpp ../../../Animals.cpp ../../../Environment.cpp ../../../Obstacle.cpp ../../../Animal.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
make: EnvironmentTest.cpp
	$(CC) -I$(include) -L$(lib_path) $(cpp) $(lib)