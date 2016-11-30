#include "ListaOrdImp2.h"

#ifndef LISTAORDIMP2_CPP
#define LISTAORDIMP2_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaOrdImp2<T> &l) 
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaOrd<T>* ListaOrdImp2<T>::CrearVacia() const 
{
	return new ListaOrdImp2<T>();
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2()
{
	/*arbol = new NodoABB<T>();*/
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrd<T> &l) 
{
	/*vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
	*this = l;*/
	return *this;
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrdImp2<T> &l) 
{
	/*vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
	*this = l;*/
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrd<T> &l) 
{ 
	/*if (this != &l) {
		this->Vaciar();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto())
		{
			T e = i.Elemento();
			this->AgregarFin(e);
		}
	}
	return *this;*/
	return *this;

}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrdImp2<T> &l) 
{ 
	if (this != &l) {
		this->Vaciar();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto())
		{
			T e = i.Elemento();
			this->AgregarFin(e);
		}
	}
	return *this;
}

template <class T>
ListaOrdImp2<T>::~ListaOrdImp2()
{
	//delete[] vector;
}

template <class T>
void ListaOrdImp2<T>::AgregarOrd(const T &e) 
{
	//agregar posicion
	/*if (elementsCount == vectorCapacity) {
		this->Crecer();
	}
	T* aux = new T[vectorCapacity];
	for (int i = 0; i < elementsCount + 1; i++)
	{
		if (pos == i) {
			aux[i] = e;
		}
		else if (pos > i) {
			aux[i] = vector[i];
		}
		else {
			aux[i] = vector[i - 1];
		}
	}
	delete[] vector;
	vector = aux;
	elementsCount++;*/
}

template <class T>
void ListaOrdImp2<T>::BorrarMinimo() 
{
	// borrar principio
	/*assert(!EsVacia());
	T* aux = new T[vectorCapacity];
	for (int i = 0; i < elementsCount - 1; i++) {
		aux[i] = vector[i + 1];
	}
	delete[] vector;
	vector = aux;
	elementsCount--;*/
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	/*assert(Existe(e));
	bool exists = false;
	T* aux = new T[vectorCapacity];
	for (int i = 0; i < elementsCount; i++) {
		if (!exists && vector[i] != e) {
			aux[i] = vector[i];
		}
		else {
			exists = true;
			aux[i] = vector[i + 1];
		}
	}
	delete[] vector;
	vector = aux;
	elementsCount--;*/
}

template <class T>
const T& ListaOrdImp2<T>::Minimo() const 
{
	/*assert(!EsVacia());
	return vector[0];*/
	return 0;
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const 
{
	//return vector[elementsCount - 1];
	return 0;
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const 
{
	/*bool exists = false;
	for (int i = 0; i < elementsCount; i++) {
		if (vector[i] == e) {
			exists = true;
		}
	}
	return exists;*/
	return false;
}

template <class T>
void ListaOrdImp2<T>::Vaciar() 
{
	/*delete[] vector;
	vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;*/
}

template <class T>
unsigned int ListaOrdImp2<T>::CantidadElementos()const 
{ 
	//return elementsCount;
	return 0; 
}

template <class T>
bool ListaOrdImp2<T>::EsVacia()const 
{
	//return elementsCount == 0;
	return false;
}

template <class T>
bool ListaOrdImp2<T>::EsLlena()const 
{ 
	//return elementsCount == vectorCapacity;
	return false;
}

template<class T>
ListaOrd<T>* ListaOrdImp2<T>::Clon() const
{
	/*ListaPos<T>* ret = new ListaPosImp<T>();
	for (Iterador<T> &i = this->GetIterador(); !i.EsFin();)
	{
		T e = i++;
		ret->AgregarFin(e);
	}
	return ret;*/
	return new ListaOrdImp<T>();
}

//PARA TERMINAR
//ListaPosImp2<T>* ListaPosImp<T>::ordenarMenorMayor(const ListaPosImp<T> l) {
//	ListaOrdImp<T> ret = new ListaOrdImp2<T>();
//	for (int i = 0; i < l.CantidadElementos; i++) {
//	
//	}
//}

template <class T>
Iterador<T> ListaOrdImp2<T>::GetIterador() const 
{
	// NO IMPLEMENTADA

	ListaPosImp<T> l;
	// SUGERENCIA: aqui cargar en l con los elementos de this ordenados de menor a mayor (con funcion auxiliar)
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}


#endif