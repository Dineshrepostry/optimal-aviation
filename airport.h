#include <bits/stdc++.h>
class Graph;
using namespace std; 

vector<string> cities = {"Chennai" , "Mumbai" , "Delhi" , "Paris" , "London" , 
"New York" , "Melbourne" , "Dubai" , "Berlin" , "Moscow" , "Rome" , "Rio de Janeiro" , 
"Toronto" , "Los Angeles" , "Bejing" , "Singapore"};

vector<string> names= {"Madras International Meenambakkam Airport", "Chhatrapati Shivaji Maharaj International Airport", 
"Indira Gandhi International Airport New", "Paris Charles de Gaulle airport", 
"London Heathrow Airport (LHR)", "John F. Kennedy International Airport","airport Tullamarine", "DXB Dubai International Airport", 
"Berlin Brandenburg Airport Willy Brandt", "Sheremetyevo International Airport", "Rome–Fiumicino International Airport", "Rio de Janeiro/Galeão International Airport",
 "Toronto Pearson International Airport", "Los Angeles International Airport (LAX)", "Beijing Capital International Airport", "Singapore Changi Airport" };

int n = cities.size() ; 


class airportclass{
    string city;
    string name;
    int node_no;

    public:
        string city_name(){
            return city;
        }

        string airport_name(){
            return name;
        }

        void set_airport(string c, string nm, int n){
            city = c;
            name = nm;
            node_no = n;
        }
        friend class Graph;

};

vector<airportclass> airport(n);

void create_airports(){
    for(int x = 0; x < n; x++){
        airport[x].set_airport(cities[x],names[x], x);
    }
}


