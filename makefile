all: derle bagla calistir

derle:
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include -o ./lib/basamak.o -c ./src/basamak.cpp
	g++ -I ./include -o ./lib/sayi.o -c ./src/sayi.cpp

bagla:
	g++ -o ./bin/program.exe ./lib/basamak.o ./lib/main.o ./lib/sayi.o

calistir:
	./bin/program
