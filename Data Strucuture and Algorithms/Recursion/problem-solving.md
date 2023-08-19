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
```C++
if(n==0) return n;  //further optimization: if(n<=9) return n;
return n%10 +sum(n/10);
```
**4. Rope cutting problem:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**5. Generate subsets:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**6. TOH:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**6. Josephus problem:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**7. Sum of subsets:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
**8. Print all permutations:** 
```C++
if(n==0) return n;
return n+sum(n-1);
```
