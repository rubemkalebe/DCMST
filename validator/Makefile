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

Main: Main.o Graph.o Edge.o CostMatrix.o LoadFile.o Validator.o
	$(CP) $(OBJ)*.o -o Main -g
#	$(CP) $(OBJ)Main.o -o Main -g

Main.o: CostMatrix.o LoadFile.o Graph.o Validator.o
	$(CP) $(COPT) -I $(INC) $(SRC)Main.cpp -o $(OBJ)Main.o

Validator.o: Edge.o Graph.o CostMatrix.o
	$(CP) $(COPT) -I $(INC) $(SRC)Validator.cpp -o $(OBJ)Validator.o -std=c++0x

LoadFile.o: Graph.o CostMatrix.o
	$(CP) $(COPT) -I $(INC) $(SRC)LoadFile.cpp -o $(OBJ)LoadFile.o

Graph.o: Vertex.o Edge.o UnionFind.o
	$(CP) $(COPT) -I $(INC) $(SRC)Graph.cpp -o $(OBJ)Graph.o

Edge.o: Vertex.o
	$(CP) $(COPT) -I $(INC) $(SRC)Edge.cpp -o $(OBJ)Edge.o

CostMatrix.o:
	$(CP) $(COPT) -I $(INC) $(SRC)CostMatrix.cpp -o $(OBJ)CostMatrix.o

UnionFind.o:
	$(CP) $(COPT) -I $(INC) $(SRC)UnionFind.cpp -o $(OBJ)UnionFind.o

Vertex.o:
	$(CP) $(COPT) -I $(INC) $(SRC)Vertex.cpp -o $(OBJ)Vertex.o
