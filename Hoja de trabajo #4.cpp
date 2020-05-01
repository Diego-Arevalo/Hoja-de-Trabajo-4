/*Hoja de Trabajo # 4 
Se le pide que realice un programa en C++ que solicite el ingreso
de la informaci�n de cada servicio realizado a un grupo de agricultores*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

//se hace una prueba de COMMIT
using namespace std;
struct reg{
	string nombre;
	int tipo;
	float size;
	float costo;};

int operacion;
void calcular();
void reporte();

int main(){
	do{
	cout<<"bienvenido, que accion desea realizar_?"<<endl;
	cout<<"1. Generar calculo y grabar"<<endl<<"2. informes"<<endl<<"3.salir"<<endl;
	cin>>operacion;
 	if (operacion==1){
 		system("CLS");
 		calcular();	};
 	if (operacion==2){
 		system("CLS");
 		reporte();	};
 } 	while (operacion!=3);
 	return (0);				}

/*or cada servicio debe ingresar los datos siguientes:  
 Tipo de Fumigaci�n (1 a 4) y 
 el n�mero de hect�reas, 
 toda esta informaci�n deber� almacenarse en una base de datos */
void calcular(){
	string nombre_x;
	int  tipo_x;
	float size_x;
	float costo_x;
	float exed_x;
	
	cout <<"ingrese nombre"<<endl;
	cin>>nombre_x;
	cout <<"ingrese tipo' 1, 2, 3, 4"<<endl;
	cin>>tipo_x;
	cout <<"tamano en hectareas"<<endl;
	cin>>size_x;
	
	if (tipo_x==1){
		costo_x=size_x*10;
		if(size_x>=500){
			costo_x=costo_x-((costo_x*5)/100);
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
		if (size_x<500 and costo_x>=1500){
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
	cout<<"Total: Q. "<<costo_x;	}

	if (tipo_x==2){
		costo_x=size_x*20;
		if(size_x>=500){
			costo_x=costo_x-((costo_x*5)/100);
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
		if (size_x<500 and costo_x>=1500){
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
	cout<<"Total: Q. "<<costo_x;	}
	
	if (tipo_x==3){
		costo_x=size_x*30;
		if(size_x>=500){
			costo_x=costo_x-((costo_x*5)/100);
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
		if (size_x<500 and costo_x>=1500){
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
	cout<<"Total: Q. "<<costo_x;	}
	
	if (tipo_x==4){
		costo_x=size_x*50;
		if(size_x>=500){
			costo_x=costo_x-((costo_x*5)/100);
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
		if (size_x<500 and costo_x>=1500){
			exed_x=costo_x-1500;
			costo_x=costo_x-((exed_x*10)/100);		}
	cout<<"Total: Q. "<<costo_x;	}
	
	
//GRABARRRRRR
ofstream grabararchivo;
	try {
		grabararchivo.open("Hoja de trabajo #4.txt",ios::app);
		grabararchivo<<tipo_x<<"\t"<<size_x<<"\t"<<costo_x<<"\t"<<endl;
		grabararchivo.close();		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	}	}


void reporte(){
/*mostrar la cantidad de servicios de cada tipo de fumigaci�n, 
determinar el tipo servicio con mayor demanda y el monto total pagado por los clientes*/
	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("Hoja de trabajo #4.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" 1 No se pudo abrir el archivo";
		exit(1);	}
	
	string	base="Hoja de trabajo #4.txt";
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
   /*----------------------------------------------------------------
   ----------------------------------------------------------------------*/ 
    reg recordset[lineas];
	archivo.open(base.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);	}	
	
	for (int i = 0; i < lineas; i++) {
        if (!archivo) {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break; }
	archivo>>recordset[i].tipo>>recordset[i].size>>recordset[i].costo;	}
    archivo.close();
    
    cout<<"Tipo"<<"\t"<<"Tamano"<<"\t"<<"Costo"<<endl;
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].tipo<<"\t"<<recordset[i].size<<"\t"<<recordset[i].costo<<endl;	}
	system("Pause");}
