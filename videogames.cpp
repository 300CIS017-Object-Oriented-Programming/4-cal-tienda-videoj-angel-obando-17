#include <iostream>
#include "videogames.h"

using std::cout;
using std::endl;
using std::cin;

juego catalogo[ GAMES ] = { { 1,  "Grand Theft Auto V   ", "( PC )    ", "[ Accion ]    ", 79156 }, 
                            { 2,  "God Of War ( 2018 )  ", "( PS5 )   ", "[ Accion ]    ", 184000 },
                            { 3,  "Half-Life 2          ", "( PC )    ", "[ Accion ]    ", 26000 },
                            { 4,  "Red Dead Redemption 2", "( PC )    ", "[ Aventura ]  ", 159900 },
                            { 5,  "The Witcher 3        ", "( XBOX )  ", "[ Aventura ]  ", 129999 },
                            { 6,  "Hollow Knight        ", "( PC )    ", "[ Aventura ]  ", 18750 },
                            { 7,  "FC25                 ", "( PS5 )   ", "[ Deportes ]  ", 279999 },
                            { 8,  "Tony Hawk - Pro Skate", "( Switch )", "[ Deportes ]  ", 220199 },
                            { 9,  "WWE 2K25             ", "( XBOX )  ", "[ Deportes ]  ", 289900 },
                            { 10, "Portal 2             ", "( PC )    ", "[ Estrategia ]", 26000 },
                            { 11, "Age of Empires IV    ", "( XBOX )  ", "[ Estrategia ]", 82500 },
                            { 12, "Civilization VII     ", "( Switch )", "[ Estrategia ]", 269699 } };


void mostrarCatalogoJuegos( ) {
    int opcion;
    do {
        cout << "\n------Catalogo de Juegos------" << endl;
        cout << "\n---Selecciona una categoria---" << endl;
        cout << "1. Accion" << endl;
        cout << "2. Aventura" << endl;
        cout << "3. Deportes" << endl;
        cout << "4. Estrategia" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch( opcion ) {
            case 1:
                for( int i = 0; i < GAMES - 9; i++ ) {
                    juego actual = catalogo[ i ];
                    cout << actual.id << ". " << actual.nombre << " " << actual.plataforma << " " << actual.categoria << " $" << actual.precio << endl;
                }
                break;
            case 2:
                for( int i = 3; i < GAMES - 6; i++ ) {
                    juego actual = catalogo[ i ];
                    cout << actual.id << ". " << actual.nombre << " " << actual.plataforma << " " << actual.categoria << " $" << actual.precio << endl;
                }
                break;
            case 3:
                for( int i = 6; i < GAMES - 3; i++ ) {
                    juego actual = catalogo[ i ];
                    cout << actual.id << ". " << actual.nombre << " " << actual.plataforma << " " << actual.categoria << " $" << actual.precio << endl;
                }
                break;
            case 4:
                for( int i = 9; i < GAMES; i++ ) {
                    juego actual = catalogo[ i ];
                    cout << actual.id << ". " << actual.nombre << " " << actual.plataforma << " " << actual.categoria << " $" << actual.precio << endl;
                }
                break;
            case 0:
                cout << "Saliendo del Catalogo de Juegos..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while( opcion != 0 );
}

int leerCodigoJuego( ) {
    cout << "Ingrese el codigo del producto ( 1 - 12 ): ";
    int codigo;
    cin >> codigo;
    while ( codigo < 1 || codigo > 12 ) {
        cout << "Codigo inválido. Intente de nuevo ( 1 - 12 ): ";
        cin.clear( );
        cin.ignore(10000, '\n' );
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadJuego( ) {
    cout << "Ingrese la cantidad ( 1 - 20 ): ";
    int cantidad;
    cin >> cantidad;
    while( cantidad < 1 || cantidad > 20 ) {
        cout << "Cantidad invalida. Intente de nuevo ( 1 - 20 ): ";
        cin.clear( );
        cin.ignore(10000, '\n' );
        cin >> cantidad;
    }
    return cantidad;
}


string obtenerNombreJuego( int codigoJuego ) {
    if( codigoJuego > 0 || codigoJuego < 13 ) {
        return catalogo[ codigoJuego - 1 ].nombre;
    } else {
        cout << "Codigo Invalido" << endl;
    }
}

int obtenerPrecioJuego( int codigoJuego ) {
    if( codigoJuego > 0 || codigoJuego < 13 ) {
        return catalogo[ codigoJuego - 1 ].precio;
    } else {
        cout << "Codigo Invalido" << endl;
    }
}

string obtenerPlataforma( int codigoJuego ) {
    if( codigoJuego > 0 || codigoJuego < 13 ) {
        return catalogo[ codigoJuego - 1 ].plataforma;
    } else {
        cout << "Codigo Invalido" << endl;
    }
}


