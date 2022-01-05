
#include <iostream>

class Vehicle {

    protected:
    int peopleCapacity;
    public:
    Vehicle(int Capacity) {
        std::cout<<"Initialization of Vehicle capacity"<<std::endl;
        peopleCapacity = Capacity; 
    }
    int getpeopleCapacity() {
        return peopleCapacity;
    }
    void swap(Vehicle &v) {
        std::swap(peopleCapacity,v.peopleCapacity);
    }
    Vehicle(Vehicle &v) {
        std::cout<<"Copy an Vehicle"<<std::endl;
        peopleCapacity = v.peopleCapacity;
    }
    Vehicle& operator = (Vehicle &v) {
        std::cout<<"Copy assignement of an Vehicle"<<std::endl;
        Vehicle temp(v);
        swap(temp);
        return *this;
    }
    ~Vehicle() {
        std::cout<<"Delete a Vehicle"<<std::endl;
    }

};