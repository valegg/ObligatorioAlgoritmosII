#ifndef ENTREGA1_H
#define ENTREGA1_H

#include "Definiciones.h"

#include "ListaOrd.h"
#include "ListaPos.h"
#include "Pila.h"
#include "Cola.h"

#include "ListaOrdImp.h"
#include "ListaPosImp.h"
#include "PilaImp.h"
#include "ColaImp.h"

// Ver Entrega1.txt para la documentación de estas funciones

template <class T>
ListaOrd<T> *UnionListaOrd(const ListaOrd<T> *l1, const ListaOrd<T> *l2)
{
	ListaOrd<T>* ret = new ListaOrdImp<T>();
	ListaOrd<T>* aux1 = l1->Clon();
	ListaOrd<T>* aux2 = l2->Clon();
	while (!aux1->EsVacia() || !aux2->EsVacia()) {
		if (aux1->EsVacia()) {
			ret->AgregarOrd(aux2->Minimo());
			aux2->BorrarMinimo();
		}
		else if (aux2->EsVacia()) {
			ret->AgregarOrd(aux1->Minimo());
			aux1->BorrarMinimo();
		}
		else {
			if (aux1->Minimo() == aux2->Minimo()) {
				ret->AgregarOrd(aux1->Minimo());
				ret->AgregarOrd(aux2->Minimo());
				aux1->BorrarMinimo();
				aux2->BorrarMinimo();
			}
			else if (aux1->Minimo() < aux2->Minimo()) {
				ret->AgregarOrd(aux1->Minimo());
				aux1->BorrarMinimo();
			}
			else {
				ret->AgregarOrd(aux2->Minimo());
				aux2->BorrarMinimo();
			}
		}
	}
	return ret;
}

ListaOrd<int>* Enlistar(NodoArbol* a);

template <class T>
ListaOrd<T>* listar(Pila<T>* p) {
	ListaOrd<T>* ret = new ListaOrdImp<T>();
	while (!p->EsVacia()) {
		ret->AgregarOrd(p->Pop());
	}
	return ret;
}


template <class T>
bool EstaContenida(const Pila<T> *p1, const Pila<T> *p2)
{
	Pila<T>* aux1 = p1->Clon();
	Pila<T>* aux2 = p2->Clon();
	ListaOrd<T>* l1 = listar(aux1);
	ListaOrd<T>* l2 = listar(aux2);
	bool contenida = false;
	bool existe = true;
	while (!l1->EsVacia() && existe) {
		if (l2->EsVacia()) {
			contenida = false;
			existe = false;
		}
		else {
			if (l1->Minimo() == l2->Minimo()) {
				l1->BorrarMinimo();
				l2->BorrarMinimo();
				contenida = true;
			}
			else if (l1->Minimo() < l2->Minimo()) {
				contenida = false;
				existe = false;
			}
			else {
				l2->BorrarMinimo();
			}
		}
	}
	return contenida;
}

int CantidadDeHojas(NodoArbol* a);

void ImprimirPorNiveles(NodoArbol *a);

#endif