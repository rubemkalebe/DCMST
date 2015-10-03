# Makefile para compilação e linkedição do arquivo principal

# utilizaremos a variavel CP para definir o compilador a ser utilizado
CP=g++

# a variavel COPT sera utilizada para adicionar opcoes a compilacao
COPT=-c -Wall -O3

# variavel para pasta 'src/'
SRC=src/

# variavel para pasta 'obj/'
OBJ=obj/

# variavel para pasta 'include/'
INC=include/

Main: Main.o CostMatrix.o Backtracking.o
	$(CP) $(OBJ)*.o -o Main -g

Main.o: CostMatrix.o LoadFile.o Backtracking.o SaveResults.o OptimizedBacktracking.o OrderedOptimizedBacktracking.o
	$(CP) $(COPT) -I $(INC) $(SRC)Main.cpp -o $(OBJ)Main.o -std=c++0x

OptimizedBacktracking.o: Vertex.o Edge.o CostMatrix.o Tree.o Chronometer.o
	$(CP) $(COPT) -I $(INC) $(SRC)OptimizedBacktracking.cpp -o $(OBJ)OptimizedBacktracking.o

OrderedOptimizedBacktracking.o: Vertex.o Edge.o CostMatrix.o Tree.o Chronometer.o
	$(CP) $(COPT) -I $(INC) $(SRC)OrderedOptimizedBacktracking.cpp -o $(OBJ)OrderedOptimizedBacktracking.o

Backtracking.o: Vertex.o Edge.o CostMatrix.o Tree.o Chronometer.o
	$(CP) $(COPT) -I $(INC) $(SRC)Backtracking.cpp -o $(OBJ)Backtracking.o

SaveResults.o: Edge.o Tree.o
	$(CP) $(COPT) -I $(INC) $(SRC)SaveResults.cpp -o $(OBJ)SaveResults.o -std=c++0x

LoadFile.o: CostMatrix.o Tree.o
	$(CP) $(COPT) -I $(INC) $(SRC)LoadFile.cpp -o $(OBJ)LoadFile.o

Tree.o: Edge.o UnionFind.o
	$(CP) $(COPT) -I $(INC) $(SRC)Tree.cpp -o $(OBJ)Tree.o -std=c++0x

Edge.o: Vertex.o
	$(CP) $(COPT) -I $(INC) $(SRC)Edge.cpp -o $(OBJ)Edge.o

CostMatrix.o:
	$(CP) $(COPT) -I $(INC) $(SRC)CostMatrix.cpp -o $(OBJ)CostMatrix.o

UnionFind.o:
	$(CP) $(COPT) -I $(INC) $(SRC)UnionFind.cpp -o $(OBJ)UnionFind.o

Vertex.o:
	$(CP) $(COPT) -I $(INC) $(SRC)Vertex.cpp -o $(OBJ)Vertex.o

Chronometer.o:
	$(CP) $(COPT) -I $(INC) $(SRC)Chronometer.cpp -o $(OBJ)Chronometer.o
