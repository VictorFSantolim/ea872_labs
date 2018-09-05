Rodrigo Oliveira Caus - 186807
Victor Ferrão Santolim - 187888

Foram feitas apenas alterações no método Fisica::update. Criamos dois floats, mola e amortecimento,
que são os parâmetros físicos do sistema massa-mola. Também criamos o float aceleracao, calculada com
base força da mola em função da posição e o amortecimento em função da velocidade. Essa aceleração é
calculada para cada corpo quando o método update é chamado. O float new_vel agora é a velocidade
anterior mais a aceleração vezes deltaT. O float new_pos é mantido como anteriormente.

No mainloop, foram alterados apenas o tempo de execução da simuação de 3 para 25 segundos para melhor
visualização das oscilações amortecidas. Foi modificado também o texto "Altura" para "Posição" exibido
na saida padrão.
 
