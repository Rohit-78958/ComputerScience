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

```Let (x,y) be a divisor of n such that x*y=n

if x<=y: x*x<=n

x<=sqrt(n)

hence proved, one divisor is always less than or equal to n
```





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

***best approach:** Euclid's algorithm  :: gcd(a.b) = gcd(a-b,b) ; if a>b
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


### 5. Prime Factorization

**Brute Force:** Print all numbers that are prime and divide n

O(n^2logn)
```C++
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void primFactors(int n){
    int temp;
	for(int i=2;i<n;i++){			//further optimization: n=>n/2(since we are finding divisors only)
		if(isprime(i)){
		    temp=i;
			while(n%temp==0){
				cout<<i<<" ";
				temp*=i;
			}
		}
	}
}
```

**Best approach:** prime factors also lies in [2, sqrt(N)] and a number can be written as multiplication of powers of prime numbers.

O(sqrt(N))
```C++
void primeFactors(int N){
	if(n<=1) return;
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			print(i);
			n=n/i;
		}
	}
	if(n>1) print(i);  //for the edge case when the biggest prime factor has power 1 only 
}
```
***NOTE: Further optimization by taking 2 and 3 cases separately***

### 6. All Divisors

**Brute Force:** Check for all divisors
```C++
void divisors(int n){
	for(int i=1;i<=n;i++){               //further optimization: n=>n/2
		if(n%i==0) print(i);
	}
```

**Best approach:** Divisors always appear in pair and one of the pair is always smaller than sqrt(n), its just that they will not be in sorted order
```C++
for(int i=1;i*i<=n;i++){
	court<<i<<" ";
	if(i!=n/i) court<<n/i<<" ";   //perfect square condition
}
```

**in sorted order😃**
```C++
int i;
for(i=1;i*i<=n;i++){
	if(n%i==0)court<<i<<" ";
}
for(;i>=1;i--){
	if(n%i==0)court<<n/i<<" ";
}
```

### 7.Sieve of Eratosthenes

Print the number of prime numbers less than the given number N
**Brute force:**
```C++
for(int i=2;i<=N;i++){
	if(isprime(i)) print(i);
}
```

**Best approach:** Mark the multiple of 2,3,5... as false till sqrt(n)

***O(nloglogn)***

```C++
vector<bool> isprime(n+1,true);
for(int i=2;i*i<=n;i++){
	if(isprime[i]){
		for(int j=2*i;j<=n;j+=i) isprime[i] = false;  //further optimization: j=i*i (to avoid unnecessary comparisons/calculations)
	}
}
for(int i=2;i<=n;i++){
	if(isprime[i]) print(i);
 }
```

**code reduction under the same complexity**
```C++
vector<bool> isprime(n+1,true);
for(int i=2;i<=n;i++){
	if(isprime[i]){
		print(i);
		for(int j=2*i;j<=n;j+=i) isprime[i] = false;  //further optimization: j=i*i (to avoid unnecessary comparisons/calculations)
	}
}
```
