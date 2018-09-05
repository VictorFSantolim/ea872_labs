/*
 *  Rodrigo Oliveira Caus - 186807
 *  Victor Ferrão Santolim - 187888
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "oo_model.hpp"

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main ()
{
    Corpo *c1 = new Corpo(10, 0, 0, 100.0, 3.0);
    Corpo *c2 = new Corpo(10, 0, 0, 100.0, 1.5);
    Corpo *c3 = new Corpo(10, 0, 0, 200.0, 0.5);
    Corpo *c4 = new Corpo(10, 0, 0, 200.0, 1.5);

  ListaDeCorpos *l = new ListaDeCorpos();
  l->add_corpo(c1);
  l->add_corpo(c2);
  l->add_corpo(c3);
  l->add_corpo(c4);

  Fisica *f = new Fisica(l);

  Tela *tela = new Tela(l, 20, 20, 20, 20);
  tela->init();

  Teclado *teclado = new Teclado();
  teclado->init();

  uint64_t t0;
  uint64_t t1;
  uint64_t deltaT;
  uint64_t T;

  int i = 0;

  T = get_now_ms();
  t1 = T;
  while (1) {
    // Atualiza timers
    t0 = t1;
    t1 = get_now_ms();
    deltaT = t1-t0;

    // Atualiza modelo
    f->update(deltaT);

    // Atualiza tela
    tela->update();

    // Lê o teclado
    char c = teclado->getchar();
    if (c == 'w') {
        f->choque('u');
    }
    else if (c == 's') {
        f->choque('d');
    }
    if (c == 'q') {
      break;
    }

    // Condicao de parada
    //if ( (t1-T) > 10000 ) break;

    std::this_thread::sleep_for (std::chrono::milliseconds(30));
    i++;
  }
  tela->stop();
  teclado->stop();
  return 0;
}
