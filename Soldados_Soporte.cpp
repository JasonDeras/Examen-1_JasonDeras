#include<iostream>
#include<typeinfo>
#include "Soldados.cpp"
#ifndef SOLDADO_SOPORTE
#define SOLDADO_SOPORTE

using namespace std;

class S_Soporte:public Soldados{
	
	private:
		
		int velocidad;
		int f_extra;
		
	protected:
		
	public:
		
		S_Soporte():Soldados(){
			velocidad=0;
			f_extra=0;
		}//Fin del constructor simple
		
		S_Soporte(int velocidad,int f_extra,string nombre,int p_vida,int p_fuerza):Soldados(nombre,p_vida,p_fuerza){
			this->velocidad=velocidad;
			this->f_extra=f_extra;
		}//Constructor sobrecargado
		
		void setVelocidad(int velocidad){
			this->velocidad=velocidad;
		}//Set de la velocidad del soldado
		
	 	int getVelocidad(){
			return velocidad;
		}//Get de la velocidad del soldado
		
		void setF_extra(int f_extra){
			this->f_extra=f_extra;
		}//Set de la fuerza extra
		
	 	int getF_estra(){
			return f_extra;
		}//Get de la fuerza extra
		
		void ataque(Soldados*s1,Soldados*s2){
			
			if(typeid(*s1)==typeid(S_Asalto)
			  && typeid(*s2)==typeid(S_Asalto)){//Valida si es un soldado de asalto a otro soldado de asalto	
			  	puntos de fuerza * (10)
			  	
			}else if(typeid(*s1)==typeid(S_Asalto)
			  && typeid(*s2)==typeid(S_Asalto)){//Valida si es de un soldado de asalto a un soldado de soporte
		puntos de fuerza * (10 + (velocidad * 2))
			}//Fin de la validacion de los ataques
			
		}//Fin del metodo abstracto para el ataque y defesa
		
		~S_Soporte(){
			
		}//Destructor
};

#endif
