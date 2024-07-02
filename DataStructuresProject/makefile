hepsi:derle calistir

derle:
	g++ -I ./include/ -o ./lib/Node.o  -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/List.o  -c ./src/List.cpp
	g++ -I ./include/ -o ./bin/Test   ./lib/Node.o ./lib/List.o ./src/Test.cpp
	
calistir:
	./bin/Test