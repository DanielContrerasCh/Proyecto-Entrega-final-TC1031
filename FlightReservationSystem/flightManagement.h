#ifndef flightManagement_h
#define flightManagement_h
#include <vector>
#include "flights.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "list.h"

using namespace std;


class FlightManagement{
private:
  void swap(vector<Flights> &, int i, int j);

public:
  vector<Flights> sort(vector<Flights> &);
  vector<Flights> loadFile(const string &name);
  void createTicket(List<Flights>&, int);
  void showCities(vector<Flights>&);
  List<Flights> destinationList(vector<Flights>&, string departure);
  void showFlights(List<Flights>&);
};

// Función para intercambiar dos elementos en un vector
// Complejidad O(1)
// @param v Vector de vuelos
// @param i Índice del primer elemento a intercambiar
// @param j Índice del segundo elemento a intercambiar
void FlightManagement::swap(vector<Flights> &v, int i, int j){
  Flights aux = v[i];
  v[i] = v[j];
  v[j] = aux;
} 

// Función para ordenar un vector de vuelos por el precio utilizando el algoritmo de Shell Sort
// Complejidad O(n(log(n))^2)
// @param v Vector de vuelos a ordenar
// @return Vector de vuelos ordenado por precio
vector<Flights> FlightManagement::sort(vector<Flights> &v){
  int h = v.size() / 2;

    while (h > 0) {
      for (int i = h; i < v.size(); i++) {
        for (int j = i; j >= h && v[j].getPrice() < v[j - h].getPrice(); j -= h) {
          swap(v, j, j - h);
        }
      }
      h /= 2;
    }

  return v;
}

// Función para cargar información de vuelos desde un archivo CSV a un vector
// Complejidad O(n)
// @param name Nombre del archivo CSV
// @return Vector de vuelos cargado desde el archivo
vector<Flights> FlightManagement::loadFile(const string &name){
  ifstream File(name);
  string origin;
  string dest;
  string skipline;
  int miles;
  float price;
  vector<Flights> flights;

  if(File.is_open())
{

    getline(File, skipline);

    while (File.good())
    {

      string temp;
      getline(File, origin, ',');

      getline(File, dest, ',');

      getline(File, temp, ',');
      miles = stoi(temp);

      getline(File, temp, '\n');
      price = stof(temp);

      Flights aux(origin, dest, miles, price);
      flights.push_back(aux);          
    }
}
else
{
    cout << "Error Message!" << endl;
}
File.close();
return flights;
}

// Función para crear un archivo de ticket a partir de una lista de vuelos
// Complejidad O(1)
// @param list Lista de vuelos
// @param ctr Contador de vuelos seleccionados
void FlightManagement::createTicket(List<Flights>&list, int ctr){
  ofstream File("Ticket.txt");
  File << list.toString(ctr);
}

// Función para mostrar las ciudades de origen disponibles a partir de un vector de vuelos
// Complejidad O(nlog(n))
// @param v Vector de vuelos
void FlightManagement::showCities(vector<Flights>&v){
  vector<string> aux;
  stringstream str;
  
  for(int i = 0; i < v.size(); i++){
    aux.push_back(v[i].getOrigin());
  }
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());

  for(int i = 0; i < aux.size(); i++){
    cout << "- " << aux[i] << endl;
  }
}

// Función para generar una lista de destinos a partir de un vector de vuelos y una ciudad de salida
// Complejidad O(n)
// @param v Vector de vuelos
// @param departure Ciudad de salida
// @return Lista de vuelos con la ciudad de salida especificada
List<Flights> FlightManagement::destinationList(vector<Flights>&v, string departure){
  List<Flights> destList;
  
  for(int i = 0; i < v.size(); i++){
    if(v[i].getOrigin() == departure){
      destList.add(v[i]);
    }
  }

return destList;
}

// Función para mostrar detalles de vuelos desde una lista y navegar por ellos
// Complejidad O(n)
// @param list Lista de vuelos
void FlightManagement::showFlights(List<Flights> &list){
  int index = 0;
  int option;
  bool run = true;
  
  cout << "These are the flights departing from your chosen location" << endl;
  while(run){
    if(index >= list.getSize()){
      cout << "There are no more flights available" << endl;
      index--;
    } else if(index == 0){
      cout << endl;
      cout << "Flight:" << endl;
      cout << list.toString(index);
      cout << "Type 1 to continue to view the next flight" << endl;
      cout << "Type 2 to book this flight" << endl;
      cin >> option; cout << endl;
      if(option == 2){
        createTicket(list, index);
        run = false;
      }
      index++;
    } else {
      cout << endl;
      cout << "Flight:" << endl;
      cout << list.toString(index);
      cout << "Type 1 to continue to view the next flight" << endl;
      cout << "Type 2 to book this flight" << endl;
      cout << "Type 3 to view the previous flight" << endl;
      cin >> option; cout << endl;
      if (option == 2){
        createTicket(list, index);
        run = false;
      } else if (option == 1){
        index++;
      } else if (option == 3){
        index--;
      }
    }
  }
}


#endif
