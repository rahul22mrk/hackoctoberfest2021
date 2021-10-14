#Initialize array   
arr = [1, 2, 3, 4, 2, 7, 8, 8, 3];   
   
print("Duplicate elements in given array: ");  
#Searches for duplicate element  
for i in range(0, len(arr)):  
    for j in range(i+1, len(arr)):  
        if(arr[i] == arr[j]):  
            print(arr[j]);  
