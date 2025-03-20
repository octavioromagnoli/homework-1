#include <iostream>
#include <memory>

using namespace std;

//No hago try catch para los smart pointers por aclaracion de consigna de que no es necesario.
//Elijo hacer push back poco eficiente a cambio de evitar usar un struct de lista, usar una 
//lista implicaría declararla y no se pide por consigna una función create_list


struct Node {
  shared_ptr<Node> next;
  int value;
};

shared_ptr<Node> create_node(int value = 0) {
  shared_ptr<Node> newNode = make_shared<Node>();
  newNode->value = value;
  newNode->next = nullptr;
  return newNode;
}

void push_front(shared_ptr<Node>& head, int value = 0) {
  shared_ptr<Node> newNode = create_node(value);
  newNode->next = head;
  head = newNode;
  return;
}

void push_back(shared_ptr<Node>& head, int value = 0){
  shared_ptr<Node>newNode = create_node(value);
  if(!head){
    head = newNode;
    return;
  }

  shared_ptr<Node> iterator = head;
  while(iterator->next){
    iterator = iterator->next;
  }
  iterator->next = newNode;
  return;
}

void insert(shared_ptr<Node>& head, int position, int value = 0){
  if(position == 0){
    push_front(head, value);
    return;
  }

  shared_ptr<Node> newNode = create_node(value);
  shared_ptr<Node> iterator = head;
  int i = 0;
  while(iterator->next){
    if(++i == position){
      newNode->next = iterator->next;
      iterator->next = newNode;
      return;
    }
    iterator = iterator->next;
  }
  cout<<"La posición dada excede el largo de la lista, se insertará el nodo al final"<<endl;
  push_back(head, value);
  return;
}

void erase(shared_ptr<Node>&head,int position){
  if(position == 0){
    head = head->next;
    return;
  }
  shared_ptr<Node> iterator = head;
  shared_ptr<Node> parent = iterator;
  int i = 0;
  while(iterator->next){
    if(++i == position){
      iterator->next = iterator->next->next;
      return;
    }
    parent = iterator;
    iterator = iterator->next;
  }
  cout<<"La posición excede el largo de la lista, por lo que se eliminará el nodo del final"<<endl;
  iterator = nullptr;
  parent->next = parent->next->next;
  return;
}

void print_list(shared_ptr<Node>& head){
  shared_ptr<Node> iterator = head;
  while(iterator){
    cout<<"["<<iterator->value<<"] -> ";
    iterator = iterator->next;
  }
  cout<<" END"<<endl;
  return;
}

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

  // cout << "Eliminar en lista vacía: ";
  // shared_ptr<Node> emptyList = nullptr;
  // erase(emptyList, 0);
  // print_list(emptyList);
  return 0;
}