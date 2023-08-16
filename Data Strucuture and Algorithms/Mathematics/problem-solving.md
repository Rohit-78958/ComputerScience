### 1. Check Prime Numbers

**Brute force approach:**
```c++
for(int i=2;i<n;i++){
  if(n%i==0) return false;
}
return true;
```
**Better approach:** If a particular number is divisible it will go maximum upto n/2(since n/2 * 2 = n) after n/2 there will be no number that divides n
```c++
for(int i=2;i<n;i++){
  if(n%i==0) return false;
}
return true;
```
**Best approach:** Factors of values more than the square root of n are mirror images of values less than that.
```c++
for(int i=2;i*i<n;i++){
  if(n%i==0) return false;
}
return true;
```
**Best approach2:** Further optimizations
```c++
if(n < 2) return false;
if(n < 4) return true;
if(n%2==0 || n%3==0) return false;
for(int i=5;i*i<n;i+=6){
  if(n%i==0 || n%(i+2)==0) return false;
}
return true;
```



### 2.Exactly 3 divisors
**Brute force approach:**
```c++
int res=0,div=0;
for(int i=1;i<n;i++){
  div=0;
  for(int j=1;j<=i;j++){
    if(i%j==0) div++;
  }
  if(div == 3) res++;
}
return res;
```
**Better approach:** A number has 3 divisors if it is a square of a prime number. For example, 4 is a square of prime number 2. Here 4 has 3 divisors. 1,2,4.
```c++
 bool isprime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }    
        
        return true;
    }
    
    bool perfect_square(int n){
        for(int i=2;i*i<=n;i++){
            if(i*i == n) return true;
        }
        return false;
    }
    
    int exactly3Divisors(int N)
    {
        //Your code here
        int res=0;
        for(int i=4;i<N;i++){
            int ps = perfect_square(i); 
            if(ps) (isprime(sqrt(i)))?res++:res;
        }
        
        return res;
    }
```
**Best approach:** further optimization, count equals the number of prime numbers in the range of [2, sqrt(N)]
```c++
    bool isprime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }    
        
        return true;
    }
    
    int exactly3Divisors(int N)
    {
        //Your code here
        int res=0;
        for(int i=2;i*i<=N;i++){
            if(isprime(i)) res++;
        }
        
        return res;
    }
```


### 3.Modular Multiplicative Inverse

**multiplicative inverse:*** (a*x)mod m = 1 mod m
```C++
   int modInverse(int a, int m)
    {
        //Your code here
        for(int i=1;i<m;i++){
            if(a*i%m==1) return i;
        }
        return -1;
    }
```


### 4. Trailing zeroes in a factorial

**brute force:** Calculate the factorial and count the zeroes at the end by reducing the number by one digit in every iteration.
                  O(n+d)
                  
**best approach:** In the prime factorization of a factorial, we notice that the zeroes come from 2*5 in which the number of 5 is always less. So if we calculate the number of 5 we can calculate the trailing zeroes.
Every 5th factor in a factorial contains a 5 as a factor so we have at least (n/5) 5's, similarly every 25th term has 2 5's (n/25)....continue this until (n/5^i) becomes 0 and the sum of all this gives us the number of trailing zeroes.

### 5. GCD/LCM of a number

**brute force:**
```C++
int gcd(int A, int B) 
	{ 
	    // code here
	    for(int i=min(A,B);i>1;i--){
	        if(A%i==0 && B%i==0) return i;
	    }  
	    
	    return 1;
	}
```

***best approach:** Euclid's algorithm
```C++
int gcd(int A, int B) 
	{ 
	    // code here
	    while(A!=B){
        if(A<B)B=B-A;
        else A=A-B;
      }
      return A;
	}
```

**NOTE: LCM * HCF = a*b**


### 5. 
