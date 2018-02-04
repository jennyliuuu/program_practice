#include <iostream>
#include <list>
#include <string>
using namespace std;


class IObserver
{
public:
    virtual void update(string s) = 0;// { cout << "iii" << endl; }
    //bool operator == (const IObserver &);
    virtual string get_name() = 0;
};

class ISubject
{
public:
    virtual void registerObserver(IObserver *ob) = 0;  //need declare IObserver before ISubject!!!
    virtual void removeObserver(IObserver *ob) = 0;
    virtual void notifyObserver(string content) = 0;
};

class NewspaperOffice : public ISubject
{
public:
    NewspaperOffice() { observer = new list<IObserver*>; }
    ~NewspaperOffice() {}
    void registerObserver(IObserver *ob);
    void removeObserver(IObserver *ob);
    void notifyObserver(string content);
    
private:
    list<IObserver*> *observer;      //IObserver can't be an abstract class   //!!!!
};

class Customer : public IObserver
{
public:
    Customer(string _name) : name(_name) {}
    void update(string s);
    string get_name() { return name; }
private:
    string name;
};
/*
bool IObserver::operator==(const IObserver & b)//!!!!
{
    if (name == b.name)
        return true;
    else
        return false;
}
*/
void NewspaperOffice::registerObserver(IObserver *ob)
{
    observer->push_back(ob);
    cout << "registerObserver..." << ob->get_name() << endl;
}

void NewspaperOffice::removeObserver(IObserver *ob)
{
    observer->remove(ob);
    cout << "removeObserver..." << ob->get_name() << endl;
}

void NewspaperOffice::notifyObserver(string content)
{
    for (list<IObserver*>::iterator it = observer->begin(); it != observer->end(); it++)
        (*it)->update(content);     //!!!!
}

void Customer::update(string s)
{
    cout << name << " got the message: " << s << endl;
}

int main()
{
    NewspaperOffice *newoff = new NewspaperOffice();
    
    Customer *customer_a = new Customer("jenny");
    newoff->registerObserver(customer_a);
    newoff->notifyObserver("hello");
    Customer *customer_b = new Customer("weber");
    newoff->registerObserver(customer_b);
    newoff->notifyObserver("hi");
    newoff->removeObserver(customer_b);  
    system("pause");
    return 0;
}


