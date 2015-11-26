# Estudo sobre o problema da Árvore Geradora Mínima de Grau Restrito (*Degree-constrained minimum spanning tree* - DCMST) #

Este arquivo descreve a estrutura do projeto e os passos necessários para executar o program.

### Apresentação ###

Aqui são apresentadas algumas soluções para o problema da DCMST, incluindo os relatórios relacionados. Além disso, são apresentados também um gerador de instâncias (euclidianas e não euclidianas) e um validador (que checa se um dado grafo é uma árvore geradora de grau restrito).

Todos os algoritmos foram implementados em linguagem **C++** e compilados com o compilador *g++* versão 4.8.4. Também foi utilizada a flag de otimização *-O3* disponibilizada pelo compilador, que possibilitou um bom ganho de desempenho.

O projeto segue um padrão de organização comum em projetos feitos em C++, no qual as pastas de nome *inc* contém arquivos a serem incluídos, as de nome *src* contém a implementaçao e as de nome *obj* contém os arquivos objetos gerados na compilação. Cada projeto também contém um *makefile* próprio, através do qual é possível compilar o projeto e gerar um executável sem grandes preocupações.

O gerador de instâncias se encontra na pasta **instancesGenerator**.

O validador se encontra na pasta **validator**.

No projeto principal contamos com duas pastas especiais:

* *instances*: contém instâncias para o problema.
* *results*: contém arquivos de saída com as soluções encontradas para cada método. Quando o programa é executado cada método (solução) gera dois arquivos, um gera a mesma saída que aparece na tela e o outro gera apenas o grafo e informações do número de vértices e grau máximo.

É possível rodar o programa 30 vezes com o script *exec.run*, que recebe o caminho da instância como parâmetro. Também pode-se compilar o projeto principal sem grandes dificuldades com o comando *make*.

### Equipe de desenvolvimento ###

* Rubem Kalebe (rubemkalebe@gmail.com)
