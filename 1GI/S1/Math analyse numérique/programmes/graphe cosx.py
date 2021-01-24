from pylab import *
from numpy import *
import math

def f(x):
    return cos(x)
    
def g(x):
    return x
m=linspace(0,1.5,50)
l=f(m)
l2=g(m)
plot(m,l,m,l2)
show()