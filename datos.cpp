#include<iostream>
#include<string>
#include <ctype.h>
#include "datos.hpp"
using namespace std;

//Función que permite poner en mayusculas la informacion para asi evitar problemas a la hora de buscala
string Datos::mayusculas(string cadena){
    for(int i=0; i< cadena.size(); i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}

//retorna el tamaño de la base de datos
int Datos::tamano(){
    return count;
}


//inserta la informacón corerspondiente de cada donante
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


//Realiza un display de la información para que pueda verla el usuario
void Datos::ver_pacientes(){
    cout << "identificacion" << "   " <<  "primer nombre" << "   " << "segundo nombre" << "   " << "primer apellido" << "   " << "segundo apellido" << "   " << "fecha nacimiento" << "   " << "sexo"<< "   " <<  "rh" << "   " <<  "distancia" << endl;
    Info *x = paciente;
    for(int i=0; i < count; i++){
        cout << x->identifiacion << "\t   " << mayusculas(x->nombre1) << "\t  " << mayusculas(x->nombre2) << "\t\t" << mayusculas(x->apellido1) << "\t\t" << mayusculas(x->apellido2) << "\t\t  " << mayusculas(x->nacimiento) << "\t   " << mayusculas(x->sexo) << "\t" << mayusculas(x->rh) << "\t" << x->distancia << endl;
        x = x->next;
    }
}

int Datos::partition(vector<Info*>& v,int left,int right){
  int x=v[right-1]->distancia;
  int i=left-1;
  for(int j=left;j<right-1;++j){
    if(v[j]->distancia<= x){
      i++;
      Info* c=v[j];
      v[j]=v[i];
      v[i]=c;
    }
  }
  Info* c=v[i+1];
  v[i+1]=v[right-1];
  v[right-1]=c;
  return i+1;
}

void Datos::quikci(vector<Info*>& v,int left,int right){
      if(left<right){
        int id=partition(v,left,right);
        quikci(v,left,id);
        quikci(v,id+1,right);
      }
}

void Datos::quicksort(vector<Info*>& v){
    quikci(v,0,v.size());
}

void Datos::busqueda(string R){
    vector<Info*> bod;
    Info *temp=paciente;
    for (int i=0;i<count;i++){
      if(temp->rh==R)
        bod.push_back(temp);
      temp=temp->next;
    }
    quicksort(bod);
    for(int i=0;i<bod.size();++i)
      cout<<bod[i]->nombre1<<" "<<bod[i]->apellido1<<"  "<<bod[i]->distancia<<'\n';
}


string Datos::search_info(int i){
  if(i<count){
    Info* temp=paciente;
    for(int j=0;j<i;++j){
        temp=temp->next;
    }
    string res=temp->identifiacion+"\t   "+mayusculas(temp->nombre1)+"\t  "+mayusculas(temp->nombre2)+"\t\t"+mayusculas(temp->apellido1)+"\t\t"+mayusculas(temp->apellido2)+"\t\t  "+mayusculas(temp->nacimiento)+"\t   "+mayusculas(temp->sexo)+"\t"+mayusculas(temp->rh)+"\t"+to_string(temp->distancia);
    return res;
  }
  string res="error";
    return res;
}
