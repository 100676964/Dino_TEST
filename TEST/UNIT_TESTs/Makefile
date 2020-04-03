CC = g++
include = ../../
lib_path = ../../nanabin
cpp = Runtests.cpp TEST_Dino/DinoTest.cpp TEST_Obstacle/ObstacleTest.cpp TEST_Animals/AnimalsTest.cpp TEST_Animal/AnimalTest.cpp ../../Dino.cpp ../../Animals.cpp ../../Environment.cpp ../../Obstacle.cpp ../../Animal.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
make: Runtests.cpp
	$(CC) -I$(include) -L$(lib_path) $(cpp) $(lib)