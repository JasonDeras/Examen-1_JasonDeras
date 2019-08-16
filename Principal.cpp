#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include<bits/stdc++.h>
#include "Soldados_Asalto.cpp"
#include "Soldados_Soporte.cpp"
using namespace std;

string token(string, string,int);
int ataque(Soldados*s1,Soldados*s2);
void listar();
vector<string>equipo1;
vector<string>equipo2;
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
					cout<<"Equipo 1"<<endl;
					for(int i=0;i<equipo1.size();i++)
					{
						cout<<equipo1.at(i);
					}
					
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
		
		int cont=0;
		fstream leer;
		
		string linea;
		
		leer.open("./Soldados.txt");
		
		while(!leer.eof()){
			
			getline(leer,linea);
			
			if(linea.size()>0){
				for(int i=0;i<linea.size();i++){
					cout<<token(linea,"/",i)+" "<<endl;	
				}
				
			}
		}
		
		leer.close();
		
	}//Fin del metodo listar
