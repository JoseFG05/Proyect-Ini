#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vehiculo{
  string modelo, marca, placa, color, motor, ced_cliente, fecha_entrega;
  int year, kilometraje;
  bool rentado;
  float precio_renta;
};

struct Cliente {
    string cedula, nombre, apellido, email, direccion;
    int cantidad_vehiculos_rentados;
    bool activo;
};

struct Repuesto {
    string modelo, marca, nombre, modelo_carro;
    int anio_carro, existencias;
    float precio;
};


//funcion para leer clientes
void leerClientes() {
    ifstream archivo("bin/datos/clientes.csv");
    string cliente;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de clientes.\n";
        return;
    }
    
    cout << "Datos de Clientes:";
    cout<< endl;
    while (getline(archivo, cliente)) {
        cout << cliente << endl;
    }
    archivo.close();
}

//funcion para agregar clientes
void agregarCliente() {
    Cliente cl;
    cout << "Ingrese los datos del cliente:\n";
    cout << "Cedula: "; 
    cin >> cl.cedula;
    cout << "Nombre: "; 
    cin >> cl.nombre;
    cout << "Apellido: "; 
    cin >> cl.apellido;
    cout << "Email: "; 
    cin >> cl.email;
    cout << "Cantidad de vehiculos rentados: "; 
    cin >> cl.cantidad_vehiculos_rentados;
    cout << "Direccion: "; 
    cin.ignore(); 
    getline(cin, cl.direccion);
    cout << "Activo (1 para si, 0 para no): "; 
    cin >> cl.activo;

    ofstream archivo("bin/datos/clientes.csv", ios::app);
    archivo << cl.cedula << "\t" << cl.nombre << "\t" << cl.apellido << "\t" << cl.email << "\t" << cl.cantidad_vehiculos_rentados 
    << "\t" << cl.direccion << "\t" << cl.activo << endl;
    archivo.close();
    cout << "Cliente agregado.";
    cout << endl;
}

// funcion para leer vehiculos

void leerVehiculos(){
    ifstream archivo("bin/datos/vehiculos.csv");
    string Vehiculo;
    cout << "Datos de Vehiculos:\n";
    while (getline(archivo,Vehiculo)){
        cout << "vehiculo" << endl;
    }
    archivo.close();
}

// Funcion para agregar Vehiculos

void agregarVehiculo(){
    Vehiculo vehi;
    cout << "Ingrese los datos del vehiculo:\n";
    cout << "Modelo:";
    cin >> vehi.modelo;
    cout << "Marca:";
    cin >> vehi.marca;
    cout << "Placa:";
    cin >> vehi.placa;
    cout << "Color:";
    cin >> vehi.color;
    cout << "Year:";
    cin >> vehi.year;
    cout << "Kilometraje:";
    cin >> vehi.kilometraje;
    cout << "Rentado (1 para si,0 para no):";
    cin >> vehi.rentado;
    cout << "Motor:";
    cin >> vehi.motor;
    cout << "Precio de renta:";
    cin >> vehi.precio_renta;
    cout << "Cedula del cliente:";
    cin >> vehi.ced_cliente;
    cout << "Fecha de entrega:";
    cin >> vehi.fecha_entrega;
    
    ofstream archivo("bin/datos/vehiculos.csv", ios:: app);
    archivo << vehi.modelo << "/t" << vehi.marca << "/t" << vehi.placa << "/t"<< vehi.color << "/t" << vehi.year << "/t" << vehi.kilometraje << "/t" << vehi.rentado << "/t" << vehi.motor << "/t" << vehi.precio_renta << "/t" << vehi.ced_cliente << "/t" << vehi.fecha_entrega << endl;
    archivo.close();
    cout << "Vehiculo agregado.\n";

}


int main(){

    int opcion;
    do{
        cout <<"1. Agregar Cliente:\n";
        cout <<"2. Agregar Vehiculo:\n";
        cout <<"3. Agregar Repuesto:\n";
        cout <<"4. Actualizar Dato:\n";
        cout <<"5. Borrar Dato:\n";
        cout << "0. Salir:\n";
        cin >> opcion;

        switch(opcion){
            case 1:
            agregarCliente();
            break;

            case 2:
            agregarVehiculo();
            break;

            case 3:
            AgregarRepuesto();
            break;

            case 4:
            ActualizarDato();
            break;

            case 5:
            BorrarDato();
            break;

            case 0:
            cout << "Saliendo del programa...\n";
            break;

            default:
            cout << "Opcion no valida, intente de nuevo. \n ";
        }
    }while(opcion !=0)



    return 0;
}