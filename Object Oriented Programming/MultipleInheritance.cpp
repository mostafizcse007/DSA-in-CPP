#include <iostream>
#include <string>
using namespace std;
class Footballer
{
public:
    int age;
    string stFoot;
    Footballer(int age, string stFoot) : age(age), stFoot(stFoot) {}
};
class Engineer
{
public:
    int experience;
    string fvtLang;
    Engineer(int experience, string fvtLang) : experience(experience), fvtLang(fvtLang) {}
};
class Expert : public Footballer, Engineer
{
public:
    string name;
    Expert(string name, int experience, string fvtLang, int age, string stFoot) : name(name), Engineer(experience, fvtLang), Footballer(age, stFoot) {}
};
int main()
{
    string nm;
    getline(cin, nm);
    int exp;
    cin >> exp;
    string lang;
    cin >> lang;
    int ag;
    cin >> ag;
    string foot;
    cin >> foot;
    Expert e1(nm, exp, lang, ag, foot);
    cout << e1.stFoot << endl;
    return 0;
}