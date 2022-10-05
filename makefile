derlecalistir:Program calistir

Program:Node AgacIslem Test
	g++ ./lib/Node.o ./lib/AgacIslem.o ./lib/Test.o -o ./bin/Program
Node:
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
AgacIslem:
	g++ -I "./include" -c ./src/AgacIslem.cpp -o ./lib/AgacIslem.o
Test:
	g++ -I "./include" -c ./src/Test.cpp -o ./lib/Test.o
calistir:
	./bin/Program.exe