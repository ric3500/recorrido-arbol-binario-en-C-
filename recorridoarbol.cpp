#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo
{
	int dato;
	nodo * der;
	nodo * izq;
};

void menu();
nodo * crearnodo(int);
void insertarnodo(nodo *&, int);
void mostrararbol(nodo *, int);
void preorden(nodo *);
void inorden(nodo *);
void posorden(nodo *);

nodo * arbol = NULL;
int main(){
	menu();
	system("pause");
	return 0;
}

void menu(){
	int dato, opc, contador = 0;
	do {
		cout << "\t.:MENU:." << endl;
		cout << "1. insertar un nuevo nodo." << endl;
		cout << "2. Mostrar arbol binario " << endl;
		cout << "2. salir" << endl;
		cout << "elija una opcion "; 
		cin >> opc;
		switch (opc)
		{
		case 1: cout << "\n ingrese un numero entero: ";
			cin >> dato;
			insertarnodo(arbol, dato);
			cout << "\n";
			system("pause"); break;
		case 2: cout << "\n Mostrando el arbol binario : \n\n";
			mostrararbol(arbol, contador);
			cout << "\n";
			cout << "recorrido en PreOrden: ";
			preorden(arbol);
			cout << "\n\n";
			cout << "recorrido en InOrden: ";
			inorden(arbol);
			cout << "\n\n";
			cout << "recorrido en PosOrden: ";
			posorden(arbol);
			cout << "\n\n";
			system("pause");
		default: break; 	}
		system("cls");
	} while (opc != 3); }


nodo * crearnodo(int n){
	nodo * nuevo_nodo = new nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

void insertarnodo(nodo *&arbol, int n){
	if (arbol == NULL){
		nodo *nuevo_nodo = crearnodo(n);
		arbol = nuevo_nodo;
	}
	else {
		int valorraiz = arbol->dato;
		if (n < valorraiz){
			insertarnodo(arbol->izq, n);
		}
		else {
			insertarnodo(arbol->der, n);
		}}} 
 
void mostrararbol(nodo *arbol, int cont){
	if (arbol == NULL){return;}
	else
	{
		mostrararbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++){
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrararbol(arbol->izq, cont + 1);
	}}

void preorden(nodo *arbol){
	if (arbol == NULL){
		return;
	}
	else
	{
		cout << arbol->dato << "-";
		preorden(arbol->izq);
		preorden(arbol->der);
	}}

void inorden(nodo *arbol){
	if (arbol == NULL){
		return;
	}
	else
	{
		inorden(arbol->izq);
		cout << arbol->dato << "-";
		inorden(arbol->der);
	}}

void posorden(nodo *arbol){
	if (arbol == NULL){return;	}
	else
	{
		posorden(arbol->izq);
		posorden(arbol->der);
		cout << arbol->dato << "-"; }}
