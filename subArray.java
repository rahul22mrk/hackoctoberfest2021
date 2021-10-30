import java.util.*;

public class SsubArray
{
	public int countFunction(int arr[],int k)
	{
		int count=0;
        for(int i=0;i<arr.length;i++)
		{
            int sum=0;
            for(int j=i;j<arr.length;j++)
			{
                sum=sum+arr[j];
				
                if(sum>=k)
				{
                    count++;
				}
            }
        }
        return count;
	}
	
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		int arr[]=new int[n];
		
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		
		System.out.println("k: ");
		int k=sc.nextInt();
		
		subArray cs = new subArray();
         
        int result=cs.countFunction(arr,k);
		
		System.out.println("Count: "+result);
	}
}
