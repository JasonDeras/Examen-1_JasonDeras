#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include<typeinfo>
#include<bits/stdc++.h>

#include <stdlib.h>
#include <time.h>

#include "Soldados_Asalto.cpp"
#include "Soldados_Soporte.cpp"
#include "Soldados.cpp"

using namespace std;

string token(string, string,int);
int ataque(Soldados*s1,Soldados*s2);
void listar();
vector<Soldados*>equipo1;
vector<Soldados*>equipo2;

	int main(){
		
		int r=1;
		int op;
		int ran1,ran2;
		
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
					
					while(equipo1.size()>0&&equipo2.size()>0){
						
						ran1=1+rand()% (equipo1.size());
						ran2=1+rand()% (equipo2.size());
						
						equipo1.at(ran1)->getTipo();
						equipo2.at(ran2)->getTipo();
						
						
						
					}//Fin del while que hace la simulacion
						
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
	
	void listar(){
		
	stringstream convert;
	ifstream leer("./Soldados.txt");
	Soldados *s;
	
	//Variable de control
	string nombre="";
	int p_vida=0;
	int p_fuerza=0;
	string tipo=0;
	
	//Puntos de vida
	string vidas="";
	
	//Puntos de ataque;
	string ataque=""; 
	
	//Velocidad o blinedaje
	string v_o="";
	
	//Fuerza o camuflaje
	string f_c="";
	
	
	//Soldados de asalto
	int velocidad;
	int f_extra;
		
	//con dos delimitadores
	while (leer.get() != '&'){
		
    	leer.unget();
    	getline(leer, tipo, '/');
    	getline(leer, nombre, '/');
    	getline(leer, vidas, '/'); 
    	
    	//Conversion de vidas a entero
    	convert<<vidas;
    	convert>>p_vida;
    	convert.str("");
    	convert.clear();
    	
    	
    	getline(leer, ataque, '/');
    	//Conversion de puntos de ataque a entero
		convert<<ataque;
    	convert>>p_fuerza;
    	convert.str("");
    	convert.clear();
  	
    	getline(leer, v_o, '/');
    	getline(leer, f_c, '/');
    	
    	if(tipo=="Asalto"){
    		
    		//Velocidad y fuerza extra
    		int velocidad=0;
			int f_extra=0;
			
			//Velocidad
			convert<<v_o;
    		convert>>velocidad;
    		convert.str("");
    		convert.clear();
    	
    		//Fuerza convert<<ataque;
    		convert>>f_c;
    		convert>>f_extra;
    		convert.str("");
    		convert.clear();
    		
    		//Crea un nuevo soldado de asalto
    		s=new S_Asalto(velocidad,f_extra,nombre,p_vida,p_fuerza,tipo);
    		
		}else if(tipo=="Soporte"){
				
				//Blindaje y camuflaje
				int blindaje=0;
				int camuflaje=0;
				
				//Blindaje
				convert<<v_o;
    			convert>>blindaje;
    			convert.str("");
    			convert.clear();
    	
    			//Fuerza convert
    			convert<<f_c;
    			convert>>camuflaje;
    			convert.str("");
    			convert.clear();
				
				//Crea un nuevo soldado de soporte
				s=new S_Soporte(blindaje,camuflaje,nombre,p_vida,p_fuerza,tipo);
				
		}//If que valida si es soldado de soporte o asalto
    
    	equipo2.push_back(s);
	}
	
	//agarrar el segundo deliminator
	leer.get();
	while (!leer.eof()){
		
    	getline(leer, tipo, '/');
    	getline(leer, nombre, '/');
    	getline(leer, vidas, '/'); 
    	
    	//Conversion de vidas a entero
    	convert<<vidas;
    	convert>>p_vida;
    	convert.str("");
    	convert.clear();
    	
    	
    	getline(leer, ataque, '/');
    	//Conversion de puntos de ataque a entero
		convert<<ataque;
    	convert>>p_fuerza;
    	convert.str("");
    	convert.clear();
  	
    	getline(leer, v_o, '/');
    	getline(leer, f_c, '/');
    	
    	if(tipo=="Asalto"){
    		
    		//Velocidad y fuerza extra
    		int velocidad=0;
			int f_extra=0;
			
			//Velocidad
			convert<<v_o;
    		convert>>velocidad;
    		convert.str("");
    		convert.clear();
    	
    		//Fuerza convert<<ataque;
    		convert>>f_c;
    		convert>>f_extra;
    		convert.str("");
    		convert.clear();
    		
    		//Crea un nuevo soldado de asalto
    		s=new S_Asalto(velocidad,f_extra,nombre,p_vida,p_fuerza,tipo);
    		
		}else if(tipo=="Soporte"){
				
				//Blindaje y camuflaje
				int blindaje=0;
				int camuflaje=0;
				
				//Blindaje
				convert<<v_o;
    			convert>>blindaje;
    			convert.str("");
    			convert.clear();
    	
    			//Camuflaje
    			convert<<f_c;
    			convert>>camuflaje;
    			convert.str("");
    			convert.clear();
				
				//Crea un nuevo soldado de soporte
				s=new S_Soporte(blindaje,camuflaje,nombre,p_vida,p_fuerza,tipo);
				
			}//If que valida si es soldado de soporte o asalto
			equipo1.push_back(s);
		}
		
		leer.close();
		
	}//Fin del metodo listar
