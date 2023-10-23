//Declaración de la clase ListArray

#include <iostream> 
#include "List.h"
#include <ostream> 

using namespace std;

template <typename T> 

class ListArray : public List<T> {
private:
  T *arr;
  int max; //Tamaño máximo del array
  int n; //Elementos de la lista
  static const int MINSIZE = 2; //Tamaño mínimo de la lista
public:
  ListArray(){
    arr = new T[MINSIZE];
    n = 0;
    max = 2;
  }
  ~ListArray(){
    delete[] arr;
  }
  T operator[](int pos){
    if(pos < 0 || pos > size() - 1){
      throw out_of_range("Posición no válida");
    }
    else{
      return arr[pos];
    }
  }
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    for(int i = 0; i < list.n; i++){
      out << list.arr[i] << " ";
    }
    return out;
  }
private: 
  void resize(int new_size){
    T *newArray = new T[new_size];
    for(int i = 0; i < max; i++){
      newArray[i] = arr[i];
    }
    delete[] arr;
    arr = newArray;
    max = new_size;
  }
public:
  void insert(int pos, T e) override{
    if(pos < 0 || pos > size()){
      throw out_of_range("Posición inválida");
    }
    else{
      if(n == max){
        resize(max + 1);
      }
    T *newArray = new T[max];
    int i = 0;
    n++;
    while(i < pos){
      newArray[i] = arr[i];
      i++;
    }
    newArray[i] = e;
    i++;
    while(i < n){
      newArray[i] = arr[i - 1];
      i++;
    }
    delete[] arr;
    arr = newArray;
    }
  }
  void append(T e) override{
    insert(n, e);
  }
  void prepend(T e) override{
    insert(0, e);
  }
  T remove(int pos) override{
    if(pos < 0 || pos > n){
      throw out_of_range("Posición inválida");
    }
    else{
      T x = arr[pos];
      T *newArray = new T[max];
      if(pos == 0){
        for(int i = 0; i < n - 1; i++){
          newArray[i] = arr[i + 1];
        }
      }
      else{
        for(int i = 0; i < pos; i++){
          newArray[i] = arr[i];
        }
        for(int i = pos + 1; i < n; i++){
          newArray[i - 1] = arr[i];
        }
      }
      delete[] arr;
      arr = newArray;
      n--;
      return x;
    }
  }
  T get(int pos) override{
    if(pos < 0 || pos > n){
      throw out_of_range("Posición inválida");
    }
    else{
      return arr[pos];
    }
  }
  int search(T e) override{
    for(int i = 0; i < n; i++){
      if(arr[i] == e){
        return i;
      }
    }
    return -1;
  }
  bool empty() override{
    if(size() == 0){
      return true;
    }
    else{
      return false;
    }
  }
  int size() override{
    return n;
  }
};
