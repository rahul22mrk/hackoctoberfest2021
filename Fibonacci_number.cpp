#include <cmath>
#include <iostream>
using namespace std;
class check_fibonnaci
{
    private:
    int n,iRoot,iRoot1;
    double root,root1;
    public:
    void getdata()
    {
        cout<<"enter the number:";
        cin>>n;
    }
    void checking_fibonacci()
    {
        root = sqrt(5.0*n*n+4.0);
        iRoot = root;
        root1 = sqrt(5.0*n*n-4.0);
        int iRoot1 = root1;
        if( root == iRoot  || root1==iRoot1)
        {
            cout << "it is a fibonacci number:" << endl;
        }
        else
        {
            cout<<"not fibonacci number:";
        }
    }
};
int main() 
{
    check_fibonnaci obj;
    obj.getdata();
    obj.checking_fibonacci();
    return 0;
}
