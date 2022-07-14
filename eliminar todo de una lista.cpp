#include<iostream>
#include<stdio.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo* siguiente;
};
Nodo* lista=NULL;
void menu();
void cent(int n);
void enlistar(Nodo*& lista,int n);
void mostrarl(Nodo* lista);
void buscarl(Nodo*& lista, int n);
void eliminarnodo(Nodo*& lista,int n);
void eliminarlista(Nodo*& lista,int& n);
int main(){
	menu();
	return 0;
}
void menu(){
	int preg,num;
	do{
		cout<<"1.enlistar"<<endl;
		cout<<"2.mostrar"<<endl;
		cout<<"3.buscar"<<endl;
		cout<<"4.eliminar numero"<<endl;
		cout<<"5.eliminar todo"<<endl;
		cin>>num;
		cent(num);
		cout<<"menu close? 0/no";
		cin>>preg;
	}while(preg!=0);
}
void cent(int n){
	int dato,preg;
	if(n==1){
		do{
			cout<<"dame un numero"<<endl;
			cin>>dato;
			enlistar(lista,dato);
			cout<<"otro numero? 0/no"<<endl;
			cin>>preg;
		}while(preg!=0);
	}
	if(n==2){
		mostrarl(lista);
	}
	if(n==3){
		cout<<"dame el numero a buscar"<<endl;
		cin>>dato;
		buscarl(lista,dato);
	}
	if(n==4){
		cout<<"dame el numero a eliminar"<<endl;
		cin>>dato;
		eliminarnodo(lista,dato);
	}
	if(n==5){
		cout<<"eliminnado todos los elementos de la lista"<<endl;
		while(lista!=NULL){
			eliminarlista(lista,dato);
			cout<<dato<<"->";
		}
		cout<<"\n";
	}
}
void enlistar(Nodo*& lista,int n){
	Nodo* node=new Nodo();
	node->dato=n;
	Nodo* aux1=lista;
	Nodo* aux2=NULL;
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=node;
	}else{
		aux2->siguiente=node;
	}
	node->siguiente=aux1;
}
void mostrarl(Nodo* lista){
	Nodo* node=new Nodo();
	node=lista;
	while(node!=NULL){
		cout<<node->dato<<"->";
		node=node->siguiente;
	}
}
void buscarl(Nodo*& lista,int n){
	bool band=false;
	Nodo* node=new Nodo();
	node=lista;
	while((node!=NULL)&&(node->dato<=n)){
		if(node->dato==n){
			band=true;
		}
		node=node->siguiente;
	}
	if(band==true){
		cout<<"elemento encontrado"<<endl;
	}else{
		cout<<"elemento no encontrado"<<endl;
	}
}
void eliminarnodo(Nodo*& lista,int n){
	if(lista!=NULL){
		Nodo* borrar;
		Nodo* anterior;
		borrar=lista;
		while((borrar!=NULL)&&(borrar->dato!=n)){
			anterior=borrar;
			borrar=borrar->siguiente;
		}
		if(borrar==NULL){
			cout<<"no se encuentra el elemento"<<endl;
		}else if(anterior==NULL){
			lista=lista->siguiente;
			delete borrar;
		}else{
			anterior->siguiente=borrar->siguiente;
			delete borrar;
		}
	}
}
void eliminarlista(Nodo*& lista,int& n){
	Nodo* aux=lista;
	n=aux->dato;
	lista=aux->siguiente;
	delete aux;
}