#include<iostream>
#include<vector>
using namespace std;
class Cycle
{
    public:
    vector<vector<int>>adj;
    Cycle(vector<vector<int>>adj)
    {
        this->adj=adj;
    }
}