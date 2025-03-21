#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <memory>
using namespace std;

struct Node;

/*
  Crea y retorna un nodo con el valor dado (0 a falta de parámetro).
  El nodo creado tiene next en nullptr.
  */
shared_ptr<Node> create_node(int value = 0);

/*
  Inserta un nodo con el valor dado (0 a falta de parámetro) al principio
  de la lista y actualiza la cabezera de lista al nuevo nodo.
  */
void push_front(shared_ptr<Node>& head, int value = 0);

/*
  Inserta un nodo con el valor dado (0 a falta de parámetro) al final
  de la lista.
  */
void push_back(shared_ptr<Node>& head, int value = 0);

/*
  Inserta un nodo con el valor dado (0 a falta de parámetro) en la posición dada. 
  Si la posición dada es mayor al largo de la lista, 
  se inserta al final.
  */
void insert(shared_ptr<Node>& head, int position, int value = 0);

/*
  Elimina el nodo de la lista en la posición dada. 
  Si la posición dada es mayor al largo de la lista, 
  se elimina el último nodo. Si la lista está vacía,
  informa al usuario y no hace nada.
  */
void erase(shared_ptr<Node>& head, int position);

/*
  Imprime la lista dada.
  */
void print_list(shared_ptr<Node>& head);

#endif 