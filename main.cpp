#include <iostream>
#include "videogames.h"

using std::cout;
using std::endl;
using std::cin;

void mostrarMenuPrincipal( ) {
    cout << "\n====== GAME - STORE - Menu Principal ======\n";
    cout << "1. Mostrar Catalogo de productos\n";
    cout << "2. Añadir producto al carrito\n";
    cout << "3. Ver resumen del pedido\n";
    cout << "4. Finalizar y pagar\n";
    cout << "5. Prediligenciar productos de demostracion\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion:  ";
}

int main( ) {
    cout << "\n------- BIENVENIDO A GAME - STORE -------" << endl;
    int opcion;
    do {
        mostrarMenuPrincipal( );
        cin >> opcion;
        switch( opcion ) {
            case 1:
                mostrarCatalogoJuegos( );
                break;
            case 2:

            case 3:

            case 4:

            case 5:

            case 0:
                cout << "Saliendo del Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while( opcion != 0 );
    return 0;
}