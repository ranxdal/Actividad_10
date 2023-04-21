#include <iostream>
using namespace std;
const char *nombre_archivo = "archivon.dat";
struct Estudiante{
	int idcod;
	char nombres[50];
	char apellidos[50];
	int nt1, nt2, nt3, nt4, promedio;
};

void Crear();
void Leer();
void Actualizar();
void Borrar();

main(){
	Leer();
	Crear();
	Borrar();
	Actualizar();
	
	system("pause");
}

void Leer(){
	system("cls");
	FILE* archivon = fopen(nombre_archivo, "rb");
	if(!archivon){
		FILE* archivon = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivon);
	cout<<"_______________________________________"<<endl;
	cout<<"No. :"<<endl;
	cout<<"ID :"<<endl;
	cout<<"Nombres :"<<endl;
	cout<<"Apellidos :"<<endl;
	cout<<"Nota #1: "<<endl;
	cout<<"Nota #2: "<<endl;
	cout<<"Nota #3: "<<endl;
	cout<<"Nota #4: "<<endl;
	cout<<"Promedio: "<<endl;
	cout<<"Estado: "<<endl;
	
	do{
		cout<<id<<endl;
		cout<<estudiante.idcod<<endl;
		cout<<estudiante.nombres<<endl;
		cout<<estudiante.apellidos<<endl;
		cout<<estudiante.nt1<<endl;
		cout<<estudiante.nt2<<endl;
		cout<<estudiante.nt3<<endl;
		cout<<estudiante.nt4<<endl;
		cout<<estudiante.promedio<<endl;
		if(estudiante.promedio <= 60){
			cout<<"Reprobado"<<endl;
		}else{
			cout<<"Aprobado"<<endl;
			fread(&estudiante,sizeof(Estudiante),1,archivon);
			id+1;
		}
	}while(feof(archivon)==0);
	fclose(archivon);
	
}



void Crear(){
	FILE* archivon = fopen(nombre_archivo, "a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese ID: ";
		cin>>estudiante.idcod;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Nota #1: ";
		cin>>estudiante.nt1;
		
		cout<<"Ingrese Nota #2: ";
		cin>>estudiante.nt2;
		
		cout<<"Ingrese Nota #3: ";
		cin>>estudiante.nt3;
		
		cout<<"Ingrese Nota #4: ";
		cin>>estudiante.nt4;
		
		estudiante.promedio = (estudiante.nt1+estudiante.nt2+estudiante.nt3+estudiante.nt4)/4;
		if(estudiante.promedio <= 60){
			cout<<"Reprobado"<<endl;
		}else{
			cout<<"Aprobado"<<endl;
		}
		fwrite(&estudiante,sizeof(Estudiante),1,archivon);
		
		cout<<"Desea ingresar otro estudiante(s/n): ";
		cin>>res;
	}while(res=='s' || res== 'S');

	
	
	fclose(archivon);
		
}

void Actualizar(){
	
	FILE* archivon = fopen(nombre_archivo,"r+b");
	Estudiante estudiante;
    int id=0;
    cout<<"Ingrese el No. que desea modificar: ";
    cin>>id;
    fseek(archivon,id * sizeof(Estudiante),SEEK_SET);
		cout<<"Ingrese ID: ";
		cin>>estudiante.idcod;
		cin.ignore();
		
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres,50);
		cout<<"Ingrese Apellidos: ";
		cin.getline(estudiante.apellidos,50);
		cout<<"Nota #1: ";
        cin>>estudiante.nt1;
        cout<<"Nota #2: ";
        cin>>estudiante.nt2;
        cout<<"Nota #3: ";
        cin>>estudiante.nt3;
        cout<<"Nota #4: ";
        cin>>estudiante.nt4;
		estudiante.promedio= (estudiante.nt1+estudiante.nt2+estudiante.nt3+estudiante.nt4)/4;
		if (estudiante.promedio <= 60){
			cout <<"Reprobo"<<endl;
		}else{
			cout <<"Aprobo"<<endl;
		}
		
		
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivon);

	
	
	
	fclose(archivon);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivon = fopen(nombre_archivo,"rb");
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	Estudiante estudiante;
	int id=0,id_n=0;
	
	cout<<"Ingrese el No. a Eliminar: ";
	cin>>id;

	while(fread(&estudiante,sizeof(Estudiante),1,archivon)){
		if (id_n!=id){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivon);
	fclose(archivo_temp);
	
	archivon = fopen(nombre_archivo,"wb");
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivon);
	}
	fclose(archivon);
	fclose(archivo_temp);
	Leer();
		
}
