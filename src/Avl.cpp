#include <iostream>
#include "../include/Avl.h"

using namespace std;

template <typename T>
Avl<T> ::Avl() {
    miRaiz = nullptr;
}


template <typename T>
Avl<T> ::~Avl() {
    limpiar(miRaiz);
}

template <typename T>
T* Avl<T> ::buscarNodo(string miNombre){
    return busquedaRecursiva(miRaiz,miNombre);
}


template <typename T>
T* Avl<T>::busquedaRecursiva(NodoArbol<T>* miNodo, string miNombre) const {
    if (miNodo != nullptr) {
        if (miNodo->dato.getNombre() == miNombre) {
            return &(miNodo->dato);  // Devuelve el puntero del Contact
        } else if (miNodo->dato.getNombre() > miNombre) {
            return busquedaRecursiva(miNodo->min, miNombre);
        } else {
            return busquedaRecursiva(miNodo->max, miNombre);
        }
    }
    return nullptr;  // Devuelve nullptr si no se encuentra el nodo.
}


template <typename T>
void Avl<T>::eliminarNodoAvl(string miDato){
    eliminarNodoRecursivo(miRaiz, miDato);
}


template <typename T>
void Avl<T>::eliminarNodoRecursivo(NodoArbol<T>*& miNodo, string miDato) {
    if (miNodo == nullptr) {
        return;
    } else if (miDato < miNodo->dato.getNombre()) {
        eliminarNodoRecursivo(miNodo->min, miDato);
    } else if (miDato > miNodo->dato.getNombre()) {
        eliminarNodoRecursivo(miNodo->max, miDato);
    } else {
        // Nodo encontrado para eliminar
        if (miNodo->min != nullptr && miNodo->max != nullptr) {
            // Nodo con dos hijos
            NodoArbol<T>* sucesor = buscarMenorDeLasMayores(miNodo->max);
            miNodo->dato = sucesor->dato;
            eliminarNodoRecursivo(miNodo->max, sucesor->dato.getNombre());
        } else {
            // Nodo con uno o cero hijos
            NodoArbol<T>* temp = miNodo;
            miNodo = (miNodo->min != nullptr) ? miNodo->min : miNodo->max;
            delete temp;
        }
    }

    if (miNodo != nullptr){
        int balance = getBalance(miNodo);
        ordenarConDif(miNodo, balance, miNodo->dato);
        miNodo->height = 1 + max(getAltura(miNodo->min),getAltura(miNodo->max));     
    }

}




template <typename T>
NodoArbol<T>* Avl<T>::buscarMenorDeLasMayores(NodoArbol<T>* nodo) {
    if (nodo->min != nullptr) {
        return buscarMenorDeLasMayores(nodo->min);
    }
    return nodo;
}

template <typename T>
int Avl<T>::getBalance(NodoArbol<T>* miNodo) {
    if (miNodo == nullptr) {
        return 0;
    }
    return getAltura(miNodo->min) - getAltura(miNodo->max);
}


