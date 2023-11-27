#ifndef flights_h
#define flights_h

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Flights {
private:
  string origin;
  string dest;
  int miles;
  float price;

public:

  // Constructor que inicializa las variables privadas
  Flights(string _origin, string _dest, int _miles, float _price) {
    origin = _origin;
    dest = _dest;
    miles = _miles;
    price = _price;
  }

  // Método para obtener el origen de los vuelos
  //Complejidad O(1)
  // @param 
  // @return string 
  string getOrigin() { return origin; }

  // Método para obtener la destinación de los vuelos
  // Complejidad O(1)
  // @param 
  // @return string 
  string getDest() { return dest; }

  // Método para obtener la distancia de los vuelos
  // Complejidad O(1)
  // @param 
  // @return int 
  int getMiles() { return miles; }

  // Método para obtener el precio de los vuelos
  // Complejidad O(1)
  // @param 
  // @return float 
  float getPrice() { return price; }

  string showInfo(); 

};

// Método para mostrar la información de los vuelos
// Complejidad O(1)
// @param 
// @return Regresa en un stringstream la información de los vuelos
string Flights::showInfo(){
  
  stringstream aux;
    aux << "   Origin: " << getOrigin() << endl;
    aux << "   Destination: " << getDest() << endl;
    aux << "   Miles: " << getMiles() << endl;
    aux << "   Price: " << getPrice() << endl;
  
  return aux.str();
}

#endif // flights_h