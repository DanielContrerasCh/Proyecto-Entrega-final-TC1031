#include "flights.h"
#include <vector>
#include <iostream>
#include "flightManagement.h"
#include "list.h"

using namespace std;

// Función para mostrar un menú de opciones y realizar acciones en función de la elección del usuario
// Complejidad O(n)
// @param flights Vector de vuelos cargados desde el archivo CSV
// @param data Objeto de la clase FlightManagement para realizar operaciones
// @param list Lista de vuelos para gestionar reservas
// @return 0 (código de salida)
int menu(vector<Flights> flights, FlightManagement data, List<Flights> list){
  

  vector<Flights> auxVector;
  int choice;

  string departure;
  string desination;
  flights = data.loadFile("dataset.csv");
  data.sort(flights);

  cout << endl;
  cout << "-------------------" << endl;
  cout << "|       Menu      |" << endl;
  cout << "-------------------" << endl;
  cout << "Welcome to the flight reservation system" << endl;
  cout << "What would you like to do?" << endl;
  cout << "1) Check flights" << endl;
  cout << "2) Check reservations" << endl;
  cout << "3) Cancel a reservation" << endl;
  cout << "4) Exit" << endl;
  cin >> choice;

  switch(choice){
    case 1: { 
      cout << "These are our available cities of departure" << endl;
      cout << "Please write the initials of your departure city" << endl;
      data.showCities(flights);
      cin >> departure; cout << endl;

      cout << "The flights are sorted by price" << endl;
      list = data.destinationList(flights, departure);
      data.showFlights(list);

    break; }

    case 2: {
      ifstream file;
      file.open("Ticket.txt");

      if(file){
        string line;
        cout << "Your reservation:" << endl;
        while (getline(file, line)) {
          cout << line << "\n";
        }
        file.close();
      } else {
        cout << "There are no existing reservations" << endl;
      }
    break;}

    case 3: {
      if(remove ("Ticket.txt") == 0){
        cout << "Your reservation has been successfully cancelled" << endl;
      }
    break;}

    case 4: {
      exit(0);
    }
  }

return 0;  
}
