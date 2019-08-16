#include<iostream>
#include<typeinfo>
#include "Soldados.cpp"
#ifndef SOLDADO_SOPORTE
#define SOLDADO_SOPORTE

using namespace std;

class S_Soporte:public Soldados{
	
	private:
		
		int blindaje;
		int camuflaje;
		
	protected:
		
	public:
		
		S_Soporte():Soldados(){
			blindaje=0;
			camuflaje=0;
		}//Fin del constructor simple
		
		S_Soporte(int blindaje,int camuflaje,string nombre,int p_vida,int p_fuerza):Soldados(nombre,p_vida,p_fuerza){
			this->blindaje=blindaje;
			this->camuflaje=camuflaje;
		}//Constructor sobrecargado
		
		void setBlindaje(int blindaje){
			this->blindaje=blindaje;
		}//Set del blindaje
		
	 	int getBlindaje(){
			return blindaje;
		}//Get del blindaje
		
		void setCamuflaje(int camuflaje){
			this->camuflaje=camuflaje;
		}//Set del camuflaje
		
	 	int getCamuflaje(){
			return camuflaje;
		}//Get del Camuflaje
		
		~S_Soporte(){
			
		}//Destructor
};

#endif
