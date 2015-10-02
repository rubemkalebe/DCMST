# Makefile para compilação e linkedição do arquivo principal

# utilizaremos a variavel CP para definir o compilador a ser utilizado
CP=g++

# a variavel COPT sera utilizada para adicionar opcoes a compilacao
COPT=-c -Wall -std=c++11

# variavel para pasta 'src/'
SRC=src/

# variavel para pasta 'obj/'
OBJ=obj/

# variavel para pasta 'include/'
INC=include/

Main: EuclideanDistance.o Generator.o Main.o SaveInstance.o
	$(CP) $(OBJ)EuclideanDistance.o $(OBJ)Generator.o $(OBJ)SaveInstance.o $(OBJ)Main.o -o Main

SaveInstance.o:
	$(CP) $(COPT) -I $(INC) $(SRC)SaveInstance.cpp -o $(OBJ)SaveInstance.o

Generator.o: EuclideanDistance.o
		$(CP) $(COPT) -I $(INC) $(SRC)Generator.cpp -o $(OBJ)Generator.o

Main.o: Generator.o
			$(CP) $(COPT) -I $(INC) $(SRC)Main.cpp -o $(OBJ)Main.o

EuclideanDistance.o:
	$(CP) $(COPT) -I $(INC) $(SRC)EuclideanDistance.cpp -o $(OBJ)EuclideanDistance.o
