/*
#include <iostream>
class B
{
    public:
        B() { i = 0; f = 0.0; d = 0.0; }
        double d;
        void g1(B b) { f = b.f; }
    protected:
        float f;
    private:
        int i;
};
class X : public B
{
    public:
        X() { s = 0; }
        void g2(X x) { f = x.f; }
        //void g3(B b) { f = b.f; }
    protected:
        short s;
};
int main()
{
    B b1;
    X x1;
    x1.g1(b1);
    return 0;
}
*/