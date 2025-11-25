 def fact(n):
        if n==1:
                return 1
        else:
                return n*fact(n-1)
 def p(n,r):
        return fact(n)/fact(n-r)
 def c(n,r):
        return p(n,r)/fact(r)
 print("Enter the details to find permutation nPr :")
 n=int(input("n: "))
 r=int(input("r: "))
 print(f"{n}p{r}={p(n,r)}")
 print("Enter the details to find Combination nCr :")
 n=int(input("n: "))
 r=int(input("r: "))
 print(f"{n}C{r}={c(n,r)}")
