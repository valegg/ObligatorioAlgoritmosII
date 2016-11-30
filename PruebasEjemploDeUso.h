#ifndef PRUEBASEJEMPLODEUSO_H
#define PRUEBASEJEMPLODEUSO_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega1.h"
#include "PruebasAuxEntrega2.h"
#include "PruebasAuxDefensa.h"
#include "Cadena.h"
#include "MultiSetImp.h"
#include "ListaOrdImp.h"
#include "ListaOrdImp2.h"
#include "ListaPosImp.h"
#include "TablaImp.h"

class PruebasEjemploDeUso : public Prueba  
{

public:
	PruebasEjemploDeUso(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUso();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;
	void Entrega1();
	void Entrega2();
	void Defensa();

	void PruebasEjerciciosTAD();
	void pruebaListaPos();
	void pruebaPila();
	void pruebaCola();

	void PruebasEjerciciosTAD2();
	void pruebaListaOrd();
	void pruebaListaOrd2();
	void pruebaTabla();
	void pruebaMultiSet();
};

#endif