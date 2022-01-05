#include <iostream>

class Payment {
    protected:
    int Sum;
    public:
    Payment() {
        std::cout<<"default constructor"<<std::endl;
    }
    Payment(int sum) {
        std::cout<<"Initialization of an Payment"<<std::endl;
        Sum = sum;
    }
    int getSum() {
        return Sum;
    }
    Payment(Payment &p) {
        std::cout<<"Copy an Payment"<<std::endl;
        Sum = p.Sum;
    }
    Payment& operator = (Payment &p) {
          std::cout<<"Copy assignment of an Payment"<<std::endl;   
          Sum = p.Sum;
          return *this;
    }
    ~Payment() {
          std::cout<<"Delete an Payment"<<std::endl;
    }

};
