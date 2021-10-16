#include <iostream>
using namespace std;

void towerOfHanoi(int n,char source, char inter, char dest)
{
    if(n<1)
        return;
    if(n==1)
     {
         cout<<source<<" -> "<<dest<<endl;
         return;
     }
     towerOfHanoi(n-1,source,dest,inter);
     cout<<source<<" -> "<<dest<<endl;
     towerOfHanoi(n-1,inter,source,dest);   
}
int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
