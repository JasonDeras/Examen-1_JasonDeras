#include<string>
#ifndef SOLDADOS_CPP
#define SOLDADOS_CPP

using namespace std;

class Soldados{
	
	private:
		
		string nombre;
		int p_vida;
		int p_fuerza;
		
	protected:
		
	public:
		
		Soldados(){
			 nombre="";
			 p_vida=0;
			 p_fuerza=0;
		}//Fin del constructor simple
		
		Soldados(string nombre,int p_vida,int p_fuerza){
			this->nombre=nombre;
			this->p_vida=p_vida;
			this->p_fuerza=p_fuerza;
		}//Constructor sobrecargado
		
		void setNombre(string nombre){
			this->nombre.assign(nombre);
		}//Set del nombre
		
		string getNombre(){
			return this->nombre;
		}//Get del nombre
		
		void setP_vida(int p_vida){
			this->p_vida=p_vida;
		}//Set de los puntos de vida;
		
		int getP_vida(){
			return this->p_vida;
		}//Get de los putos de vida
		
		void setP_fuerza(int p_fuerza){
			this->p_fuerza=p_fuerza;
		}//Set de los puntos de fuerza
		
		int getP_Fuerza(){
			return this->p_fuerza;
		}//Get de los puntos de fuerza
		
		//Metodo abstracto de los ataques
		virtual void ataque(Soldados*s1,Soldados*s2)=0;
		
		~Soldados(){
			
		}//Destructor
};

#endif
