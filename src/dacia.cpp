#include <iostream>
#include "vehicle.hpp"

class Dacia : public Vehicle {

    private :
    int horsePower;
    int comustibleCapacity;
    public :
    int getHorsePower() {
        return horsePower;
    }
    int getComustibleCapacity() {
        return comustibleCapacity;
    }
    void swap(Dacia &d) {
        std::swap(horsePower,d.horsePower);
        std::swap(comustibleCapacity,d.comustibleCapacity);
    }
    Dacia(int people,int power, int capacity):Vehicle(people) {
        std::cout<<"Initialization of a Dacia"<<std::endl;
        horsePower = power;
        comustibleCapacity = capacity;
    }
    Dacia(Dacia &d):Vehicle(d) {
        std::cout<<"Copy an Dacia"<<std::endl;
        horsePower = d.horsePower;
        comustibleCapacity = d.comustibleCapacity;

    }
    Dacia& operator = (Dacia &d) {
        std::cout<<"Copy assignement of an Dacia"<<std::endl;
        Dacia temp(d);
        Vehicle::operator=(temp);
        swap(temp);
        return *this;

    }
    ~Dacia() {
        std::cout<<"Delete a Dacia"<<std::endl;
    }
    void output() {
        std::cout<<"Dacia"
            <<" ->peopleCapacity :"<<peopleCapacity
            <<" horsePower :"<<horsePower
            <<" compustibleCapacity :"<<comustibleCapacity
            <<std::endl;
    
    }
};

int main() {

    Dacia d1(4,200,100);
    Dacia d2(2,200,98);
    Dacia d3(1,250,150);
    d1.output();
    d2.output();
    d3.output();
    
    d1=d1;
    d1.output();
    d1=d2=d3;
    d1.output();
    d2.output();
    d3.output();
    


}