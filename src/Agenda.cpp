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
    while (actual != nullptr) {
        cout << "Nombre: " << actual->dato.getNombre() << ", " << "Teléfono: " << actual->dato.getNroTelefono() << endl;
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
        NodoArbol<Contact>* miNodo = miAgenda.getCabeza();
        cout<< endl;
        buscarContactoRecursivo(name,miNodo);
    }
}

bool esMayor(NodoArbol<Contact>*& miNodo, Contact val) {
    if (miNodo->dato.getNombre() > val.getNombre()) {
        return true;
    } else {
        return false;
    }
}

void Agenda::buscarContactoRecursivo(const string& name, NodoArbol<Contact>* miNodo){
    if (miNodo){
        if (miNodo->dato.getNombre() == name){
            datosUser(&(miNodo->dato)); //direccion de memoria(puntero)
        } else if (miNodo->dato.getNombre() > name) {
            return buscarContactoRecursivo(name, miNodo->min);
        } else {
            return buscarContactoRecursivo(name, miNodo->max);
        }
        
    } else {
        cout<< "EL CONTACTO NO FUE ENCONTRADO" << endl;
        cout<< endl;
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

