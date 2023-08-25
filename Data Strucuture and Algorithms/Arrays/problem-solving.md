```
Tricks for O(n) time complexity:-
-> res variable approach
-> two pointers approach
-> prefix and suffix sum approach
```

### 1. Remove duplicates from sorted array
***Appraoch1:*** O(n^2)

***Appraoch2:*** O(n) space and time

***Appraoch3:*** O(n) time --> res variable approach


### 2. Move zeros to end
***Appraoch1:*** O(n^2)

***Appraoch2:*** O(n) space and time

***Appraoch3:*** O(n) time --> res variable approach


### 3. Left rotate an array by D places
***Appraoch1:*** O(n*D)

***Appraoch2:*** O(n) space and time

***Appraoch3:*** O(n + D) time --> reverse first d then (n-d) and finally all n elements


### 4. Leaders in an array
***Element with no greater and equal element on right of it.***

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => using maxi variable approach but printed in reverse order => original order O(nlogn) or storing in an auxillary array and reversing it which contributes O(n) auxilary space as well.


### 5. Maximum difference problem
***max(arr[j]-arr[i]) such that j>i***
***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => subtracting each element with minimum element and continuously updating minimum element


### 6. Frequency of each element in sorted array

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => two pointers approach 


### 7. Stock Buy and Sell

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => adding up the difference whenever there is profit => p[i]>p[i-1]


### 6. Trapping rain water

***res+=min(lmax[i],rmax[i])-arr[i]***

***Appraoch1:*** O(n^2) =>calculating lmax and rmax for each element 

***Appraoch2:*** O(n) time and space => precomputing lmax and rmax


### 6. Maximum consecutive one's

***Appraoch1:*** O(n^2) =>checking for each element and updating res after every inner loop

***Appraoch2:*** O(n) time => using two variables res, cnt which becomes 0 when arr[i]==0 and res is updated.


### 6. Maximum index

***find max(j-i) such that a[i]<=a[j] for j<=i***

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time & space
```C++
int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        int lmin[n],rmax[n];
        lmin[0]=a[0];
        rmax[n-1]=a[n-1];
        for(int i=1;i<n;i++) lmin[i]=min(a[i],lmin[i-1]);
        for(int i=n-2;i>=0;i--) rmax[i]=max(a[i],rmax[i+1]);
        
        int res=0, i=0,j=0;
        while(i<n && j<n){
            if(lmin[i]<=rmax[j]){
                res=max(res,j-i);
                j++;
            }
            else i++;
        }
        
        return res;
}
```


### 6. Frequency of each element in sorted array

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => two pointers approach 


### 6. Frequency of each element in sorted array

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => two pointers approach 


### 6. Frequency of each element in sorted array

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => two pointers approach 


### 6. Frequency of each element in sorted array

***Appraoch1:*** O(n^2) =>checking for each element

***Appraoch2:*** O(n) time => two pointers approach 



