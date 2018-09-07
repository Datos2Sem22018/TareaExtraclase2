#include <iostream>
#include "BuilderPattern.cpp"
#include "ObserverPattern.cpp"
using namespace std;

int main(){

//---------------------------------------------------------------------------------//
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
//-----------------------------------------------------------------------------------//

cout<<endl<<endl;

    ConcreteObserver observer1(1);
    ConcreteObserver observer2(4);

    cout << "Observer 1 state: " << observer1.getState() << endl;
    cout << "Observer 2 state: " << observer2.getState() << endl;

    //Creates a new Subject to update the states
    //and define the observes to update
    Subject *subject = new ConcreteSubject;
    subject->attach(&observer1);
    subject->attach(&observer2);

    //Define the new subject "10"
    subject->setState(10);
    subject->notify();

    cout << "Observer 1 state: " << observer1.getState() << endl;
    cout << "Observer 2 state: " << observer2.getState() << endl;



}