function f=exer(x,y)
    f=100*((x-y)^2)+(x-1)^2;
endfunction
deff('z=f(x,y)','z=100*((x-y)^2)+(x-1)^2')
x=-1:0.1:1;y=x;
clf();fplot3d(x,y,f,alpha=5,theta=31)
