#include <iostream>
using namespace std;
class Fraction
{
public:
    int num;
    int den;
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    void display()
    {
        cout << num << " / " << den << endl;
    }
    Fraction operator+(Fraction frac)
    {
        int newnum = this->num * frac.den + frac.num * this->den;
        int newden = this->den * frac.den;
        Fraction ans(newnum, newden);
        return ans;
    }
};
int main()
{
    Fraction f1(1, 7);
    Fraction f2(1, 2);
    Fraction f3 = f1 + f2;
    f3.display();
    return 0;
}