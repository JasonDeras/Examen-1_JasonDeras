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
		
		S_Soporte(int blindaje,int camuflaje,string nombre,int p_vida,int p_fuerza,string tipo):Soldados(nombre,p_vida,p_fuerza,"Soporte"){
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
		
		int ataque(string tipo1,string tipo2){
		 	return 0;
		}//Metodo de ataque y defensa
		
		void print(){
			Soldados::print();
			cout<<"Blindaje: "<<blindaje<<endl;
			cout<<"Camuflaje: "<<camuflaje<<endl;
		}//Metodo print
		
		~S_Soporte(){
			
		}//Destructor
};

#endif
