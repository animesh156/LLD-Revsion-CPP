
// High-level modules should not depend on low-level modules. Both should depend on abstractions.
// Abstractions should not depend on details. Details should depend on abstractions.

// Don’t make your classes depend directly on concrete implementations.

// Make them depend on interfaces or abstract classes instead.

// This makes your code more flexible, maintainable, and testable.

#include <bits/stdc++.h>
using namespace std;

// class Email {
// public:
//     void sendEmail(const string& msg) {
//         cout << "Email sent: " << msg << endl;
//     }
// };

// class NotificationService {
//     Email email; // depends on concrete class
// public:
//     void notify(const string& msg) {
//         email.sendEmail(msg);
//     }
// };

// Interface for sender
class IMessageSender
{
public:
    virtual void sendMessage(string &msg) = 0;
    virtual ~IMessageSender() = default;
};

// low-level module
class EmailSender : public IMessageSender
{
public:
    void sendMessage(string &msg) override
    {
        cout << "Email sent: " << msg << endl;
    }
};

// low-level module
class SMSSender : public IMessageSender
{
public:
    void sendMessage(string &msg) override
    {
        cout << "SMS sent: " << msg << endl;
    }
};

// low-level module
class WhatsAppSender : public IMessageSender
{
public:
    void sendMessage(string &msg) override
    {
        cout << "WhatsApp sent: " << msg << endl;
    }
};

// High level Module
class NotificationService
{
    IMessageSender *sender;

public:
    NotificationService(IMessageSender *s) : sender(s) {}
    void notify(string &msg)
    {

        sender->sendMessage(msg);
    }
};

int main()
{

    EmailSender email;
    SMSSender sms;
    WhatsAppSender whatsapp;

    NotificationService service1(&email);
    string msg1 = "Hello via mail";
    service1.notify(msg1);

    NotificationService service2(&sms);
    string msg2 = "Hello via SMS";
    service2.notify(msg2);

    NotificationService service3(&whatsapp);
    string msg3 = "Hello via whatsapp";
    service3.notify(msg3);

    return 0;
}