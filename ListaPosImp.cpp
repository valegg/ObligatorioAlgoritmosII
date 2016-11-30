#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

template <class T>
ostream & operator<<<>(ostream &out, const ListaPosImp<T>& l)
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp();
}

template <class T>
ListaPosImp<T>::ListaPosImp()
{
	vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
	*this = l;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
	*this = l;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
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
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
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
ListaPosImp<T>::~ListaPosImp()
{
	delete[] vector;
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e)
{
	if (elementsCount == vectorCapacity)
	{
		this->Crecer();
	}
	T* aux = new T[vectorCapacity];
	aux[0] = e;
	for (int i = 0; i < elementsCount; i++)
	{
		aux[i + 1] = vector[i];
	}
	delete[] vector;
	vector = aux;
	elementsCount++;
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e)
{
	if (elementsCount == vectorCapacity) {
		this->Crecer();
	}
	vector[elementsCount] = e;
	elementsCount++;
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	if (elementsCount == vectorCapacity) {
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
	elementsCount++;
}

template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	assert(!EsVacia());
	T* aux = new T[vectorCapacity];
	for (int i = 0; i < elementsCount - 1; i++) {
		aux[i] = vector[i + 1];
	}
	delete[] vector;
	vector = aux;
	elementsCount--;
}

template <class T>
void ListaPosImp<T>::BorrarFin()
{
	assert(!EsVacia());
	elementsCount--;
}

template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	assert(!EsVacia());
	if (pos < elementsCount) {
		T* aux = new T[vectorCapacity];
		for (int i = 0; i < elementsCount; i++) {
			if (i < pos) {
				aux[i] = vector[i];
			}
			else {
				aux[i] = vector[i + 1];
			}
		}
		delete[] vector;
		vector = aux;
		elementsCount--;
	}
}

template <class T>
void ListaPosImp<T>::Borrar(const T &e)
{
	assert(Existe(e));
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
	elementsCount--;
}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	assert(!EsVacia());
	return vector[0];
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	return vector[elementsCount - 1];
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	return vector[pos];
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	int position = 0;
	while (vector[position] != e) {
		position++;
	}
	return position;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	bool exists = false;
	for (int i = 0; i < elementsCount; i++) {
		if (vector[i] == e) {
			exists = true;
		}
	}
	return exists;
}

template <class T>
void ListaPosImp<T>::Vaciar()
{
	delete[] vector;
	vector = new T[LENGTH_VECTOR];
	elementsCount = 0;
	vectorCapacity = LENGTH_VECTOR;
}

template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{
	return elementsCount;
}

template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	return elementsCount == 0;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	return elementsCount == vectorCapacity;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	ListaPos<T>* ret = new ListaPosImp<T>();
	for (Iterador<T> &i = this->GetIterador(); !i.EsFin();)
	{
		T e = i++;
		ret->AgregarFin(e);
	}
	return ret;
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}

template <class T>
void ListaPosImp<T> ::Crecer() {
	//NO IMPLENTADO
}

#endif