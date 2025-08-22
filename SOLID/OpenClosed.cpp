// Open/Closed Principle :- This principle states that "Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification" which means you should be able to extend a class behavior, without modifying it.

// So, virtual functions matter only when you’re using base class pointers/references to access derived objects.
// Base* b = new Derived();
// b->show();
// Virtual function = “I’ll provide default behavior, but you may override me.”

// Pure virtual function = “I’m just a contract → you must implement me in the derived class.”

#include <bits/stdc++.h>
using namespace std;

// base class for payment processing
class Payment
{
public:
    // pure virtual function
    virtual void processPayment(double amount) = 0;

    // void processPayment(double amount)
    // {
    //     cout << amount << endl;
    // }
};

class CreditCardPayment : public Payment
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing credit card payment of $" << amount << endl;
    }
};

// extending paypal payment
class PaypalPayment : public Payment
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

// extending to UPI payment
class UPIPayment : public Payment
{
public:
    void processPayment(double amount) override
    {
        cout << "Processing UPI payment of $" << amount << endl;
    }
};

int main()
{

    Payment *p1 = new CreditCardPayment();
    Payment *p2 = new PaypalPayment();
    Payment *p3 = new UPIPayment();

    p1->processPayment(589.78);
    p2->processPayment(234.56);
    p3->processPayment(456.45);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}