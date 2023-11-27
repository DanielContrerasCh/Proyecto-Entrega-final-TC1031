#ifndef list_h
#define list_h

#include "exception.h"
#include <sstream>
#include <string>
#include <vector>
#include "flights.h"


template <class T> class List;

template <class T> class Link {
private:
  Link(T);
  Link(T, Link<T> *);

  T value;
  Link<T> *next;

  friend class List<T>;
};

// Constructor
template <class T> Link<T>::Link(T val) : value(val), next(0){}

// Constructor que inicializa un nuevo nodo con un valor dado y un siguiente nodo especificado
// @param val Valor del nodo
// @param nxt Puntero al siguiente nodo en la lista
template <class T> Link<T>::Link(T val, Link *nxt) {
  value = val;
  next = nxt;
}


template <class T> class List {
public:
  List();
  void add(T);
  void addFirst(T);
  int length() const;
  bool empty() const;
  string toString(int) const;
  int getSize();

private:
  Link<T> *head;
  int size;

};

// Constructor de la clase List
template <class T> List<T>::List() {
  size = 0;
  head = NULL;
}

// Función que verifica si la lista está vacía
// Complejidad O(1)
template <class T> bool List<T>::empty() const {
  if (size == 0) {
    return true;
  }
  return false;
}

// Función para agregar un elemento al principio de la lista
// Complejidad O(1)
template <class T> void List<T>::addFirst(T val) {

  Link<T> *nuevo_nodo = new Link<T>(val);
  if (nuevo_nodo == NULL) {
    throw OutOfMemory();
  }

  nuevo_nodo->next = head;
  head = nuevo_nodo;
  size++;
}

// Función para agregar un elemento al final de la lista
// Complejidad O(n)
// @param Valor de tipo T
template <class T> void List<T>::add(T val) {

  if (empty()) {
    addFirst(val);
  } else {
    Link<T> *nuevo_nodo = new Link<T>(val);
    if (nuevo_nodo == NULL) {
      throw OutOfMemory();
    }

    Link<T> *nodo_actual = head;
    while (nodo_actual->next != NULL) {
      nodo_actual = nodo_actual->next;
    }
    nodo_actual->next = nuevo_nodo;
    size++;
  }
}

// Función para obtener el tamaño de la lista
// Complejidad O(1)
// @return int
template <class T> int List<T>::getSize(){
  return size;
}

// Función devuelve un string para mostrar los detalles de un elemento de la lista
// Complejidad O(n) donde "n" es ctr.
// @param ctr Índice del elemento a obtener
// @return string 
template <class T> std::string List<T>::toString(int ctr) const {
  Link<T> *p;
  p = head;
  
  std::stringstream aux;

  for(int i = 0; i < ctr; i++){
    if(p == NULL){
      throw NoSuchElement();
    }
    p = p->next;
  }
  
  aux << p->value.showInfo();
  
  return aux.str();
}

#endif