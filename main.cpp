#include <iostream>
#include <iomanip>
#include "videogames.h"

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;

void mostrarMenuPrincipal( ) {
    cout << "\n====== GAME - STORE - Menu Principal ======\n";
    cout << "1. Mostrar Catalogo de productos\n";
    cout << "2. Añadir producto al carrito\n";
    cout << "3. Ver resumen del pedido\n";
    cout << "4. Finalizar y pagar\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion:  ";
}

int main( ) {
    int codigos[ MAX_ITEMS ] = { 0 };
    int cantidades[ MAX_ITEMS ] = { 0 };
    int cantidadItems = 0; 

    cout << "\n------- BIENVENIDO A GAME - STORE -------" << endl;
    int opcion;
    do {
        mostrarMenuPrincipal( );
        cin >> opcion;
        switch( opcion ) {
            case 1: {
                mostrarCatalogoJuegos( );
                break;
            }
            case 2: {
                agregarJuegoAlCarrito( codigos, cantidades, cantidadItems );
                break;
            }
            case 3: {
                cout << "====== RESUMEN DEL PEDIDO ======" << "\n\n";
                for( int i = 0; i < cantidadItems; i++ ) {
                    cout << obtenerNombreJuego( codigos[ i ] ) << " x " << cantidades[ i ] << endl;
                }
                double subtotal = calcularSubtotalCarrito( codigos, cantidades, cantidadItems );
                cout << "\nSubtotal:  $" << fixed << setprecision( 2 ) << subtotal << "\n\n";
                break;
            }
            case 4:
                break;
            case 0:
                cout << "Saliendo del Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while( opcion != 0 );
    return 0;
}