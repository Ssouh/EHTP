import math


def f(x):
    return x**3+4*x**2-10
    
def bissect(a,b,tol,Nmax,p,iter,erreur):
    iter=0
    while iter<=Nmax:
        pzero=p
        p=(a+b)/2
        iter=iter+1
        if p!=0:
            erreur=abs(p-pzero)/abs(pzero)
        Test=f(a)*f(b)
        if Test<0:
            a=p
        elif Test>0:
            b=p
        else:
            erreur=0
        if erreur<tol or iter>=Nmax:
            break
    return iter
        