#include <iostream>
#include "../include/Contact.h"

using namespace std;

// Constructor por defecto
Contact::Contact()
    : nombre(""), numeroTelefono(""), email(""), direccion(""), fechaCumpleanios(""),
      nombreEmpresa(""), puesto(""), descripcion(""), redesSociales() {}

// Constructor con parámetros
Contact::Contact(string name, string nroTel, string email, string direccion, string fechaCumpleanios, string nombreEmpresa, string puesto, string descripcion, string socialMedia)
    : nombre(name), numeroTelefono(nroTel), email(email), direccion(direccion), fechaCumpleanios(fechaCumpleanios),
      nombreEmpresa(nombreEmpresa), puesto(puesto), descripcion(descripcion), redesSociales() {
    setRedesSociales(socialMedia);
}

//  SI LO IMPLEMENTO SOLO CON LA CLASE CONTACT FUNCIONA PERFECTO, PERO
//  CUANDO LO IMPLEMENTO CON LA AGENDA ME GENERA ERROR!.

//  LA RAZON POR LA CUAL QUERIA USAR EL DESTRUCTOR ES POR LA LISTA DE LAS REDES SOCIALES

// Contact::~Contact(){ 
//     limpiar(redesSociales);
// }

// void Contact::limpiar(nodoSocialMedia* miNodo){
//     if (miNodo != nullptr){
//         limpiar(miNodo->ste);
//         delete miNodo;
//     }
// }

// Operador de igualdad
bool Contact::operator==(Contact miNombre) {
    return this->nombre == miNombre.nombre;
}


// Setter y Getter para el nombre
void Contact::setNombre(string name) {
    this->nombre = name;
}

string Contact::getNombre() const {
    return this->nombre;
}

// Setter y Getter para el número de teléfono
void Contact::setNroTelefono(string numeroTelefono) {
    this->numeroTelefono = numeroTelefono;
}

string Contact::getNroTelefono() const {
    return this->numeroTelefono;
}

// Setter y Getter para el correo electrónico
void Contact::setEmail(string email) {
    this->email = email;
}

string Contact::getEmail() const {
    return this->email;
}

// Setter y Getter para la dirección
void Contact::setDireccion(string direccion) {
    this->direccion = direccion;
}

string Contact::getDireccion() const {
    return this->direccion;
}

// Setter y Getter para la fecha de cumpleaños
void Contact::setFechaCumpleanios(string fechaCumpleanios) {
    this->fechaCumpleanios = fechaCumpleanios;
}

string Contact::getFechaCumpleanios() const {
    return this->fechaCumpleanios;
}

// Setter y Getter para el nombre de la empresa
void Contact::setEmpresa(string nombreEmpresa) {
    this->nombreEmpresa = nombreEmpresa;
}

string Contact::getEmpresa() const {
    return this->nombreEmpresa;
}

// Setter y Getter para el puesto en la empresa
void Contact::setPuesto(string puesto) {
    this->puesto = puesto;
}

string Contact::getPuesto() const {
    return this->puesto;
}

// Setter y Getter para la descripción
void Contact::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Contact::getDescripcion() const {
    return this->descripcion;
}


void Contact::setRedesSociales(string redSocial) {

    redesSociales.agregarElemento(redSocial);
}


void Contact::getRedesSociales() const {
    redesSociales.mostrarLista();
}


// Mostrar las redes sociales
void Contact::getRedesSocialesRecursivo() const {
    cout<< "Redes Sociales de " << nombre << ":" << endl;



}

