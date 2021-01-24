function y=Euler_implicite(n)
    y0=1;
    dx=5/n;
    x=5/n:5/n:5;
    for i=1:n
        y(i)=(1/(1-dx*sin(i*dx)))*y0;
        y0=y(i);
    end
    x=[0;x'];
    y=[1;y];
    plot(x,y)
    t=0:0.1:5;
    z=exp(1-cos(t));
    plot(t,z,'r')
endfunction
