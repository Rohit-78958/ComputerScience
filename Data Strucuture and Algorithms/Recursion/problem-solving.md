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

***fixing character by character***
```C++
if(i==s.length()-1){
 cout<<s<<endl;
 return;
}
for(int j=i;j<s.length();j++){
 swap(s[i],s[j]);
 permute(s,i+i);
 swap(s[j],s[i]);
}
```

**8. Count digits in a number:**

```C++
if(n < 10) return 1;
return 1+count(n/10);
```

***Tail recursive***
```C++
if(n == 0) return sum;   //further optimization: if(n<10) return sum+1;
return count(n/10,sum+1);
```


**8. Power set using recursion:**

***Select 1 or more charcter in sequence***

```C++
vector<string> str;//global thats why we need to clear it for every test case otherwise make separate function for calculating powerset
vector <string> powerSet(string s, string curr="",int i=0)
{
   //Your code here
   if(i==0) str.clear();
   if(i==s.length()){
       str.push_back(curr);
       return str;
   }
   
   powerSet(s,curr,i+1);
   powerSet(s,curr+s[i],i+1);
   return str;
}
```

**9. TOH**

```c++
long long toh(int N, int from, int to, int aux) {
        // Your code here
        if(N==1){
            cout<<"move disk "<< 1 <<" from rod "<< from<<" to rod "<< to<<endl;
            return 1;
        }
        toh(N-1,from,aux,to);
        cout<<"move disk "<< N<<" from rod "<< from<<" to rod "<<to<<endl;
        toh(N-1,aux,to,from);
        return pow(2,N)-1;
}
```

**10. Digital root**

***Sum of digits until we form a single digit number***
```C++
int digitalRoot(int n)
    {
        //Your code here
        if(n<10) return n;
        
        int sum = n%10 + digitalRoot(n/10);
        
        if(sum>=10) sum = sum%10 + digitalRoot(sum/10);
        
        return sum;
    }
```
***Another approach:***
```C++
int digitalRoot(int n)
{
   //Your code here
   if(n<10) return n;
   return digitalRoot(n%10+digitalRoot(n/10));
}

//or

 int digitalRoot(int n)
   {
    if (n < 10) return n;
   if(n % 9 == 0) return 9;
   return n % 9;
   }
```


**11. Possible words from phone digits**

```C++
class Solution
{
    vector<string> pw;
    
    map<int, string> keypad={
            {1,"1"},
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"},
            {0,"0"}};
    

    public:
    //Function to find list of all words possible by pressing given numbers.
    void possiblWords(int a[], int N, string curr="", int j=0)
    {
        //Your code here
        if(curr.length()==N){
            pw.push_back(curr);
            return;
        }
        
        string s = keypad[a[j]];
        for(int i=0;i<s.length();i++) possiblWords(a,N,curr+s[i],j+1);
        
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        possiblWords(a, N);
        return pw;
    }
};
```

## Notes:-

***1. last digit in binary: n%2***

***2. Repeating numbers: call recursive function betweeen two print statments***

***3. Sum of bits in 513: since 512 has 1 bit => 513 has 2 bits***
