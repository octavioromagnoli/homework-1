#include "3.h"
#include <iostream>
#include <memory>

using namespace std;

/*No hago try catch para los smart pointers por aclaracion de consigna de que no es necesario.
Elijo hacer push back poco eficiente a cambio de evitar usar un struct de lista, usar una 
lista implicaría declararla y no se pide por consigna una función create_list, entonces 
preferí no hacerla. En mi implementación, la lista es simplemente un puntero al primer 
nodo, que está concatenado con el resto de la lista.*/


struct Node {
  shared_ptr<Node> next;
  int value;
};

int main() {
  shared_ptr<Node> listHead = create_node(0);
  
  for (int i = 1; i <= 5; ++i) {
    push_front(listHead, i);
    cout << "Después de push_front(" << i << "): ";
    print_list(listHead);
  }

  for (int i = 6; i <= 10; ++i) {
    push_back(listHead, i);
    cout << "Después de push_back(" << i << "): ";
    print_list(listHead);
  }

  cout << "Antes de eliminar la posición 6: ";
  print_list(listHead);
  erase(listHead, 6);
  cout << "Después de eliminar la posición 6: ";
  print_list(listHead);
  
  // Casos borde
  cout << "Insertar en posición 0 (al frente): ";
  insert(listHead, 0, -1);
  print_list(listHead);
  
  cout << "Insertar en posición mayor al tamaño de la lista (al final): "<<endl;
  insert(listHead, 100, 99);
  print_list(listHead);
  
  cout << "Eliminar en posición 0 (al frente): ";
  erase(listHead, 0);
  print_list(listHead);
  
  cout << "Eliminar en posición mayor al tamaño de la lista (último nodo): "<<endl;
  erase(listHead, 100);
  print_list(listHead);
  
  cout << "Eliminar en lista vacía: ";
  shared_ptr<Node> emptyList = nullptr;
  erase(emptyList, 0);
  print_list(emptyList);

  cout << "push_front en una lista vacía: ";
  shared_ptr<Node> emptyList1 = nullptr;
  push_front(emptyList1, 42);
  print_list(emptyList1);

  cout << "push_back en una lista vacía: ";
  shared_ptr<Node> emptyList2 = nullptr;
  push_back(emptyList2, 84);
  print_list(emptyList2);

  cout << "insert en una lista vacía: ";
  shared_ptr<Node> emptyList3 = nullptr;
  insert(emptyList3, 4, 21);
  print_list(emptyList3);
  return 0;
}


shared_ptr<Node> create_node(int value) {
  shared_ptr<Node> newNode = make_shared<Node>();
  newNode->value = value;
  newNode->next = nullptr;
  return newNode;
}

void push_front(shared_ptr<Node>& head, int value) {
  shared_ptr<Node> newNode = create_node(value);
  newNode->next = head;
  head = newNode;
  return;
}

void push_back(shared_ptr<Node>& head, int value){
  shared_ptr<Node>newNode = create_node(value);
  if(!head){
    head = newNode;
    return;
  }
  shared_ptr<Node> iterator = head;
  //Recorro la lista hasta que iterator esté sobre el último nodo, luego inserto
  while(iterator->next){
    iterator = iterator->next;
  }
  iterator->next = newNode;
  return;
}

void insert(shared_ptr<Node>& head, int position, int value){
  if(!head){
    cout<<"La lista está vacía, se insertara en primera posición"<<endl;
    push_front(head, value);
    return;
  }
  if(position == 0){
    push_front(head, value);
    return;
  }

  shared_ptr<Node> newNode = create_node(value);
  shared_ptr<Node> iterator = head;
  int i = 0;
  //Recorro hasta que el siguiente sea la posición buscada e inserto allí
  while(iterator->next){
    if(++i == position){
      newNode->next = iterator->next;
      iterator->next = newNode;
      return;
    }
    iterator = iterator->next;
  }
  //Si recorrí toda la lista y no inserté significa que position>largo de la lista
  cout<<"La posición dada excede el largo de la lista, se insertará el nodo al final"<<endl;
  push_back(head, value);
  return;
}

void erase(shared_ptr<Node>&head,int position){
  if (!head) { //Si la lista está vacía informo al usuario
    cout << "La lista está vacía, no se puede eliminar ningún nodo." << endl;
    return;
  }
  //Borrar el primero es revincular el head
  if(position == 0){
    head = head->next;
    return;
  }
  // Como la lista es simplemente enlazada, para borrar el ultimo
  // nodo, necesito el nodo anterior, entonces lo guardo en parent
  shared_ptr<Node> iterator = head;
  shared_ptr<Node> parent = iterator;
  int i = 0;
  // Recorro hasta que el próximo sea el buscado o termine la lista
  while(iterator->next){
    if(++i == position){
      iterator->next = iterator->next->next;
      return;
    }
    parent = iterator;
    iterator = iterator->next;
  }
  // Si no eliminé significa que position > largo de la lista, elimino el último usando parent para revincular
  cout<<"La posición excede el largo de la lista, por lo que se eliminará el nodo del final"<<endl;
  parent->next = nullptr;
  return; //notar que al salir del scope iterator desaparece y el use count del nodo a borrar se hace 0
}

void print_list(shared_ptr<Node>& head){
  if (!head) {
    cout << "[]->END" << endl;
    return;
  }
  shared_ptr<Node> iterator = head;
  while(iterator){
    cout<<"["<<iterator->value<<"]->";
    iterator = iterator->next;
  }
  cout<<" END"<<endl;
  return;
}