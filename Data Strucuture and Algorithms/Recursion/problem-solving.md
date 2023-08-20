### Tail Recursion

```
 -> All functions can't be made tail recursive
 -> It is optimized by modern compilers
 -> We need to introduce another default parameter k to make a recursive function tail recursive.
```

### Recursion
***Think in terms of smaller problems***

**1. Sum of first n natural numbers:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**2. Check the palindrome of a number:** 
```C++
//my approach
pali(s,i=0){
  if(i>s.length()/2) return true;
  if(s[i]!=s[s.length()-1-i]) return false;
  return pali(s,i+1);
}

//other approach
pali(str, s,e){
  if(s>=e) return true;
  return (str[s]==str[e]) && pali(str,s+1,e-1);  //short circuiting
}
```
**3. Sum of digits of a number:** 
***O(d)***
```C++
if(n==0) return n;  //further optimization: if(n<=9) return n;
return n%10 +sum(n/10);
```
**4. Rope cutting problem:** Find the maximum number of pieces in which rope can be cut
***O(3^n)***
```C++
if(n==0) return 0;
if(n < 0) return -1;
int res = max(maxi(n-a,a,b,c), maxi(n-b,a,b,c), maxi(n-c,a,b,c));
if(res==-1) return -1;
return res+1;
```
**5. Generate subsets:** 
***Subsequences: String obtained after removing 0 or more characters.***

***O(length of string)***
```C++
//if we had subset of length 2 how we would have got for 3 from it
if(i==s.length()){
 cout<<curr<<" ";
 return;
}
subset(s,curr,i+1);
subset(s,curr+s[i],i+1);
```
**6. TOH:** 
***O(2^n)***
```C++
if(n==1){
 cout<<"move disk 1 from"<<A<<" to "<<C<<endl;
 return;
}
TOH(n-1,A,C,B);
cout<<"move disk "<<n<<" from"<<A<<" to "<<C<<endl;
TOH(n-1,B,A,C);
```
**6. Josephus problem:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**7. Sum of subsets:** 
```C++
void gen_subset(int arr[], int n, vector<int> &v){
    if(n==0){
        for(auto i: v)cout<<i<<" ";
        cout<<endl;
        return;
    }
    gen_subset(arr,n-1,v);
    v.push_back(arr[n-1]);
    gen_subset(arr,n-1,v);
    v.pop_back();
}
```

```C++
if(n==0) return sum==0?1:0;
return sum(arr,n-1,sum)+sum(arr,n-1,sum-arr[n-1]);
```
**8. Print all permutations:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
