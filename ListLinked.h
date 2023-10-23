#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>

class ListLinked : public List<T> {
private:
  Node<T> *first;
  int n;
public:
  ListLinked(){
    first = nullptr;
    n = 0;
  }
  ~ListLinked(){
    Node<T> *aux = nullptr;
    for(int i = 0; i < n; i++){
      aux = first->next;
      delete first;
      first = aux;
    }
  }
  T operator[](int pos){
    if(pos < 0 || pos >= n){
      throw out_of_range("Posición inválida");  
    }
    else{
      Node<T> *aux = first;
      int i = 0;
      while(aux != nullptr && i < pos){
        aux = aux->next; 
        i++;
      }
      if(aux != nullptr){
        return aux->data;
      }
      return -1;
    }
  }
  friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
    int i = 0; 
    Node<T> *aux = list.first;
    while(i < list.n){
      out << aux->data << " ";
      aux = aux->next;
      i++;
    }
    return out;
  }
  void insert(int pos, T e) override{
    if(pos < 0 || pos > n){
      throw out_of_range("Posición inválida");
    }
    else if(pos == 0){
      first = new Node<T>(e, first);
      n++;
    }
    else{
      Node<T> *prev = first;
      int i = 0;
      while(prev != nullptr && i < pos - 1){
        prev = prev->next;
        i++;
      }
      if(prev != nullptr){
        prev->next = new Node(e, prev->next);
        n++;
      }
    }
  }
  void append(T e) override{
    insert(n, e);
  }
  void prepend(T e) override{
    insert(0, e);
  }
  T remove(int pos) override{
    if(pos < 0 || pos > n - 1){
      throw out_of_range("Posición inválida");
    }
    else if(pos == 0){
      Node<T> *aux = first;
      int x = first->data;
      first = first->next;
      n--;
      delete aux;
      return x;
    }
    else{
      Node<T> *aux = first;
      Node<T> *prev = nullptr;
      int i = 0;
      while(aux != nullptr && i < pos){
        prev = aux;
        aux = aux->next;
        i++;
      }
      if(aux != nullptr){
        int x = aux->data;
        prev->next = aux->next;
        n--;
        delete aux;
        return x;
      }
      return -1;
    }
  }
  T get(int pos) override{
    if(pos < 0 || pos > n - 1){
      throw out_of_range("Posición inválida");
    }
    else{
      int i = 0;
      Node<T> *aux = first;
      while(aux != nullptr && i < pos){
        aux = aux->next;
        i++;
      }
      if(aux != nullptr){
        return aux->data;
      }
      return -1;
    }
  }
  int search(T e) override{
    Node<T> *aux = first;
    int i = 0;
    while(aux != nullptr && aux->data != e){
      aux = aux->next;
      i++;
    }
    if(aux != nullptr){
      return i;
    }
    else{
      return -1;
    }
  }
  bool empty() override{
    return first == nullptr;
  }
  int size() override{
    return n;
  }
};
