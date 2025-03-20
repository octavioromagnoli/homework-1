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

int main() {
  return 0;
}