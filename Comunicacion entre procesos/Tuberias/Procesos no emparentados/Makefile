all: ejecutarLectura 

#Compila lectura.c
compilarLectura: lectura.c
	gcc lectura.c -o lectura

#Compila escritura.c
compilarEscritura: escritura.c
	gcc escritura.c -o escritura

#Crear terminal y compila y ejecuta lectura
ejecutarLectura: crearTerminal compilarLectura
	./lectura

#Compila escritura, crea una nueva terminal y ejecuta escritura en esa terminal
crearTerminal: compilarEscritura
	gnome-terminal -- ./escritura
