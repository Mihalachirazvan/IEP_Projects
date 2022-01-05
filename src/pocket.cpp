#include <iostream>
#include <memory>

class Pocket {
    private:
    int value;
    bool isLocked = false;
    public:
    Pocket(int value) {
        this->value = value;
        std::cout<<"Initialization of an Pocket"<<std::endl;
    }
     Pocket(Pocket &p) {
        std::cout<<"Copy an Pocket"<<std::endl;
        this->value = p.value;
    }
    ~Pocket() {
        std::cout<<"Delete a Pocket"<<std::endl;
    }
    void get_Value() {
        std::cout<<"Value of pocket:"<<value<<std::endl;
    }
    void give(int value) {
        if(this->value>0)
        this->value = this->value - value;
    }
    void take(int value) {
        this->value = this->value + value;
    }
    void setLock(bool state) {
        this->isLocked = state;
    }
    void askPocket() {
        if(this->isLocked) 
            std::cout<<"Pocket is locked"<<std::endl;
            else
            std::cout<<"Pocket is ready for use"<<std::endl;
    }
};
Pocket* createPocketInstance(int value) {
    return (new Pocket(value));
}
void lock(Pocket &p) {
    std::cout<<"Locking Pocket"<<std::endl;
    p.setLock(true);
}
void unlock(Pocket &p) {
    std::cout<<"Unlocking Pocket"<<std::endl;
    p.setLock(false);
}

    class LockPocket {
        private:
            Pocket &lock_Pocket;
        public:
        LockPocket(Pocket &p):lock_Pocket(p) {
            lock(lock_Pocket);
        }
        ~LockPocket() {
            unlock(lock_Pocket);
        }
    };

using namespace std;
int main() {

    std::cout<<"smart pointer AUTO"<<std::endl;

    //auto_ptr<Pocket> pocket_auto(createPocketInstance(10));
    
    std::cout<<"smart pointer UNIQUE"<<std::endl;
    {
    unique_ptr<Pocket> pocket_unique(createPocketInstance(20));
    pocket_unique->get_Value();
    unique_ptr<Pocket> pocket_unique_2 = move(pocket_unique);
    pocket_unique_2->get_Value();
    }
    std::cout<<"smart pointer SHARED"<<std::endl;
    {
    shared_ptr<Pocket> pocket_shared(createPocketInstance(50));
    pocket_shared->get_Value();
    std::cout<<"shared pocket NO:"<<pocket_shared.use_count()<<std::endl;
    shared_ptr<Pocket> pocket_shared_2(pocket_shared);
    std::cout<<"shared pocket NO:"<<pocket_shared_2.use_count()<<std::endl;
    pocket_shared_2->get_Value();
    pocket_shared_2->take(10);
    pocket_shared->get_Value();

    shared_ptr<Pocket> pocket_shared_3 = move(pocket_shared);
    std::cout<<"shared pocket NO:"<<pocket_shared.use_count()<<std::endl;
    std::cout<<"shared pocket NO:"<<pocket_shared_3.use_count()<<std::endl;
    pocket_shared_3->give(20);
    pocket_shared_3->get_Value();
    pocket_shared_2->get_Value();

  
    }  

    Pocket p(20);
    LockPocket *lock_pocket = new LockPocket(p);
    p.askPocket();
    delete lock_pocket;
    p.askPocket();
    p.get_Value();
}
