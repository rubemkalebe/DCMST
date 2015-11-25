# Estudo sobre o problema da Árvore Geradora Mínima de Grau Restrito (*Degree-constrained minimum spanning tree* - DCMST) #

Este arquivo descreve a estrutura do projeto e os passos necessários para executar o program.

### Apresentação ###

Aqui são apresentadas algumas soluções para o problema da DCMST, incluindo os relatórios relacionados. Além disso, são apresentados também um gerador de instâncias (euclidianas e não euclidianas) e um validador (que checa se um dado grafo é uma árvore geradora de grau restrito).

O projeto segue um padrão de organização comum, no qual as pastas de nome *inc* contém arquivos a serem incluídos, as de nome *src* contém a implementaçao e as de nome *obj* contém os arquivos objetos gerados na compilação. Cada projeto também contém um *makefile* próprio, através do qual é possível compilar o projeto e gerar um executável sem grandes preocupações.

O gerador de instâncias se encontra na pasta **instancesGenerator**.

O validador se encontra na pasta **validator**.

No projeto principal contamos com duas pastas especiais:

* *instances*: contém instâncias para o problema.
* *results*: contém arquivos de saída com as soluções encontradas para cada método. Cada método gera dois arquivos, um gera a mesma saída que aparece na tela e o outro gera apenas o grafo e informações do número de vértices e grau máximo.

É possível rodar o programa 30 vezes com o script *exec.run*, que recebe o caminho da instância como parâmetro. Também pode-se compilar o projeto principal sem grandes dificuldades com o comando *make*.

### Equipe de desenvolvimento ###

* Rubem Kalebe (rubemkalebe@gmail.com)
