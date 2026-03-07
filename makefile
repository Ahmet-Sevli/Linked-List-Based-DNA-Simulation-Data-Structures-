Tumu: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Gen_Dugum.cpp -o ./lib/Gen_Dugum.o
	g++ -c -I "./include" ./src/DNA_Liste.cpp -o ./lib/DNA_Liste.o
	g++ -c -I "./include" ./src/Kromozom_Dugum.cpp -o ./lib/Kromozom_Dugum.o
	g++ -c -I "./include" ./src/Kromozom_Liste.cpp -o ./lib/Kromozom_Liste.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o


bagla:
	g++ ./lib/Gen_Dugum.o ./lib/DNA_Liste.o ./lib/Kromozom_Dugum.o ./lib/Kromozom_Liste.o ./lib/main.o -o ./bin/program


calistir:
	./bin/program