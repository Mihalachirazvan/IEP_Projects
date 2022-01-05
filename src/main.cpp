#include <iostream>
#include "payment.h"
#include <regex>
#include <string>

std::regex regex_Number("[0-9]+");
std::regex regex_Date("(1[0-2]|0[1-9])/(2[1-9]|[3-9][0-9])");

class PaymentCard : public Payment {
    private:
    char cardNumber[17];
    char CVC[4];
    char expDate[6];
    public :
    char* getCardNR() {
        return cardNumber;
    }
    char* getCVC() {
        return CVC;
    }
    char* getExpDate() {
        return expDate;
    }
    public:
    PaymentCard(int sum,const char* number,const char* cvcNr , const char* date):Payment(sum) {
        if(            
            (std::regex_match(number,regex_Number) && strlen(number)==16) &&
            (std::regex_match(cvcNr,regex_Number) && strlen(cvcNr)==3) &&
            (std::regex_match(date,regex_Date) && strlen(date)==5)
        ) { 
            strcpy(CVC,cvcNr);
            strcpy(cardNumber,number);
            strcpy(expDate,date);
        }
        else {
            perror("not good inputs values");
            exit(1);
        }
    }
    PaymentCard(PaymentCard &p) {
        std::cout<<"Copy an Payment Card"<<std::endl;
         strcpy(cardNumber,p.cardNumber);
         strcpy(CVC,p.CVC);
         strcpy(expDate,p.expDate);
         Sum = p.Sum;
    }
    PaymentCard& operator = (PaymentCard &p) {
          std::cout<<"Copy assignment of an Payment Card"<<std::endl;   
          strcpy(cardNumber,p.cardNumber);
          strcpy(CVC,p.CVC);
          strcpy(expDate,p.expDate);
          Sum = p.Sum;
          return *this;
    }
    ~PaymentCard() {
          std::cout<<"Delete an Payment Card"<<std::endl;
        
    }
};

int main() {

    Payment p1(200);
    std::cout<<"Payment p1: Suma:"<<p1.getSum()<<std::endl;
    Payment p2(250);
     std::cout<<"Payment p2: Suma:"<<p2.getSum()<<std::endl;
    Payment p3(p2);
     std::cout<<"Payment p3: Suma:"<<p3.getSum()<<std::endl;
    p1=p3;
     std::cout<<"Payment p1: Suma:"<<p1.getSum()<<std::endl;

    PaymentCard p4(234,"4123567898761234","123","12/21");

     std::cout<<"Payment Card p4: Suma:"<<p4.getSum()<<" Card numer:"<<p4.getCardNR()<<" CVC:"<<p4.getCVC()<<" Date:"<<p4.getExpDate()<<std::endl;
    //PaymentCard p5(234,"412356789876A234","12A","32/21");




}
