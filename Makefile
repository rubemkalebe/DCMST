# Makefile para compilação e linkedição do arquivo principal

# utilizaremos a variavel CP para definir o compilador a ser utilizado
CP=g++

# a variavel COPT sera utilizada para adicionar opcoes a compilacao
COPT=-c -Wall

# variavel para pasta 'src/'
SRC=src/

# variavel para pasta 'obj/'
OBJ=obj/

# variavel para pasta 'include/'
INC=include/

main: funcoes.o main.o
	$(CP) $(OBJ)funcoes.o $(OBJ)main.o -o main

funcoes.o:
	$(CP) $(COPT) -I $(INC) $(SRC)funcoes.cpp -o $(OBJ)funcoes.o

main.o:
	$(CP) $(COPT) -I $(INC) $(SRC)main.cpp -o $(OBJ)main.o