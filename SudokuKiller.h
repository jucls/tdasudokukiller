/**
  * @file SudokuKiller.h
  * @brief Fichero cabecera del TDA Sudoku Killer
  *
  */

#ifndef __SUDOKUKILLER
#define __SUDOKUKILLER

#include <iostream>
#include "Arbol.h"


using namespace std;

/**
  *  @brief T.D.A. Sudoku Killer
  *
  * Una instancia @e c del tipo de datos abstracto @c Sudoku Killer es un objeto
  * que almacena el contenido de una matriz tridimensional que representa al tablero de	diferentes formas. 
  *
  * En la resolución de este problema lo representará de dos formas, 
  *	1. Tablero: representa al juego del sudoku, todos los posibles valores en cada casilla.
  	2. Tablero fantasma: representa un "tablero auxiliar o no real" que contendrá el valor de las sumas y su asignación para operar con ello. 
  *
  * 
  *
  * @author Jaime Castillo Uclés
  * @date Octubre 2021
  */
template < class M >
class SudokuKiller {
 private:
	 M ***datos;
 	 int fila, columna, values[i]; //Tablero del sudoku
 	
 public:
 

/**
  * @brief Constructor por defecto de la clase. Crea el tablero.
  */
  SudokuKiller();

/**
  * @brief Constructor con tres parametros, filas, columnas y values. Si tiene un valor fijo se quedará values con un elemento.
  * @param fil Filas de la matriz
  * @param cols Columnas de la matriz
  * @param values[i] Vector de valores de cada casilla
  * @return el nuevo tablero
  */
  
  SudokuKiller(int fil, int col, int values[i]);
/**
  * @brief Destructor de la clase
  * 
  */
 ~SudokuKiller();

/**
  * @brief Obtenemos los valores de cada casilla
  * @param fil Filas de la matriz
  * @param col Columnas de la matriz
  * @param datos Puntero objeto
  * @return el vector asociado a los posibles números de esa casilla
  */ 
  int getValues (int fil, int col, const M &datos);

/**
  * @brief Detecta que una casilla en concreto solo tiene un elemento, es decir, está resuelta
  * @param fil Fila del tablero
  * @param col Columna del tablero
  * @param datos Puntero objeto
  */
 void find(int fil, int col, const M &datos);
/**
  * @brief Borramos un elemento de Values
  * @param fil Filas del tablero
  * @param col Columna del tablero
  * @param Se le pasa el árbol (en este caso, el nodo) que hemos podado en el árbol y queremos descartar
  */  
 void descartando(int fil, int col, const M &datos, Arbol arbol);
 /**
  * @brief Actualiza el vector de values[i] para quitar todos los valores y dejar un solo valor por cada casilla según venga el árbol
  * @param datos Puntero a los datos de tablero
  * @param arbol Arbol que es solución del sudoku
  */  
 void SolucionEncontrada(const M &datos, Arbol arbol);
  /**
  * @brief Devuelve el vector de posibles valores que puede tomar la casilla según las sumas
  * @param i Posición de fila de la casilla
  * @param j Posición de columna de la casilla
  * @param tablero_fantasma  Matriz tridimensional que asigna el número ordinal de cada suma, con el valor de la suma, y número de casilla
  * @return Devuelve un array de values, que son los valores posibles de cada casilla según las sumas
  * 
  */   
  int CuanticValue(int i, int j, SudokuKiller tablero_fantasma, SudokuKiller &tablero);

};




#endif SUDOKUKILLER_H




