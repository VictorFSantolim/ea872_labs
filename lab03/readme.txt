Rodrigo Caus (186807) e Victor Santolim (187888)
Lab 3 - ncurses2

Mudanças do lab 3:

	Portamos as mudanças feitas no lab 2 para o código disponibilizado do lab 3.
	Modificamos a função choque em oo_model.cpp para receber um char de parâmetro, 
	'u' ou 'd', que indica qual direção será incrementada a velocidade, ou seja 
	direção do impulso. Nessa função, a velocidade agora é velocidade mais ou menos
	uma constante, dependendo do parâmetro. Em model_mainloop.cpp, modificamos o
	modo como é tratada a leitura do caractere, para selecionar o parâmetro de
	chamada da funçõo choque. Também nesse arquivo, removemos o critério de parada
	por tempo de simulação.
