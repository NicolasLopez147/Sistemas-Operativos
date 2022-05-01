#Variables
OBJETOS = holaMundo.o main.o

#Compila las reglas especificadas
all: programa1 programa2

#Compila holaMundo
programa1: holaMundo.o
	gcc -o programa1 holaMundo.o 

#Compila main
programa2: main.o
	gcc -o programa2 main.o


holaMundo.o: holaMundo.c 
	gcc -c holaMundo.c

main.o: main.c 
	gcc -c main.c
	
#Limpia archivos
clean:
	rm -f programa $(OBJETOS)