template <typename T>
void Avl<T>::ordenarConDif(NodoArbol<T>*& miNodo, int dif,T val){

    // Verifica y corrige el desequilibrio
    if (dif > 1) {
        if (miNodo->min != nullptr && miNodo->min->min != nullptr) {
            // Rotación IZQ-IZQ
            NodoArbol<T>* x1 = miNodo->min;
            NodoArbol<T>* y1 = x1->max;
            x1->max = miNodo;
            miNodo->min = y1;
            miNodo = x1;

            ActualizarAltura(miNodo->min);
            ActualizarAltura(miNodo->max);
            miNodo->height = 1 + max(getAltura(miNodo->min),getAltura(miNodo->max));
            
        } else {
            //Rotacion IZQ-DER
            NodoArbol<T>* y2= miNodo->min;
            NodoArbol<T>* x2= y2->max;
            y2->max=x2->min; 
            x2->min=y2;
            miNodo->min=x2;

            // y hacemos la rotacion IZQ-IZQ
            NodoArbol<T>* x3 = miNodo->min;
            NodoArbol<T>* y3 = x3->max;
            x3->max = miNodo;
            miNodo->min = y3;
            miNodo = x3;

            ActualizarAltura(miNodo->min);            
            ActualizarAltura(miNodo->max);
            miNodo->height = 1 + max(getAltura(miNodo->min),getAltura(miNodo->max));
            

        }
    } else if (dif < -1) {
        if (miNodo->max != nullptr && miNodo->max->max != nullptr) {
            // Rotación DER-DER
            NodoArbol<T>* y4 = miNodo->max;
            NodoArbol<T>* x4 = y4->min;
            y4->min = miNodo;
            miNodo->max = x4;
            miNodo = y4;

            ActualizarAltura(miNodo->min);
            ActualizarAltura(miNodo->max);
            miNodo->height = 1 + max(getAltura(miNodo->min),getAltura(miNodo->max));
            
        } else {
            //Rotacion DER-IZQ
            NodoArbol<T>* y5 = miNodo->max;
            NodoArbol<T>* x5 = y5->min;
            y5->min = x5->max;
            x5->max = y5;
            miNodo->max = x5;

            // y hacemos la rotacion DER-DER
            NodoArbol<T>* y6 = miNodo->max;
            NodoArbol<T>* x6 = y6->min;
            y6->min = miNodo;
            miNodo->max = x6;
            miNodo = y6;

            ActualizarAltura(miNodo->min);
            ActualizarAltura(miNodo->max);
            miNodo->height = 1 + max(getAltura(miNodo->min),getAltura(miNodo->max));

        }
    }
}


template <typename T>
bool Avl<T>::operator==(const T& miDato) const {
    return (miRaiz != nullptr) && (miRaiz->dato.getNombre() == miDato.getNombre());
}



template <typename T>
void Avl<T> ::limpiar(NodoArbol<T>*& miNodo){
    if (miNodo!=nullptr){
        limpiar(miNodo->min);
        limpiar(miNodo->max);
        delete(miNodo);
    }
}



template <typename T>
int Avl<T>::getAltura(NodoArbol<T>* miNodo) const {
    if (miNodo == nullptr) {
        return 0; // La altura de un nodo nulo es 0.
    }else{
        return miNodo->height;
    }
}


template <typename T>
void Avl<T>::ActualizarAltura(NodoArbol<T>*& miNodo) {
    if (miNodo!=nullptr){
        if (miNodo->min==nullptr && miNodo->max==nullptr){
            miNodo->height=1;
        }else{
            miNodo->height = 1 + max(getAltura(miNodo->min), getAltura(miNodo->max));
        }
    }
}


template <typename T>
void Avl<T>::agregarAVL(T val){
    agregarRecursivo(miRaiz, val);
}


template <typename T>
void Avl<T>::agregarRecursivo(NodoArbol<T>*& miNodo, T val) {
    if (miNodo == nullptr) {
        miNodo = new NodoArbol<T>();
        miNodo->dato = val;
        miNodo->max = nullptr;
        miNodo->min = nullptr;
        miNodo->height = 1;
    } else {
        if (miNodo->dato.getNombre() > val.getNombre()) {
            agregarRecursivo(miNodo->min, val);
        } else {
            agregarRecursivo(miNodo->max, val);
        }
    
        // Después de la inserción, recalcula la altura
        miNodo->height = 1 + max(getAltura(miNodo->min), getAltura(miNodo->max));

        // Calcula el factor de equilibrio después de la inserción
        int dif = getAltura(miNodo->min) - getAltura(miNodo->max);


        ordenarConDif(miNodo,dif,val);

    }
}


template <typename T>
void Avl<T>::mostrar() const{
    mostrarEnOrden(miRaiz);
}


template <typename T>
void Avl<T>::mostrarEnOrden(NodoArbol<T>* miNodo) const{
    if (miNodo!=nullptr){
        cout << "El valor es " << miNodo->dato.getNombre() << " " << "y la altura es " << miNodo->height<<endl;

        mostrarEnOrden(miNodo->min);
        mostrarEnOrden(miNodo->max);
    }
}