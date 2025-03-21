all: ej1 ej2 ej3 ej4
#Compilar el ejercicio
ej1: Ej_1/1.cpp Ej_1/1.h
	g++ -Wall -g Ej_1/1.cpp -o 1

ej2: Ej_2/2.cpp Ej_2/2.h
	g++ -Wall -g Ej_2/2.cpp -o 2

ej3: Ej_3/3.cpp Ej_3/3.h
	g++ -Wall -g Ej_3/3.cpp -o 3

ej4: Ej_4/4.cpp 
	g++ -Wall -g Ej_4/4.cpp -o 4
#Correr el ejercicio compilado
run1:
	./1

run2:
	./2

run3:
	./3

run4:
	./4

execute1: ej1
	./1

execute2: ej2
	./2

execute3: ej3
	./3

execute4: ej4
	./4
# Limpiar archivos de ejecución
clean:
	rm -f 1
	rm -f 2
	rm -f logtext.txt
	rm -f 3
	rm -f 4

.PHONY: all clean run_ex1 run_ex2 run_ex3 run_ex4 run_ex5
