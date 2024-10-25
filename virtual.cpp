#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void sound() = 0;
        virtual void move(){
            cout << "Animals can move" << endl;
        }
};

class Dog : public Animal{
    public:
        void sound() override{
            cout << "Dog barks" << endl;
        }
        void move() override{
            cout << "Dog runs" << endl;
        }
};

class Bird : public Animal{
    public:
        void sound() override{
            cout << "Bird chirps" << endl;
        }
        void move() override{
            cout << "Bird flies" << endl;
        }
};

int main(){

    Animal* animal1 = new Dog();
    Animal* animal2 = new Bird();

    animal1->sound();
    animal1->move();

    animal2->sound();
    animal2->move();

    delete animal1;
    delete animal2;

    return 0;
}