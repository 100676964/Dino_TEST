CC = g++
include = ../
lib_path = ../nanabin
Ucpp = UNIT_TESTs/Runtests.cpp UNIT_TESTs/TEST_Dino/DinoTest.cpp UNIT_TESTs/TEST_Obstacle/ObstacleTest.cpp UNIT_TESTs/TEST_Animals/AnimalsTest.cpp UNIT_TESTs/TEST_Animal/AnimalTest.cpp UNIT_TESTs/TEST_Environment/EnvironmentTest.cpp ../Dino.cpp ../Animals.cpp ../Environment.cpp ../Obstacle.cpp ../Animal.cpp
Bcpp = Benchmark_TEST/DinoBenchmark.cpp ../Animal.cpp ../Animals.cpp ../Dino.cpp ../Environment.cpp ../Obstacle.cpp
Icpp =  Intergration_TESTs/IntergrationTest.cpp ../Dino.cpp ../Animals.cpp ../Environment.cpp ../Obstacle.cpp ../Animal.cpp
lib = -lnana -lX11 -lpthread -lrt -lXft -lfontconfig -lstdc++fs
Uout = UNIT_TESTs/RunUnitTests
Bout = Benchmark_TEST/RunBenchmarkTest
Iout = Intergration_TESTs/RunIntergrationTest
all: one two three fourtw
one: UNIT_TESTs/Runtests.cpp
	$(CC) -I$(include) -L$(lib_path) $(Ucpp) $(lib) -o $(Uout)
two: Benchmark_TEST/DinoBenchmark.cpp
	$(CC) -I$(include) -L$(lib_path) $(Bcpp) $(lib) -o $(Bout)
three: Intergration_TESTs/IntergrationTest.cpp
	$(CC) -I$(include) -L$(lib_path) $(Icpp) $(lib) -o $(Iout)
four: AutoRun.cpp
	$(CC) AutoRun.cpp -I$(include) -L$(lib_path) $(lib) -o AutoRun
