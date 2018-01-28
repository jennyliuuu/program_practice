/*Doesn't use strategy pattern*/
//#include <iostream>
//using namespace std;
//
//class Icar
//{
//public:
//    virtual void speedUp() = 0;
//    virtual void speedDouwn() = 0;
//    virtual void Atk() = 0;
//};
//
//class PorscheCar : public Icar
//{
//public:
//    void speedUp() { cout << "This is speed up." << endl; }
//    void speedDouwn() { cout << "This is speed down." << endl; }
//    void Atk() { cout << "This use gun attack." << endl; }   // If you want to use knife attack, you need to modify this function.
//};
//
//int main()
//{
//    Icar *car = new PorscheCar();
//    car->speedUp();
//    car->speedDouwn();
//    car->Atk();
//    system("pause");
//    return 0;
//}
