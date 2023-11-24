#include <iostream>
#include "../include/Agenda.h"

void Agenda::agregarContacto(const Contact& contacto){
    miAgenda.agregarAVL(contacto);
}

void Agenda::mostrarContactos(Lista<Contact> miLista){
    miAgenda.mostrar(miLista);
    mostrarRecursivo(miLista);
}


void Agenda::mostrarRecursivo(const Lista<Contact>& miLista) const{
    NodoLista<Contact>* actual = miLista.obtenerCabeza();

    // Base de la recursión: si el nodo actual es nulo, terminar la recursión
    while (actual != nullptr) {
        // Mostrar información del contacto
        cout << "Nombre: " << actual->dato.getNombre() << ", " << "Teléfono: " << actual->dato.getNroTelefono() << endl;
        // ... (mostrar otros detalles del contacto)

        // Mover al siguiente nodo
        actual = actual->siguiente;
    }
}


void Agenda::eliminarContacto(const string& name){
    if (name!=""){
        miAgenda.eliminarNodoAvl(name);
    }
}

void Agenda::buscarContacto(const string& name){
    if (name!=""){
    Contact* miNodo = miAgenda.buscarNodo(name);
    cout<< endl;
    if (miNodo != nullptr) {
        datosUser(miNodo);
        cout<< endl;
        
    } else {
        cout<< "EL CONTACTO NO FUE ENCONTRADO" << endl;
        cout<< endl;
    }
    }
}


void Agenda::datosUser(Contact* miUser)const{
        if (miUser!=nullptr){
            cout << endl;
            cout << "/////////////////////////////////////"<<endl;
            cout << "Nombre: " << miUser->getNombre() << endl;
            cout << "Número de Teléfono: " << miUser->getNroTelefono() << endl;
            cout << "Email: " << miUser->getEmail() << endl;
            cout << "Dirección: " << miUser->getDireccion() << endl;
            cout << "Fecha de Cumpleaños: " << miUser->getFechaCumpleanios() << endl;
            cout << "Nombre de la Empresa: " << miUser->getEmpresa() << endl;
            cout << "Puesto: " << miUser->getPuesto() << endl;
            cout << "Descripción: " << miUser->getDescripcion() << endl;
            cout << "Redes Sociales: ";
            miUser->getRedesSociales();
            cout << "/////////////////////////////////////"<<endl;
            cout << endl;
        }
}

Agenda::Agenda(){}

Agenda::~Agenda(){}

