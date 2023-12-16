# makefile

derle:
	g++ -I ./include/ -o ./lib/Labirent.o -c ./src/Labirent.cpp
	g++ -I ./include/ -o ./bin/Labirent ./lib/Labirent.o ./src/main.cpp

calistir:
	./bin/Labirent
