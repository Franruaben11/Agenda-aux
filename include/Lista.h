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

    NodoLista<T>* obtenerCabeza() const;

    Lista();

    Lista<T>& operator=(const NodoLista<T>* miNewNodo);

    // ~Lista();

    void agregarElemento(T elemento);
    

    void mostrarLista() const;

    void eliminarElemento(T elemento, NodoLista<T>* &cabeza);

};


#endif