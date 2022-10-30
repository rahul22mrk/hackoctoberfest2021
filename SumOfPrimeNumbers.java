public class SumOfPrimeNumbers  
{  
public static void main(String args[])   
{  
int count, sum = 0;  
//the loop executes 100 time and increments the variable number by 1 after each iteration  
for(int number = 1; number <= 200; number++)  
{  
count = 0;  
for (int i = 2; i <= number/2; i++)  
{  
//find the remainder and check if it is equal to 0 or not      
if(number % i == 0)  
{  
//increments the count variable by 1 if the above condition returns true  
count++;  
break;  
} //end of if statement   
} //end of for loop  
//returns true if both conditions are true  
if(count == 0 && number != 1 )  
{  
//calculates the sum of prime numbers      
sum = sum + number;  
}  //end of if statement   
}  //end of for loop  
//prints the sum  
System.out.println("The Sum of Prime Numbers from 1 to 200 is: " + sum);  
} //end of main  
} //end of class
