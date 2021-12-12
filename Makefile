all: 
	g++ -c main.cpp -o main.o
	g++ main.o -o main.out
	@echo  "\e[1;31m ПРИМЕР РАБОТЫ ПРОГРАММЫ ПРИ СЧИТЫВАНИИ МАТРИЦЫ РАЗМЕРА 4х4 ИЗ ФАЙЛА С ВЫВОДОМ ПЕРВЫХ 4 СТРОК\e[0m"
	./main.out 4 4 0 input.txt
	rm *.o *.out