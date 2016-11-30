#include "Entrega2.h"


bool ParentesisBalanceados(char *formula)
{
	/*if (formula == NULL) return true;
	int largo = strlen(formula);
	bool entra = false;
	bool balanceado = false;
	for (int i = 0; i < largo; i++) {
		if (formula[i] == '(') {
			for (int j = largo; j > i; j--) {
				int k = j - 1;
				if (formula[k] == ')') {
					char* aux = new char;
					strncpy (aux, formula + (i + 1), (k - i - 1));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
				if (formula[k] == ']' || formula[k] == '}') {
					return balanceado = false;
				}
			}
		};
		if (formula[i] == '[') {
			for (int j = largo; j > i; j--) {
				int k = j - 1;
				if (formula[k] == ']') {
					char* aux = new char;
					strncpy(aux, formula + (i+1), (k - i - 1));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
				if (formula[k] == ')' || formula[k] == '}') {
					return balanceado = false;
				}
			}
		};
		if (formula[i] == '{') {
			for (int j = largo; j > i; j--) {
				int k = j - 1;
				if (formula[k] == '}') {
					char* aux = new char;
					strncpy(aux, formula + (i + 1), (k-i-1));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
				if (formula[k] == ']' || formula[k] == ')') {
					return balanceado = false;
				}
			}
		};
		return balanceado;
	};
	
	return false;*/
	if (formula == NULL) return true;
	int largo = strlen(formula);
	bool balanceado = false;
	for (int i = 0; i < largo; i++) {
		if (formula[i] == '(') {
			for (int j = i; j < largo; j++) {
				if (formula[j] == ')') {
					char* aux = new char;
					strncpy(aux, formula + (i + 1), (j - i - 2));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
			}
		}
		if (formula[i] == '[') {
			for (int j = i; j < largo; j++) {
				if (formula[j] == ']') {
					char* aux = new char;
					strncpy(aux, formula + (i + 1), (j - i - 1));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
			}
		}
		if (formula[i] == '{') {
			for (int j = i; j < largo; j++) {
				if (formula[j] == '}') {
					char* aux = new char;
					strncpy(aux, formula + (i + 1), (j - i - 1));
					balanceado = ParentesisBalanceados(aux);
					return balanceado;
				}
			}
		}
	}
	return balanceado;
}
