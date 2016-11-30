#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp() {
	cout << "1";
	first = NULL;
	last = NULL;
	length = 0;
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c) {
	cout << "2";
	Cola<T>* cClon = c.Clon();
	if (this != NULL) Vaciar();
	while (!cCLon->EsVacia()) {
		Encolar(cClon->Desencolar());
	}
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c) {
	cout << "3";
	Cola<T>* cClon = c.Clon();
	if (this != NULL) Vaciar();
	while (!cClon->EsVacia()) {
		Encolar(cClon->Desencolar());
	}
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c) {
	cout << "4";
	Cola<T>* auxC = c.Clon();
	Cola<T>* aux = new ColaImp<T>();
	while (!auxC->EsVacia()) {
		aux->Encolar(auxC->Desencolar());
	}
	while (!aux->EsVacia()) {
		this->Encolar(aux->Desencolar());
	}
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c) {
	cout << "5";
	Cola<T>* auxC = c.Clon();
	Cola<T>* aux = new ColaImp<T>();
	while (!cAux->EsVacia()) {
		aux->Encolar(auxC->Desencolar());
	}
	while (!aux->EsVacia()) {
		this->Encolar(aux->Desencolar());
	}
	return *this;
}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const {
	cout << "6";
	bool equals = true;
	Cola<T>* auxC = c.Clon();
	Cola<T>* thisAux = this->Clon();
	while (!auxC->EsVacia() && !thisAux->EsVacia() && equals) {
		if (auxC->Desencolar() != thisAux->Desencolar()) {
			equals = false;
		}
	}
	return equals && auxC->EsVacia() && thisAux->EsVacia();
}

template <class T>
ColaImp<T>::~ColaImp() {
	delete first;
	delete last;
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	cout << "7";
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e) {
	cout << "8";
	assert(!this->EsLlena());
	last = new NodoLista<T>(e, NULL, last);
	if (first == NULL) {
		first = last;
	}if (last->sig != NULL) {
		(last->sig)->ant = last;
	}
	length++;
}

template <class T>
T& ColaImp<T>::Principio()const {
	cout << "9";
	return first->dato;
}

template <class T>
T ColaImp<T>::Desencolar() {
	cout << "10";
	T ret = first->dato;
	first = first->sig;
	length--;
	return ret;
}

template <class T>
void ColaImp<T>::Vaciar() {
	cout << "11";
	while (!EsVacia()) {
		this->Desencolar();
	}
	length = 0;
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const {
	cout << "12";
	return length;
}

template <class T>
bool ColaImp<T>::EsVacia() const {
	cout << "13";
	return first == NULL;
}

template <class T>
bool ColaImp<T>::EsLlena() const {
	cout << "14";
	return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const {
	cout << "15";
	Cola<T>* ret = new ColaImp<T>();
	NodoLista<T>* aux = first;
	while (aux) {
		ret->Encolar(aux->dato);
		aux = aux->sig;
	}
	return ret;
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const {
	Cola<T> *clon = this->Clon();
	T elemento;
	while (!clon->EsVacia()) {
		elemento = clon->Desencolar();
		o << elemento << " ";
	}
	delete clon;
}

#endif