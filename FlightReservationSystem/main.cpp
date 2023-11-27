// Made by Daniel Contreras Chávez A01710608
// El 13 de noviembre del 2023

#include <iostream>
#include <fstream>
#include "flights.h"
#include "flightManagement.h"
#include "menu.h"
#include "list.h"
#include <vector>

using namespace std;

int main() {
  
  FlightManagement data;
  vector<Flights> flights;
  List<Flights> list;
  bool run = true;

  while(run){
    menu(flights, data, list);
  }

  return 0;
}