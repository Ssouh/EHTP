import math


def f(x):
    return math.cos(x)-x
    
def fprime(x):
    return -math.sin(x)-1
    
def newton(pzero,tol,nmax,iter,erreur):
    p=pzero
    iter=0
    while iter<=nmax:
        pzero=p
        p=pzero-f(pzero)/fprime(pzero)
        iter=iter+1
        if p!=0:
            erreur=abs((p-pzero)/p)
        if erreur<tol or iter>=nmax:
            break
    print(iter)
    return(p)

        