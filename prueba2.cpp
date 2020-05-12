#include "datos.hpp"
//#include <iostream>
#include<vector>
#include<fstream>

vector<string> split(string cad,string lim){
  vector<string> vec;
  while (cad.length()>0){
    int pos=cad.find(lim);
    if(pos==-1){
      vec.push_back(cad);
      cad="";
    }
    else{
    vec.push_back(cad.substr(0,pos));
    cad=cad.substr(pos+1,cad.length()-(pos+1));
    }
  }
  return vec;
}

int main(){
    //Datos x;
    //string y;
    //cout << "ingrese los datos separados por coma: ";
    //std::cin  >> y;
    //vector<string> infor=split(y,",");

    //x.insertar(infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6], infor[7],stoi(infor[8]));
    x.insertar("1085345980", "nicole", "andrea", "caicedo", "garzon", "17/10/1999", "f", "A+", 20);
    x.insertar("108345980", "nicolas", "giovanny", "caicedo", "ramirez", "17/06/1999", "m", "B+", 68);
    x.insertar("108345980", "andres", "felipe", "gamez", "vargas", "13/10/1998", "m", "B-", 21);
    x.insertar("108345980", "camilo", "andres", "salazar", "martinez", "17/12/1960", "m", "AB-", 62);
    x.insertar("108345980", "sebastian", "rodirgo", "gamez", "jimEnez", "16/04/1964", "m", "B+", 11);
    x.insertar("108345980", "adrian", "german", "pimiento", "lopez", "21/11/1976", "m", "A+", 65);
    x.insertar("108345980", "martha", "cecilia", "vargas", "rodriguez", "16/11/1966", "f", "A+", 110);
    x.busqueda("A+");

    ofstream in("DataBase.txt",ios::app);
    if(in.good()){
      in<<"Identificacion" << "   " <<  "Primer_nombre" << "   " << "Segundo_nombre" << "   " << "Primer_apellido" << "   " << "Segundo_apellido" << "   " << "Fecha_nacimiento" << "   " << "Sexo"<< "   " <<  "RH" << "   " <<  "Distancia" <<'\n';
      in<<"================================================================================================================================="<<'\n';
      for(int i=0;i<x.tamano();++i){
        in<<x.search_info(i)<<'\n';
      }
    }
    in.close();
    //cout<<x.search_ info(0)<<'\n';

    return 0;
}
