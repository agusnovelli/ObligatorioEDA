todo: main.o ./losmain/sistema.o ./losmain/directorio.o ./losmain/archivo.o ./losmain/contenido.o
	g++ -o main main.o ./losmain/sistema.o ./losmain/directorio.o ./losmain/archivo.o ./losmain/contenido.o
main.o: main.cpp
	g++ -c main.cpp
sistema.o: ../lospuntohache/sistema.h sistema.cpp
	g++ -c sistema.cpp
directorio.o: ../lospuntohache/directorio.h directorio.cpp
	g++ -c directorio.cpp
archivo.o: ../lospuntohache/archivo.h archivo.cpp
	g++ -c archivo.cpp
contenido.o: ../lospuntohache/contenido.h contenido.cpp
	g++ -c contenido.cpp
limpiar:
	rm *.o
	rm main
