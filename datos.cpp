#include<iostream>
#include<string>
#include <ctype.h> 
#include "datos.hpp"
using namespace std;


string Datos::mayusculas(string cadena){
    for(int i=0; i< cadena.size(); i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}

int Datos::tamano(){
    return count;
}

void Datos::insertar(string ident, string nom1, string nom2, string ape1, string ape2, string nac, string sexo, string rh, double dist){
    int id=0;
    Info * informacion = new Info;
    if (paciente == nullptr){
        informacion->id=id++;
        informacion->identifiacion=ident;
        informacion->nombre1=nom1;
        informacion->nombre2=nom2;
        informacion->apellido1=ape1;
        informacion->apellido2=ape2;
        informacion->nacimiento=nac;
        informacion->sexo=sexo;
        informacion->rh=rh;
        informacion->distancia=dist;
        informacion->back=paciente;
        informacion->next=nullptr;
        paciente = informacion;
        count ++;

    }else{
        informacion->id=id++;
        informacion->identifiacion=ident;
        informacion->nombre1=nom1;
        informacion->nombre2=nom2;
        informacion->apellido1=ape1;
        informacion->apellido2=ape2;
        informacion->nacimiento=nac;
        informacion->sexo=sexo;
        informacion->rh=rh;
        informacion->distancia=dist;
        informacion->next = paciente;
        paciente = informacion;
        informacion->back = paciente;
        count ++;
    }
}

void Datos::ver_pacientes(){
    cout << "identificacion" << "   " <<  "primer nombre" << "   " << "segundo nombre" << "   " << "primer apellido" << "   " << "segundo apellido" << "   " << "fecha nacimiento" << "   " << "sexo"<< "   " <<  "rh" << "   " <<  "distancia" << endl;
    Info *x = paciente;
    for(int i=0; i < count; i++){
        cout << x->identifiacion << "\t   " << mayusculas(x->nombre1) << "\t  " << mayusculas(x->nombre2) << "\t\t" << mayusculas(x->apellido1) << "  \t" << mayusculas(x->apellido2) << "\t\t" << mayusculas(x->nacimiento) << "\t    " << mayusculas(x->sexo) << "\t  " << mayusculas(x->rh) << "\t" << x->distancia << endl; 
        x = x->next;
    } 
}