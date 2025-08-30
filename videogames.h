#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <string>

using std::string;

const int MAX_ITEMS = 50;
const int GAMES = 12;

struct juego {
    int id;
    string nombre;
    string plataforma;
    string categoria;
    double precio;
};

extern juego catalogo[ GAMES ];

//Descuentos
const double OFF_ORO = 0.15;
const double OFF_PLATA = 0.08;
const double OFF_REGULAR = 0.00;


void mostrarCatalogoJuegos( );
int leerCodigoJuego( );
int leerCantidadJuegos( );
string obtenerNombreJuego( int codigoJuego );
int obtenerPrecioJuego( int codigoJuego );
string obtenerPlataforma( int codigoJuego );
string obtenerCategoria( int codigoJuego );
void agregarJuegoAlCarrito( int codigos[ ], int cantidades[ ], int &cantidadJuegosRegistrados );
double calcularSubtotalCarrito( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados );
int leerTipoCliente( );
double obtenerPorcentajeDescuento( int tipoCliente );
double calcularDescuentosAdicionales( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados );
double calcularTotalFinal( double subtotal, double porcentajeDescuento, double descuentosAdicionales );
void mostrarResumenCompra( const int codigos[ ], const int cantidades[ ], int cantidadJuegosRegistrados, double porcentajeDescuento );
void cargarCompraDemo( int codigos[ ], int cantidades[ ], int &cantidadJuegosRegistrados );

#endif