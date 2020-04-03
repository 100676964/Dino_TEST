CC = g++
include = ../../
lib_path = ../../nanabin
cpp = DinoBenchmark.cpp ../../Animal.cpp ../../Animals.cpp ../../Dino.cpp ../../Environment.cpp ../../Obstacle.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
outdir = Run_benchmark
make: DinoBenchmark.cpp
	$(CC) -I$(include) -L$(lib_path) $(cpp) $(lib) -o $(outdir)