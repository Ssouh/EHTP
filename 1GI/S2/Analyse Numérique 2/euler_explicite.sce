function y=Euler_explicite(n)
    y0=1;
    dx=3*%pi/2/n; //(condition CFL))  
    for i=1:n+1
        x(i)=(i-1)*dx;
        y(i)=(1+dx*sin((i-1)*dx))^i;
    end
    x=[0;x];
    y=[1;y];
    plot(x,y)
    t=0:0.1:5;
    z=exp(1-cos(t));
    plot(t,z,'r')
endfunction
