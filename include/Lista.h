#ifndef LISTA_H
#define LISTA_H

#include <string>

using namespace std; // Agregamos using namespace std

template <typename T>
struct NodoLista{
    T dato;
    NodoLista<T>* siguiente;
};

template <typename T>
class Lista {
private:
    NodoLista<T>* cabeza;

public:

    NodoLista<T>*& obtenerCabeza();

    Lista();

    // ~Lista();

    void agregarElemento(T elemento);

    void mostrarLista() const;

    void eliminarElemento(T elemento, NodoLista<T>* &cabeza);

};


#endif