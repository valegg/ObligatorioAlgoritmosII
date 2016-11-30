#ifndef NODOAB_H
#define NODOAB_H

#include <iostream>
#include <assert.h>

template <class U>
class NodoAB {
	public:
		U dato;
		NodoAB<U> *izq;
		NodoAB<U> *der;
		unsigned int auxiliar;

		NodoAB(const U &e) : dato(e), izq(NULL), der(NULL), auxiliar(0) {}
		NodoAB(const U &e, NodoAB<U> *i, NodoAB<U> *d) : dato(e), izq(i), der(d), auxiliar(0) {}
		virtual ~NodoAB() {}

	private:
		NodoAB<U> &operator=(const NodoAB<U> &n) { assert(false); }
		NodoAB(const NodoAB<U> &n) : dato(n.dato), izq(n.izq), der(n.der), auxiliar(n.auxiliar) {}
};

#endif