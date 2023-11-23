#include "../include/Lista.h"
#include <iostream>

using namespace std;

template <typename T>
Lista<T>::Lista() : cabeza(nullptr) {}


// template <typename T>
// Lista<T>::~Lista() {
//         while (cabeza) {
//             NodoLista<T>* temp = cabeza;
//             cabeza = cabeza->siguiente;
//             delete temp;
//         }
// }

template <typename T>
NodoLista<T>*& Lista<T>::obtenerCabeza(){ //hay doble Lista porque Nodo esta dentro de la Lista y obtenerCabeza tambien
    return cabeza;
}


template <typename T>
void Lista<T>::agregarElemento(T elemento){
    NodoLista<T>* nuevoNodo = new NodoLista<T>;
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}


template <typename T>
void Lista<T>::mostrarLista() const{
    NodoLista<T>* actual = cabeza;
    while (actual) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}


template <typename T>
void Lista<T>::eliminarElemento(T elemento, NodoLista<T>* &miLista) {
    // Caso base: si la lista está vacía
    if (!miLista) {
        return;
    }
    
    // Caso especial: el elemento a eliminar está en la cabeza de la lista
    if (miLista->dato == elemento) {
        NodoLista<T>* temp = miLista;
        miLista = miLista->siguiente;
        delete temp;
        eliminarElemento(elemento, miLista); // Llamada recursiva para eliminar otros elementos iguales
    } else {
        // Caso general: buscar el elemento en el resto de la lista
        eliminarElemento(elemento, miLista->siguiente); // Continuar con la siguiente posición
    }
}

