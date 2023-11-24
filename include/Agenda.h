#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED


#include "Avl.h"
#include "Contact.h"
#include "Lista.h"

class Agenda{
private:
    Avl<Contact> miAgenda;
    void datosUser(Contact* miUser)const;
    void mostrarRecursivo(const Lista<Contact>& miLista)const;
    void buscarContactoRecursivo(const string& name, NodoArbol<Contact>* miNodo);

public:
    Agenda();
    ~Agenda();
    void agregarContacto(const Contact& miContacto);
    void mostrarContactos(Lista<Contact> miLista);
    void eliminarContacto(const string& miName);
    void buscarContacto(const string& miName);
};

#endif 
