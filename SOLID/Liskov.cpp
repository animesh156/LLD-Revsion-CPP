// The principle was introduced by Barbara Liskov in 1987 and according to this principle "Derived or child classes must be substitutable for their base or parent classes". This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behaviour.

// If class B inherits from class A, then anywhere you use A, you should be able to use B without unexpected behavior.

#include <bits/stdc++.h>
using namespace std;

// // good LSP
// class Bird
// {
// public:
//     virtual void fly()
//     {
//         cout << "Bird is flying" << endl;
//     }
// };

// class Sparrow : public Bird
// {
// public:
//     void fly() override
//     {
//         cout << "Sparrow is flying" << endl;
//     }
// };

// class Ostrich : public Bird
// {
// public:
//     // violates law as ostrich can't fly
//     void fly()
//     {
//         cout << "Ostrich can't fly" << endl;
//     }
// };

// better design
class Bird
{
};

class FlyingBird : public Bird
{
public:
    virtual void fly() = 0;
};

class Ostrich : public Bird
{
public:
    void swim()
    {
        cout << "Penguin swims" << endl;
    }
}; // no fly

class Sparrow : public FlyingBird
{
public:
    void fly() override
    {
        cout << "Sparrow flies" << endl;
    }
};

int main()
{
    // Bird *b = new Sparrow(); // Substitution works fine coz sparrow can fly
    // Bird *c = new Ostrich(); //  Wrong behavior → violates LSP
    FlyingBird *b = new Sparrow();
    b->fly();
    // c->fly();
    delete b;
    // delete c;
    return 0;
}