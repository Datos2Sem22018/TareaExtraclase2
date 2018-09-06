#include <iostream>
#include "BuilderPattern.cpp"
using namespace std;

int main(){


    cout << "Builder Pattern"<<endl<<endl;
    Car *car; // Final product

    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    cout << "Jeep" << endl;
    director.setBuilder(&jeepBuilder); // using JeepBuilder instance
    car = director.getCar();
    car->specifications();

    cout << endl;


    /* Build a Nissan */
    cout << "Nissan" << endl;
    director.setBuilder(&nissanBuilder); // using NissanBuilder instance
    car = director.getCar();
    car->specifications();

}