#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include "Lista.h"

using namespace std;

template <typename T>
struct NodoArbol {
    T dato;
    NodoArbol<T>* max;
    NodoArbol<T>* min;
    int height;
};


template <typename T>
class Avl {
private:
    NodoArbol<T>* miRaiz;
    void mostrarEnOrden(NodoArbol<T>* miNodo,Lista<T>& miLista);
    void agregarRecursivo(NodoArbol<T>*& miNodo, T val1);
    void limpiar(NodoArbol<T>*& miNodo);
    void eliminarNodoRecursivo(NodoArbol<T>*& miNodo, string name);
    T* busquedaRecursiva(NodoArbol<T>* miNodo, string name) const;
    int getBalance(NodoArbol<T>* miNodo);
    void ordenarConDif(NodoArbol<T>*& miNodo,int dif, T val);
    NodoArbol<T>* buscarMenorDeLasMayores(NodoArbol<T>* miNodo);

public:
    Avl();
    ~Avl();
    void ActualizarAltura(NodoArbol<T>*& miNodo);
    int getAltura(NodoArbol<T>* miNodo) const;
    void agregarAVL(T val1);
    void eliminarNodoAvl(string nameBorrar);
    T* buscarNodo(string nombreBuscar);
    void mostrar(Lista<T>& miLista) ;
};

#endif
