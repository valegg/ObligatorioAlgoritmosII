#include "Entrega1.h"

#ifndef ENTREGA1_CPP
#define ENTREGA1_CPP

void auxiliarListar(NodoArbol* a, ListaOrd<int>* list) {
	if (a != NULL) {
		auxiliarListar(a->der, list);
		list->AgregarOrd(a->dato);
		auxiliarListar(a->izq, list);
	}
}

ListaOrd<int>* Enlistar(NodoArbol* a)
{
	ListaOrd<int>* list = new ListaOrdImp<int>();
	auxiliarListar(a, list);
	return list;
}

bool esHoja(NodoArbol* a) {
	bool ret = false;
	if (a->izq == NULL && a->der == NULL) ret = true;
	return ret;
}

int CantidadDeHojas(NodoArbol* a)
{
	int ret = 0;
	NodoArbol* aux;
	Pila<NodoArbol*>* auxP = new PilaImp<NodoArbol*>;
	auxP->Push(a);
	while (!auxP->EsVacia()) {
		aux = auxP->Pop();
		if (esHoja(aux)) {
			ret++;
		}
		else {
			if (aux->der != NULL) {
				auxP->Push(aux->der);
			}
			if (aux->izq != NULL) {
				auxP->Push(aux->izq);
			}
		}
	}
	delete auxP;
	return ret;
}

void ImprimirPorNiveles(NodoArbol *a)
{
	/*ListaOrd<int>* imp;
	Cola<NodoArbol*>* auxC = new ColaImp<NodoArbol*>;
	if (a != NULL) auxC->Encolar(a);
	while (!auxC->EsVacia()) {
	NodoArbol* arb = auxC->Principio();
	imp->dato = arb->dato;
	if (arb->izq != NULL) {
	auxC->Encolar(arb->izq);
	}if (arb->der != NULL) {
	auxC->Encolar(arb->der);
	}
	auxC->Desencolar();
	}
	for (int i = 0; i < elementsCount; i++) {
	cout << ElementoPos(imp) << " ";
	BorrarFin(imp);
	}
	delete auxC;*/

	NodoArbol* aux;
	Pila<NodoArbol*>* auxP = new PilaImp<NodoArbol*>();
	auxP->Push(a);
	while (!auxP->EsVacia()) {
		aux = auxP->Pop();
		if (esHoja(aux)) {
			cout << aux->dato << " ";
		}
		else {
			auxP->Push(new NodoArbol(aux->dato));
			if (aux->izq != NULL) {
				auxP->Push(aux->izq);
			}
			if (aux->der != NULL) {
				auxP->Push(aux->der);
			}
		}
	}

	/*if(a == NULL) return;
	Pila<int>* imp = new PilaImp<int>();
	Cola<NodoArbol*>* auxC = new ColaImp<NodoArbol*>;
	if (a != NULL) auxC->Encolar(a);
	while (!auxC->EsVacia()) {
	NodoArbol* arb = auxC->Principio();
	imp->Push(arb->dato);
	if (arb->der != NULL) {
	auxC->Encolar(arb->der);
	}if (arb->izq != NULL) {
	auxC->Encolar(arb->izq);
	}
	auxC->Desencolar();
	}
	while (!imp->EsVacia()) {
	cout << imp->Pop() << " ";
	}*/
	delete auxP;
	delete aux;
}

#endif