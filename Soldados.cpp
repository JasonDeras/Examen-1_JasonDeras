#include<string>
#include<iostream>
#ifndef SOLDADOS_CPP
#define SOLDADOS_CPP

using namespace std;

class Soldados{
	
	private:
		
		string nombre;
		int p_vida;
		int p_fuerza;
		string tipo;
		
	protected:
		
	public:
		
		Soldados(){
			 nombre="";
			 p_vida=0;
			 p_fuerza=0;
			 tipo="";
		}//Fin del constructor simple
		
		Soldados(string nombre,int p_vida,int p_fuerza,string tipo){
			this->nombre=nombre;
			this->p_vida=p_vida;
			this->p_fuerza=p_fuerza;
			this->tipo=tipo;
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
		
		void setTipo(string tipo){
			this->tipo.assign(tipo);
		}//Set del tipo de soldado
		
		string getTipo(){
			return this->tipo;
		}//Get del tipo de soldado
		
		void print(){
			
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Puntos de vida: "<<p_vida<<endl;
			cout<<"punto de fuerza: "<<p_fuerza<<endl;
			cout<<"Tipo: "<<tipo<<endl;
		}//Metodo print
		
		~Soldados(){
			
		}//Destructor
};

#endif
