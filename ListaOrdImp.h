#ifndef LISTAORDIMP_H
#define LISTAORDIMP_H

#include <assert.h>
#include "ListaOrd.h"
#include "IteradorListaOrdImp.h"
#include "NodoLista.h"

template <class T>
class IteradorListaOrdImp;

template <class T>
class ListaOrdImp: public ListaOrd<T> {
	friend class IteradorListaOrdImp<T>; 
	friend ostream &operator<< <>(ostream& o, const ListaOrdImp<T> & l);
public:

	// Constructor por defecto
	ListaOrdImp();

	// Constructor copia
	ListaOrdImp(const ListaOrd<T> &l);
	ListaOrdImp(const ListaOrdImp<T> &l);

	// Operador de asignacion
	ListaOrd<T> &operator=(const ListaOrd<T> &l);
	ListaOrd<T> &operator=(const ListaOrdImp<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	ListaOrd<T>* CrearVacia() const;
	virtual ~ListaOrdImp();

	void AgregarOrd(const T &e);
	void BorrarMinimo();	
	void BorrarMaximo();
	void Borrar(const T &e);

	const T& Minimo() const;
	const T& Maximo() const;

	const T& Recuperar(const T&) const; 
	bool Existe(const T &e) const;	

	void Vaciar();

	unsigned int CantidadElementos() const;

	bool EsVacia() const;
	bool EsLlena() const;

	ListaOrd<T>* Clon() const;

	Iterador<T> GetIterador() const;
	void Imprimir(ostream& o) const;

protected:
	void AgregarOrdAux(NodoLista<T> *nodo, const T &e);
	void BorrarAux(NodoLista<T> *nodo, const T &e);
	void AgregarPpio(const T &e);
	void AgregarFin(const T &e);

	// Atributos
	NodoLista<T> *ppio; //Puntero al ppio de la lista
	NodoLista<T> *fin; //Puntero al fin de la lista

	unsigned int largo; //Lleva la cuenta de la cantidad de elementos de la lista
};

#include "ListaOrdImp.cpp"

#endif