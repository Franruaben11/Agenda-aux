#ifndef CONTACT_H
#define CONTACT_H

#include "Lista.h"
#include <string>

using namespace std; // Agregamos using namespace std


// struct nodoSocialMedia {
//     string dato;
//     nodoSocialMedia* ste;
// };


class Contact {
private:
    string nombre;
    string numeroTelefono;
    string email;
    string direccion;
    string fechaCumpleanios;
    string nombreEmpresa;
    string puesto;
    string descripcion;
    // nodoSocialMedia* redesSociales;
    Lista<string> redesSociales;
    void getRedesSocialesRecursivo() const;
    // void limpiar(nodoSocialMedia* miNodo);

public:
    Contact();
    Contact(string name, string nroTel, string email, string direccion, string fechaCumpleanios, string nombreEmpresa, string puesto, string descripcion, string socialMedia);
    // ~Contact(); //error cuando ejecuto toda la agenda o AVL

    bool operator==(Contact miNombre);

    void setNombre(string name);
    string getNombre() const;

    void setNroTelefono(string numeroTelefono);
    string getNroTelefono() const;

    void setEmail(string email);
    string getEmail() const;

    void setDireccion(string direccion);
    string getDireccion() const;

    void setFechaCumpleanios(string fechaCumpleanios);
    string getFechaCumpleanios() const;

    void setEmpresa(string nombreEmpresa);
    string getEmpresa() const;

    void setPuesto(string puesto);
    string getPuesto() const;

    void setDescripcion(string descripcion);
    string getDescripcion() const;

    void setRedesSociales(string redSocial);
    void getRedesSociales() const;

};

#endif
