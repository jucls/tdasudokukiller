/**
  * @file Arbol.h
  * @brief Fichero cabecera del TDA Arbol
  *
  */

#ifndef __ARBOL
#define __ARBOL

#include <iostream>
#include "SudokuKiller.h"


using namespace std;

/**
  *  @brief T.D.A. Arbol
  *
  * Una instancia @e c del tipo de datos abstracto @c Arbol es un objeto
  * que almacena el contenido de un árbol n-ario con capacidad de ser variante. Contiene m etiquetas de tipo T 
  * distribuidas en m nodos donde cada nodo puede tener hasta n hijos situados en las posiciones [0, n-1]
  *
  * Tiene incorporada la clase Nodo.
  *
  * @author  Jaime Castillo Uclés
  * @date Octubre 2021
  */
template < typename T>
class Arbol {
 private:
 	size_t N;
	 struct Celda {       
	      T etiqueta;        ///< Valor que contiene el nodo
	      Celda * padre;///< Puntero del padre del nodo
	      vector<Celda*> hijos;

	      
	      Celda(size_t n, const T & elem): etiqueta(elem), padre(nullptr), hijos(n, nullptr){
	      }
	    };

    	Celda * primera; ///< Puntero al primer nodo de la lista.
 	
 	
 	


 public:
 
/*
* @brief T.D.A. Nodo
*
*/
 	class Nodo{
 		Celda * pnodo;
 		public:
 		/*
 		* Sin entrar en estas funciones, nos permiten movernos y conocer la estructura del árbol. Son esenciales para que funcione en este caso ya que no tenemos iteradores, el árbol.
 		*/
 		//...
 	}

/**
  * @brief Constructor por defecto de la clase. Crea un árbol nulo.
  */
  Arbol();
/**
  * @brief Destructor de la clase
  */
  ~Arbol();
/**
  * @brief Constructor de la clase con parametros.
  * @param tablero Tablero del sudoku
  */
  Arbol(SudokuKiller tablero);
/**
  * @brief Se crean árboles de un nodo mediante el constructor y se injertan como parte del aŕbol principal
  * @param n nodo del que parte el subárbol que se va a generar
  * @param i Altura del nodo
  * @return Devuelve un árbol
  */
 Arbol injertarHijo(Nodo n,size_t i, Arbol &arbol);

/**
  * @brief Constructor de copias de la clase
  * @param c Arbol a copiar
  */
  Arbol (const Arbol && c);  

/**
  * @brief Elimina directamente el árbol que cuelga de n
  * @param n número del hijo que se quiere podar
  * @return Devuelve el arbol que se ha eliminado.
  */ 
  Arbol podar(Nodo n);
  

/**
  * @brief Copia el subárbol que cuelga de n y lo devuelve como un nuevo árbol
  * @param n nodo desde que el que se hace la copia
  * @return Devuelve un nuevo árbol
  */
  Arbol copiaProfunda(Nodo n) const;
  /**
  * @brief Comprueba si el nodo n es un nodo del árbol. No es una función estrictamente necesaria, pero puede ayudar a hacer más flexible el main.
  * @param n nodo que se comprueba
  * @return Devuelve true si es un nodo del árbol
  */
  bool contiene(Nodo n) const;
  /**
  * @brief Intercambia los contenidos de dos arboles. No es una función estrictamente necesaria, pero puede ayudar a hacer más flexible el main.
  */
  void swap (Arbol &arbol) ;
  
/**
  * @brief Sobrecarga del operador ==
  * @param r árbol a comparar con el objeto implícito árbol
  * @return Devuelve 0 si este objeto es igual a r
  */  
  bool operator ==(const Arbol r );
  
 /**
  * @brief Sobrecarga del operador !=
  * @param r árbol a comparar con el objeto implícito árbol
  * @return Devuelve 0 si este objeto es igual a r
  */  
  bool operator !=(const Arbol &r);


/************* FUNCIONES ESPECIALES *********/
/*
* @brief Comprueba que los valores de un subárbol resuelven el sudoku. No hay valores repetidos en las filas, columnas y cuadrados
* @param tablero Tablero del Sudoku
* @param arbol Arbol en el cual estamos buscando
* @param rama subarbol el cual se quiere comprobar que es solución
* @return Devuelve un boolean que será true si es solución esa rama
*/
 bool ComprobarRama(SudokuKiller &tablero, Arbol &arbol, Arbol rama);
/**
  * @brief Selecciona algunos nodos de los posibles filtrados por el vector de values de CuanticValue, antes que otros, para guiar la búsqueda en el aŕbol
  * @param tablero Tablero del sudoku (Matriz que contiene los valores que sabemos)
  * @param tablero_fantasma  Matriz tridimensional que asigna el número ordinal de cada suma, con el valor de la suma, y número de casilla (ej: para la casilla de la fila 1 comlumna 1 sería 11)
  * @return Devuelve un valor de los valores de values, o lo que es lo mismo el nodo por el cuál empezar a buscar
  * 
  */   
  int ValueNet(int i, int j, SudokuKiller tablero, SudokuKiller tablero_fantasma, Arbol &arbol);
/**
  * @brief Selecciona alguna casilla de las que faltan por completar para guiar la búsqueda del árbol
  * @param tablero Tablero del sudoku (Matriz que contiene los valores que sabemos)
  * @param tablero_fantasma  Matriz tridimensional que asigna el número ordinal de cada suma, con el valor de la suma, y número de casilla
  * @return Devuelve la posición de la casilla
  * 
  */   
  int PolicyNet(SudokuKiller tablero, SudokuKiller tablero_fantasma);

 
};

#endif ARBOL_H
