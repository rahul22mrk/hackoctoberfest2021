#include<bits/stdc++.h>
using namespace std;

int main(){
	int minValue = 0;
	int maxValue = 100;
	int wrongAttempt = 0;
	int resultNumber = (rand()%100 + rand()%10)%100;
	int guessNumber = 0;
	while(1){
		 cout<<"Number is b/w "<<minValue<<" and "<<maxValue;
		cout<<"\n\t\t\t\t\tEnter Your Guess!!\n";
		cin>>guessNumber;
		if(guessNumber<=minValue || guessNumber>=maxValue){
			wrongAttempt++;
			continue;
		}
		else{
			if(guessNumber == resultNumber){
				cout<<"Hurreeee! You Guess it successfully.";
				cout<<"WRONG ATTEMPTS - "<<wrongAttempt;
				break;
			}
			else{
				wrongAttempt++;
				if(guessNumber<resultNumber){
					minValue = guessNumber;
				}
				else if(guessNumber>resultNumber){
					maxValue = guessNumber;
				}
			}
		}
	}
}
