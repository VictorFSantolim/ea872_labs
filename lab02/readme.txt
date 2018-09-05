Rodrigo Caus (186807) e Victor Santolim (187888)
Lab 2 - ncurses1

Para implementar quatro osciladores massa-mola amortecidos, modificamos o
arquivo oo_model.hpp, adicionando à classe Corpo os floats mola e viscosidade.
Também foram criadas os escopos das funções de get para esses atributos. No arquivo
oo_model.cpp , o construtor de Corpo foi alterado para adicionar as novas
variáveis, assim como escrito a definição das funções de get dessas variáveis.
O hard_copy foi igualmente modificado para copiar esses atributos do corpo.
A Física::update foi modificado e foi criada o float aceleracao, que é calculado
para cada corpo com base nas forças exercidas pela viscosidade e pela mola.
Por fim, Tela::update foi modificado para incluir um offset na posição de desenho
e remoção do caractere que representa o corpo. Também adicionamos uma verificação
do valor dessa posição. Se for menor que zero ou maior que o MaxI, não é feita
a impressão. No mainloop, apenas modificamos as posições iniciais e adicionamos
as constantes da mola e viscosidade.
