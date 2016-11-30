#include "FuncAuxTAD.h"

//#ifndef FUNCAUXTAD_CPP
//#define FUNCAUXTAD_CPP

ListaOrd<int>* FrameworkA1::ConvertirAListaOrd(NodoListaS *l) {
	ListaOrd<int> *ret = new ListaOrdImp<int>();
	while (l != NULL) {
		ret->AgregarOrd(l->dato);
        l = l->sig;
    }
	return ret;
}

ListaPos<int>* FrameworkA1::ConvertirAListaPos(NodoListaS *l) {
	ListaPos<int> *ret = new ListaPosImp<int>();
	while (l != NULL) {
		ret->AgregarFin(l->dato);
        l = l->sig;
    }
	return ret;
}

Pila<int>* FrameworkA1::ConvertirAPila(NodoListaS *l) {
	Pila<int> *ret = new PilaImp<int>();
	while (l != NULL) {
		ret->Push(l->dato);
        l = l->sig;
    }
	return ret;
}
	
Cola<int>* FrameworkA1::ConvertirACola(NodoListaS *l) {
	Cola<int> *ret = new ColaImp<int>();
	while (l != NULL) {
		ret->Encolar(l->dato);
        l = l->sig;
    }
	return ret;
}

MultiSet<int>* FrameworkA1::ConvertirAMultiSet(NodoListaS *l) {
	MultiSet<int> *ret = new MultiSetImp<int>();
	while (l != NULL) {
	   ret->Insertar(l->dato, 1);
           l = l->sig;
        }
	return ret;
}

//NodoListaS* FrameworkA1::ConvertirANodoLista(const ListaOrd<int> *ptr) {
//	NodoListaS *ret = NULL;
//	ListaOrd<int> *ptr;
//	while (l != NULL) {
//		ret->Encolar(l->dato);
//        l = l->sig;
//    }
//	return ret;
//}
//
//NodoListaS* FrameworkA1::ConvertirANodoLista(ListaPos<int> *ptr)
//NodoListaS* FrameworkA1::ConvertirANodoLista(Pila<int> *ptr)
//NodoListaS* FrameworkA1::ConvertirANodoLista(Cola<int> *ptr)
