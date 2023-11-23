#include <iostream>
#include "include/Avl.h"
#include "include/Contact.h"
#include "src/Contact.cpp"
#include "src/Avl.cpp"
#include "src/Agenda.cpp"
#include "include/Agenda.h"
#include "include/Lista.h"
#include "src/Lista.cpp"

using namespace std;

int main(){
    //Constructor
    Agenda miAgenda;

    //CrearContactos
    Contact contacto1("Bautista", "123-456-7890", "juan@example.com", "Calle 123", "1990-05-15", "Empresa A", "Analista", "Amigo", "@bautistaAnalista");
    Contact contacto2("Maria", "1234", "maria@gmail.com", "Calle Principal 123", "01/05/1995", "Google", "Ingeniera", "Tiempo Completo", "@mariagomez");
    Contact contacto3("Jeronimo", "5678", "juan@hotmail.com", "Avenida Central 456", "15/09/1980", "Microsoft", "Analista", "Medio Parcial", "@juansilva");
    Contact contacto4("Luisa", "9876", "luisa@yahoo.com", "Calle Secundaria 789", "03/12/1990", "Apple", "Diseñadora", "Tiempo Imparcial", "@luisamartinez");
    Contact contacto5("Aaron", "4321", "pedro@gmail.com", "Avenida Norte 321", "28/07/1988", "Amazon", "Desarrollador", "Tiempo Completo", "@pedromartinez");
    Contact contacto6("Antony", "1234", "Antonyyyro@gmail.com", "Avenida Sur 321", "28/10/2008", "Amazon", "Comerciante", "Tiempo Completo", "@tonytony");
    Contact contacto7("Carlos", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    Contact contacto8("Benjamin", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    Contact contacto9("Berenisse", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    Contact contacto10("Bernardo", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    Contact contacto11("Baltasar.", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    Contact contacto12("Bruno", "432", "cahrles@gmail.com", "Avenida Noreste 321", "28/10/1998", "Meta", "Comerciante", "Tiempo Completo", "@daMelio");
    


    //AgregarContactos
    miAgenda.agregarContacto(contacto1);
    miAgenda.agregarContacto(contacto2);
    miAgenda.agregarContacto(contacto3);
    miAgenda.agregarContacto(contacto4);
    miAgenda.agregarContacto(contacto5);
    miAgenda.agregarContacto(contacto6);
    miAgenda.agregarContacto(contacto7);
    miAgenda.agregarContacto(contacto8);
    miAgenda.agregarContacto(contacto9);
    miAgenda.agregarContacto(contacto10);
    miAgenda.agregarContacto(contacto11);
    miAgenda.agregarContacto(contacto12);

    //MostrarContactos
    miAgenda.mostrarContactos();

    //BuscarContacto (existente)
    miAgenda.buscarContacto("Luisa");
    

    //EliminarContactos
    miAgenda.eliminarContacto("Juan");
    miAgenda.eliminarContacto("Luisa");
    miAgenda.eliminarContacto("Maria");

    cout << "POST-BORRADO" << endl;     
    
    //BuscarContacto (no existente)
    miAgenda.buscarContacto("Luisa");

    //MostrarContactos (post-borrar)
    miAgenda.mostrarContactos();


    return 0;
};



// int main() {
//     // Crear una lista de enteros
//     Lista miLista;



//     // Agregar elementos a la lista
//     miLista.agregarElemento("pepe");
//     miLista.agregarElemento("franco");
//     miLista.agregarElemento("robert");

//     // Mostrar la lista
//     cout << "Lista actual: ";
//     miLista.mostrarLista();

//     // Agregar más elementos
//     miLista.agregarElemento("camba");
//     miLista.agregarElemento("tino");

//     // Mostrar la lista después de agregar más elementos
//     cout << "Lista después de agregar más elementos: ";
//     miLista.mostrarLista();

//     miLista.eliminarElemento("franco", miLista.obtenerCabeza());
//     cout << "Lista después de eliminar elementos: ";
//     miLista.mostrarLista();

//     return 0;
// }
