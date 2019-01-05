// http://monkeycoding.com/?p=969
#include <iostream>
#include <string>
using namespace std;

class Singleton {
public:
    static Singleton *getInstance() {
        if (m_instance == NULL) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
    static void ResetInstance()
    {
        cout << "reset instance" << endl;
        delete m_instance; // REM : it works even if the pointer is NULL (does nothing then)
        m_instance = NULL; // so getInstance will still work.
    }
    ~Singleton() 
    { 
        cout << "call delete" << endl;
        //delete m_instance;    /// The system goes in infinate loop here if i uncomment this (the destructor also calls the destructor)
        // https://stackoverflow.com/questions/8699434/how-to-delete-singleton-pointer
    }
private:
    static Singleton *m_instance;
    Singleton() {}
    
};
Singleton* Singleton::m_instance = NULL;

int main() {
    Singleton *instance1 = Singleton::getInstance();
    Singleton *instance2 = Singleton::getInstance();
    int addr1 = (int)instance1;
    int addr2 = (int)instance2;
    cout << "addr1: " << addr1 << endl;
    cout << "addr2: " << addr2 << endl;
    
    //Singleton::ResetInstance();
    
    delete instance1;

    system("pause");
    return 0;
}
