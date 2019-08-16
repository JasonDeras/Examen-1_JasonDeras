#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include<bits/stdc++.h>
#include "Solados_Asalto.cpp"
#include "Solados_Soporte.cpp"
using namespace std;

string token(string, string,int);
int ataque(Soldaos*s1,Soldados*s2);
void listar();	
void eliminar();
void modificar();

	int main(){
		
		int r=1;
		int op;
		
		while(r==1){
			
			cout<<"Menu\n\n\n\n";
			cout<<"1. Imprimir las listas de los equipos\n\n";
			cout<<"2. Iniciar simulacion\n\n";
			cout<<"3. Salir\n\n";
			cout<<"Ingrese una opcion: ";
			cin>>op;
			cout<<"\n\n\n\n";
			
			switch(op){
				
				
				case 1:
					listar();
					cout<<"\n\n\n\n";
				break;
				
				case 2:
					
				break;
				
				case 3:
					exit(0);
				break;
				
				default:
					cout<<"Opcion no valida\n\n\n\n";
				break;	
			}//Case de las opciones
			cout<<"Volver al menu?1.-Si,2.-No: ";
			cin>>r;
			cout<<"\n\n\n\n";
		}//Fin del while del menu
		system("pause");
		return 0;
	}//Fin del main
	
	string token(string cadena, string divisor, int pos){
		
       if(cadena.size()>0){
       	
         char oracion[cadena.size()];
		  
         for (int i=0;i<=cadena.size();i++){
               oracion[i]=cadena[i];
         } 
		                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);   
		           
         while(ptrtoken){
         	
             if(num==pos){ 
                return ptrtoken;                    
             }
			                  
             ptrtoken = strtok(NULL, d);
             num++;
         }
         
         return "";
         
       }else{
             return "";
       }
       
	}//Fin de metodo token
	
	void listar(){
		
		fstream leer;
		
		string linea;
		
		leer.open("./prueba.txt");
		
		while(!leer.eof()){
			
			getline(leer,linea);
			
			if(linea.size()>0){
				
				cout<<token(linea,";",1)+" "
					 +token(linea,";",2)+" "
					 +token(linea,";",3)+" "<<endl;
			}
		}
		
		leer.close();
		
	}//Fin del metodo listar
	
	void eliminar(){
		
		fstream leer;
		
		ofstream escribir;
		
		vector<string>lista;
		
		string linea;
		
		int cent=0;
		
		leer.open("./prueba.txt");
		string codigo;
		
		cout<<"codigo a eliminar: ";
		cin>>codigo;
		
		while(!leer.eof()){
			
			getline(leer,linea);
			
			if(token(linea,";",1)==codigo){
				
				cent=1;
				
			}else {
				
				if(linea[0]!='\0'){
					lista.push_back(linea);
				}//No es el fin de archivo (eof)
				
			}//Busca el codigo a eliminar
			
		}//Fin del while que lee el archivo
		
		leer.close();
		
		//Sobre escrubir el archivo
		if(cent==1){
			escribir.open("./prueba.txt");
			for(int i=0;i<lista.size();i++){
				escribir<<lista[i]<<endl;
			}
			escribir.close();
		}
		
	}//Fin del metodo eliminar
	
	void modificar(){
		
		fstream leer;
		
		ofstream escribir;
		
		vector<string>lista;
		
		string linea;
		
		int cent=0;
		
		leer.open("./prueba.txt");
		string codigo;
		
		cout<<"codigo a modificar: ";
		cin>>codigo;
		
		while(!leer.eof()){
			
			getline(leer,linea);
			
			if(token(linea,";",1)==codigo){
				
				cent=1;
				string vn,ve;
				cout<<"Nombre nuevo: ";
				cin>>vn;
				cout<<"Edad nueva: ";
				cin>>ve;
				lista.push_back(codigo+";"+vn+";"+ve);
				
			}else {
				
				if(linea[0]!='\0'){
					lista.push_back(linea);
				}//No es el fin de archivo (eof)
				
			}//Busca el codigo a eliminar
			
		}//Fin del while que lee el archivo
		
		leer.close();
		
		//Sobre escrubir el archivo
		if(cent==1){
			
			escribir.open("./prueba.txt");
			for(int i=0;i<lista.size();i++){
				escribir<<lista[i]<<endl;
			}
			escribir.close();
		}
		
	}//Fin del metodo modificar
