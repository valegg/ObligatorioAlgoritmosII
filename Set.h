#pragma once

#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Set;

template <class T>
ostream &operator<< <>(ostream& out, const Set<T> &s) {
	s.Imprimir(out);
	return out;
}

template <class T>
class Set abstract {
public:
	// PRE: -
	// POS: Destructor
	virtual ~Set() { }

	//PRE:-
	//POS: Retorna un nuevo Set vacio que no comparte memoria
	virtual Set<T>* CrearVacio() const abstract;

	//PRE:-
	//POS: Retorna un nuevo Set igual a this que no comparte memoria
	virtual Set<T>* Clon() const abstract;

	// PRE: !EsLleno()
	// POS: Pertenece(e)
	virtual void Insertar(const T &e) abstract;

	// PRE: -
	// POS: !Pertenece(e)
	//	Usa el operador == del elemento e para encontrar uno igual.
	//	Si no encuentra no tiene efecto
	virtual void Borrar(const T &e) abstract;

	// PRE: !EsVacio()
	// POS: Retorna un elemento cualquiera del Set 
	virtual const T& Elemento() const abstract;

	// PRE: Pertenece(e)
	// POS: Retorna el elemento igual a e
	//		Usa el operador == del elemento para encontrar uno igual
	virtual const T& Recuperar(const T &e) const abstract;

	// PRE: -
	// POS: Busca si existe un elemento que sea igual a e
	//		Usa el operador == del elemento para encontrar uno igual
	virtual bool Pertenece(const T &e) const abstract;

	// PRE: -
	// POS: EsVacio()
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna true si y solo si el Set no tiene elementos
	virtual bool EsVacio() const abstract;

	// PRE: -
	// POS: Retorna true si y solo si el Set esta lleno
	virtual bool EsLleno() const {
		return false;
	}

	// PRE: -
	// POS: Retorna la cantidad de elementos del Set
	virtual unsigned int Cardinal() const abstract;

	// PRE: -
	// POS: Retorna un nuevo Set que es la union de this y s,
	//		o sea, el conjunto que contiene los elementos de this y de s
	//		No se debe modificar a s (aunque falte el const en el par�metro)
	virtual Set<T>* Union(Set<T>& s) const abstract;

	// PRE: -
	// POS: Retorna un nuevo Set que es la intersecci�n de this y s,
	//		o sea, el conjunto que contiene solo los elementos comunes a this y s 	
	//		No se debe modificar a s (aunque falte el const en el par�metro)
	virtual Set<T>* Interseccion(Set<T>& s) const abstract;

	// PRE: -
	// POS: Retorna un nuevo Set que es la diferencia entre this y s,
	//		o sea, el conjunto que contiene solo los elementos que estan en this pero no en s	
	//		No se debe modificar a s (aunque falte el const en el par�metro)
	virtual Set<T>* Diferencia(Set<T>& s) const abstract;

	//PRE: -
	//POS: Retorna si todos los elementos de this pertenecen a s
	virtual bool ContenidoEn(const Set<T> &s) const abstract;

	// PRE: -
	// POS: Retorna si this y s contienen los mismos elementos 
	virtual bool operator==(const Set<T> &s) const abstract;

	// PRE: -
	// POS: *this == s y no comparten memoria
	virtual Set<T> &operator=(const Set<T> &s) abstract;

	//PRE:-
	//POS: Se llama desde el operator<<. Imprime el objeto
	virtual void Imprimir(ostream& o) const abstract;
protected:

	Set() { }
	Set(const Set &l) { assert(false); }

};

#endif