CC = g++
include = ../../
lib_path = ../../nanabin
cpp =  In_1.cpp ../../Dino.cpp ../../Animals.cpp ../../Environment.cpp ../../Obstacle.cpp ../../Animal.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
out = intergrationtest
make: In_1.cpp
	$(CC) -I$(include) -L$(lib_path) $(cpp) $(lib) -o $(out)
