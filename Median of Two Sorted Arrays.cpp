class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        int n=n1+n2-1;
        int arr3[n+1];
	    int k=0;
	int j=0;
	int i=0;	
	while(i<n1&&j<n2)
	{    	
			if(arr1[i]>arr2[j])
				arr3[k++]=arr2[j++];
			else
				arr3[k++]=arr1[i++];
	}
	while(i<n1)
	{
		arr3[k++]=arr1[i++];
	}
	while(j<n2)
	{
		arr3[k++]=arr2[j++];
	}
        int a=n+1;
        double median;
        if((n-1)%2)
        {
            median=arr3[((a+1)/2)-1];
        }
        else if(n%2)
        {
            median=((arr3[a/2]+arr3[(a/2)-1])/(double)2);
        }
        return median;
}
     
};

