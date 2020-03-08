CC = g++
include = ./
lib_path = ./nanabin
cpp = *.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
outdir = ./exe/Dinogame
make: ExperimentGame.cpp
	$(CC) -I$(include) -L$(lib_path) $(cpp) $(lib) -o $(outdir)