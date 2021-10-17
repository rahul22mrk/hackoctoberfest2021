#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int india = 0;
        int england = 0;
        int draw = 0;
        vector<int>vec1;
        for(int i=0;i<5;i++){
            int a;
            cin>>a;
            vec1.push_back(a);
        }
        for (int i = 0; i < vec1.size(); i++)
        {
            if(vec1[i] == 1){
                india = india +1;
            }
            else if (vec1[i] == 2){
                england = england+1;
            }
            else {
                draw = draw +1;
            }
        }
        if(india > england){
            cout<<"INDIA"<<endl;
        }
        else if(england>india){
            cout<<"ENGLAND"<<endl;
        }
        else {
            cout<<"DRAW"<<endl;
        }
        
    }
}
