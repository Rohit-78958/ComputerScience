### 1. abs(num)
```C++
return (num>0)?num:-num
```
### 2. pow(n,x)
**naive:** 
```c++
for(int i=0;i<x;i++)n*=n;
return n;
```

**Best approach:** Write n in binary form and x raised to n is equal to the product of x raised to power 1's positions which increases in powers of 2.

***O(logn)***

```C++
int res=1;
while(n>0){
  if(n&1) res*=x; //(n%2==0)
  x*=x
  n = n>>1;  //n/=2
}
return res;
```
