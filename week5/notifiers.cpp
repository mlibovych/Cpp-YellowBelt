#include <iostream>

using namespace std;

void SendSms(const string& number, const string& message);

void SendEmail(const string& email, const string& message);

class INotifier {
public :
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
    const string number;
public :
    SmsNotifier (const string& number_) : number(number_) {

    }

    void Notify(const string& message) override {
        SendSms(number, message);
    }
};

class EmailNotifier : public INotifier {
    const string mail;
public :
    EmailNotifier (const string& mail_) : mail(mail_){

    }

    void Notify(const string& message) override {
        SendEmail(mail, message);
    }
};

// void Notify(INotifier& notifier, const string& message) {
//   notifier.Notify(message);
// }


// int main() {
//   SmsNotifier sms{"+7-495-777-77-77"};
//   EmailNotifier email{"na-derevnyu@dedushke.ru"};

//   Notify(sms, "I have White belt in C++");
//   Notify(email, "And want a Yellow one");
//   return 0;
// }