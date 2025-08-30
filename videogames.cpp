#include <iostream>
#include <iomanip>
#include "videogames.h"

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;

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

string obtenerCategoria( int codigoJuego ) {
    if( codigoJuego > 0 || codigoJuego < 13 ) {
        return catalogo[ codigoJuego - 1 ].categoria;
    } else {
        cout << "Codigo Invalido" << endl;
    }
}

void agregarJuegoAlCarrito( int codigos[ ], int cantidades[ ], int &cantidadJuegosRegistrados ) {
    if( cantidadJuegosRegistrados >= MAX_ITEMS ) {
        cout << "Ups! El carrito esta lleno" << endl;
        return;
    }
    int codigo, cantidad;
    codigo = leerCodigoJuego( );
    cantidad = leerCantidadJuego( );
    for( int i = 0; i < cantidadJuegosRegistrados; i++ ) {
        if( codigos[ i ] == codigo ) {
            cantidades[ i ] += cantidad;
            cout << "Producto Actualizado: " << obtenerNombreJuego( codigo ) << " x " << cantidades[ i ] << " ( Cantidad Acumulada )" << endl;
            return;
        }
    }

    codigos[ cantidadJuegosRegistrados ] = codigo;
    cantidades[ cantidadJuegosRegistrados ] = cantidad;
    cantidadJuegosRegistrados++;

    cout << "Producto Agregado: " << obtenerNombreJuego( codigo ) << " x " << cantidad << "\n" << endl;
}

double calcularSubtotalCarrito( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados ) {
    double subtotal = 0.0;
    for( int i = 0; i < cantidadJuegosRegistrados; i++ ) {
        int precioUnitario = obtenerPrecioJuego( codigos[ i ] );
        subtotal += precioUnitario * cantidades[ i ];   
    }
    return subtotal;
}

int leerTipoCliente( ) {
    int opcion;
    cout << "SELECCIONE SU MEMBRESIA\n" << endl;
    cout << "1. ORO" << endl;
    cout << "2. PLATA" << endl;
    cout << "3. REGULAR" << endl;
    cin >> opcion; 
    while( opcion < 1 || opcion > 3 ) {
        cout << "Opcion No Valida. Ingrese de nuevo ( 1 - 3 )" << endl;
        cin.clear( );
        cin.ignore(10000, '\n' );
        cin >> opcion;

    }
    return opcion;
}

double obtenerPorcentajeDescuento( int tipoCliente ) {
    if( tipoCliente == 1 ) {
        return OFF_ORO;
    }
    if( tipoCliente == 2 ) {
        return OFF_PLATA;
    }
    return OFF_REGULAR;
}

double calcularDescuentosAdicionales( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados ) {
    int ps5, pc, xbox, switch_;
    for( int i = 0; i < cantidadJuegosRegistrados; i++ ) {
        if( catalogo[ codigos[ i ] - 1 ].plataforma == "( PS5 )   " ) {
            ps5 += cantidades[ i ];
        }
        if( catalogo[ codigos[ i ] - 1 ].plataforma == "( PC )    " ) {
            pc += cantidades[ i ];
        }
        if( catalogo[ codigos[ i ] - 1 ].plataforma == "( XBOX )  " ) {
            xbox += cantidades[ i ];
        }
        if( catalogo[ codigos[ i ] - 1 ].plataforma == "( Switch )" ) {
            switch_ += cantidades[ i ];
        }
    }
    if( ps5 >= 2 && xbox < 5 && pc < 3 ) {
        return OFF_PS5;
    }
    if( xbox >= 5 && ps5 < 2 && pc < 3 ) {
        return OFF_XBOX;
    } 
    if( pc >= 3 && ps5 < 2 && xbox < 5 ) {
        return OFF_PC;
    }

    return 0.0;
}

double calcularTotalFinal( double subtotal, double porcentajeDescuento, double descuentosAdicionales ) {
    double desucentoTotal = porcentajeDescuento + descuentosAdicionales;
    double total = subtotal * ( 1.0 - desucentoTotal );
    return total;
}

void mostrarResumenCompra( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados, double porcentajeDescuento, double descuentosAdicionales ) {
    cout << "======== RESUMEN DEL PEDIDO ========" << "\n\n";
    for( int i = 0; i < cantidadJuegosRegistrados; i++ ) {
        int precioUnitario = obtenerPrecioJuego( codigos[ i ] );
        cout << obtenerNombreJuego( codigos[ i ] ) << " x " << cantidades[ i ] << "   $" << precioUnitario * cantidades[ i ] << endl;
    }
    double subtotal = calcularSubtotalCarrito( codigos, cantidades, cantidadJuegosRegistrados );
    cout << "\nSubtotal:  $" << fixed << setprecision( 2 ) << subtotal << "  ( Sin descuentos )\n\n";
    double total = calcularTotalFinal( subtotal, porcentajeDescuento, descuentosAdicionales );
    cout << "\nTotal:     $" << fixed << setprecision( 2 ) << total << "  ( Con descuentos )\n\n";
}