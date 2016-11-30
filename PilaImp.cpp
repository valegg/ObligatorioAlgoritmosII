#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const PilaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
PilaImp<T>::PilaImp() {
	list = NULL;
	length = 0;
}

template<class T>
PilaImp<T>::PilaImp(const Pila<T>& p) {
	this = p.Clon();
}

template<class T>
PilaImp<T>::PilaImp(const PilaImp<T>& p) {
	this = p.Clon();
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) {
	Pila<T>* auxP = p.Clon();
	Pila<T>* aux = new PilaImp<T>();
	while (!auxP->EsVacia()) {
		aux->Push(auxP->Pop());
	}
	while (!aux->EsVacia()) {
		this->Push(aux->Pop());
	}
	return *this;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const PilaImp<T>& p) {
	Pila<T>* auxP = p.Clon();
	Pila<T>* aux = new PilaImp<T>();
	while (!auxP->EsVacia()) {
		aux->Push(auxP->Pop());
	}
	while (!aux->EsVacia()) {
		this->Push(aux->Pop());
	}
	return *this;
}

template<class T>
bool PilaImp<T>::operator==(const Pila<T> &p) const {
	bool equals = true;
	Pila<T>* auxP = p.Clon();
	Pila<T>* thisAux = this->Clon();
	while (!auxP->EsVacia() && !thisAux->EsVacia() && equals) {
		if (auxP->Pop() != thisAux->Pop()) {
			equals = false;
		}
	}
	return equals && auxP->EsVacia() && thisAux->EsVacia();
}

template<class T>
PilaImp<T>::~PilaImp() {
	delete list;
}

template<class T>
Pila<T>* PilaImp<T>::CrearVacia() const {
	return new PilaImp<T>();
}

template<class T>
void PilaImp<T>::Push(const T& e) {
	list = new NodoLista<T>(e, NULL, list);
	length++;
}

template<class T>
T& PilaImp<T>::Top() const {
	assert(!EsVacia());
	return list->dato;
}

template<class T>
T PilaImp<T>::Pop() {
	assert(!EsVacia());
	T ret = list->dato;
	list = list->sig;
	length--;
	return ret;
}

template<class T>
void PilaImp<T>::Vaciar() {
	while (!EsVacia()) {
		this->Pop();
	}
	length = 0;
}

template<class T>
unsigned int PilaImp<T>::CantidadElementos() const {
	return length;
}

template<class T>
bool PilaImp<T>::EsVacia() const {
	return length == 0;
}

template <class T>
bool PilaImp<T>::EsLlena() const {
	return false;
}

template<class T>
Pila<T>* PilaImp<T>::Clon() const {
	NodoLista<T>* aux = list;
	Pila<T>* invertida = new PilaImp<T>();
	while (aux) {
		invertida->Push(aux->dato);
		aux = aux->sig;
	}
	Pila<T>* ret = new PilaImp<T>();
	while (!invertida->EsVacia()) {
		ret->Push(invertida->Pop());
	}
	delete invertida;
	return ret;
}

template<class T>
void PilaImp<T>::Imprimir(ostream & o) const
{
	Pila<T>* clon = this->Clon();
	while (!clon->EsVacia()) {
		T e = clon->Top();

		o << e << " ";

		clon->Pop();
	}
	delete clon;
}

#endif