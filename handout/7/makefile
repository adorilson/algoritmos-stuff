#
# A variável CC indica que compilador será utilizado
#
CC=g++

#
# A variável CFLAGS indica que opções de compilação queremos
#
CFLAGS=	-Wall -pedantic -ansi -g -c

#
# A variável LFLAGS indica que opções de compilação queremos
#
LFLAGS=	-Wall -g

#
# A variável INCS indica o caminho dos arquivos de cabeçalho
#
INCS=

#
# A variável LIBS indica o caminho das bibliotecas e as bibliotecas usadas na ligação
#
LIBS=

#
# A variável OBJS indica os arquivos objetos
#
OBJS= mainapp.o shuffler.o insertionsort.o mergesort.o

#
# Regra de compilação e ligação do executável
# 
mainapp: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mainapp $(LIBS)

#
# Regra de compilação do arquivo objeto shuffler.o
# 
shuffler.o: shuffler.hpp shuffler.cpp randint.hpp
	$(CC) $(CFLAGS) shuffler.cpp -o shuffler.o

#
# Regra de compilação do arquivo objeto insertionsort.o
# 
insertionsort.o: mysort.hpp insertionsort.hpp insertionsort.cpp
	$(CC) $(CFLAGS) insertionsort.cpp -o insertionsort.o

#
# Regra de compilação do arquivo objeto mergesort.o
# 
mergesort.o: mysort.hpp mergesort.hpp mergesort.cpp
	$(CC) $(CFLAGS) mergesort.cpp -o mergesort.o

#
# Regra de compilação do arquivo objeto mainapp.o
# 
mainapp.o: mainapp.cpp mysort.hpp shuffler.hpp insertionsort.hpp
	$(CC) $(CFLAGS) mainapp.cpp -o mainapp.o

#
# Regra que elimina arquivos intermediários
# 
clean:
	rm -f *.o *~

#
# Regra que elimina arquivos intermediários e executável
# 
realclean:
	rm -f *.o *~ mainapp