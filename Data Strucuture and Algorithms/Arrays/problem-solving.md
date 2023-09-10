```
Tricks for O(n) time complexity:-
-> res variable approach
-> two pointers approach
-> prefix and suffix sum approach
-> encoding decoding approach
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


### 8. Trapping rain water

***res+=min(lmax[i],rmax[i])-arr[i]***

***Appraoch1:*** O(n^2) =>calculating lmax and rmax for each element 

***Appraoch2:*** O(n) time and space => precomputing lmax and rmax


### 9. Maximum consecutive one's

***Appraoch1:*** O(n^2) =>checking for each element and updating res after every inner loop

***Appraoch2:*** O(n) time => using two variables res, cnt which becomes 0 when arr[i]==0 and res is updated.


### 10. Maximum index

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


### 11. Check if array is sorted and rotated

***Appraoch1:*** O(n^2) =>rotate every time and check if it is sorted in inc. or dec. order

***Appraoch2:*** O(n) time =>If array is increasing then it has one fall and n - 2 rises, and also arr[0] must be greater than arr[n-1];
Similarly, If array is decreasing then it has one rise and n - 2 falls, and also arr[0] must be lesser than arr[n-1];


### 12. Rearrange an array in O(1) space

***Appraoch1:*** O(n) space and time =>storing all elements in auxillary array appraoch

***Appraoch2:*** O(n) time => encoding decoding appraoch
```C++
void arrange(long long arr[], int n) {
        // Your code here
        for(int i = 0;i < n; i++)
            arr[i] = arr[i] + (arr[arr[i]]%n)*n;
        for(int i = 0; i < n; i++)
            arr[i] = arr[i]/n; //to get new values   and  arr[i]%n to get old  values
    }
```


### 13. Rearrange array alternatively with max-min elements

```if array not sorted then sort it first```

***Appraoch1:*** O(n^2) =>for every iteration we either find for max or min and swap values

***Appraoch2:*** O(n) time and space => two pointers approach and extra space
                                     => storing first half and putting large values at even places and and smaller values at odd postions

***Appraoch3:*** O(n) time => encoding - decoding approach


### 14. Smallest Positive missing number

***Appraoch1:*** O(n^2) =>checking for each element with i, if present increment i and if not present return i

***Appraoch2:*** O(n) time and space => incrementing the count of each value and returning the value with 0 count

***Appraoch3:*** O(nlogn) time => sorting the array and checking for each element

***Appraoch4:*** O(n) time => segregating positive numbers then marking the number negative that is present at index using arr[arr[i]] and printing the psotive index+1



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



