#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED


#include "Avl.h"
#include "Contact.h"

class Agenda{
private:
    Avl<Contact> miAgenda;
    void datosUser(Contact* miUser)const;

public:
    Agenda();
    ~Agenda();
    void agregarContacto(const Contact& miContacto);
    void mostrarContactos() const;
    void eliminarContacto(const string& miName);
    void buscarContacto(const string& miName);
    
};

#endif 
