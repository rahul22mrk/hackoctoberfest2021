#include<bits/stdc++.h>

using namespace std;

int checkGcd(int a, int b){
	if(a==0 || b == 0)
		return b;
	else
	   return checkGcd(b%a,a);
}
int main(){
	int firstNumber,secondNumber,result;
	cout<<"GCD of two numbers\n";
	cout<<"Enter First Number\n";
	cin>>firstNumber;
	cout<<"Enter Second Number\n";
	cin>>secondNumber;
	if(firstNumber>secondNumber){
		result = checkGcd(secondNumber,firstNumber);
	}
	else{
		result = checkGcd(firstNumber,secondNumber);
	}
	cout<<"GCD is  - "<<result<<endl;
return 0;
}
