/*Use strategy pattern*/
#include <iostream>
using namespace std;
//============================================================
class Icar
{
public:
    virtual void speedUp() = 0;
    virtual void speedDown() = 0;
    virtual void Atk() = 0;
};
//============================================================
class IspeedUp
{
public:
    virtual void speedUp() = 0;
};
class IspeedDown
{
public:
    virtual void speedDown() = 0;
};
class IAtk
{
public: 
    virtual void Atk() = 0;
};
//============================================================
class HighSpeed : public IspeedUp
{
public: 
    void speedUp() { cout << "This is speed up." << endl; }
};
class DownSpeed : public IspeedDown
{
public:
    void speedDown() { cout << "This is speed down." << endl; }
};
class GunAtk : public IAtk
{
public:
    void Atk() { cout << "This use gun attack." << endl; }
};
class KnifeAtk : public IAtk
{
public:
    void Atk() { cout << "This use knife attack." << endl; }
};
//============================================================
class PorscheCar : public Icar
{
public:
    PorscheCar(IspeedUp *speedup, IspeedDown *speeddown, IAtk *atk)
    {
        this->_speedup = speedup;
        this->_speeddown = speeddown;
        this->_atk = atk;
    }
    void speedUp() { this->_speedup->speedUp(); }
    void speedDown() { this->_speeddown->speedDown(); }
    void Atk() { this->_atk->Atk(); }   
private:
    IspeedUp *_speedup; 
    IspeedDown *_speeddown; 
    IAtk *_atk;
};
//============================================================
int main()
{
    Icar *car = new PorscheCar(new HighSpeed(), new DownSpeed(), new KnifeAtk());
    car->speedUp();
    car->speedDown();
    car->Atk();

    Icar *car2 = new PorscheCar(new HighSpeed(), new DownSpeed(), new GunAtk());  //Using gun attack just modify here, no need to modify class
    car2->speedUp();
    car2->speedDown();
    car2->Atk();
    system("pause");
    return 0;
}