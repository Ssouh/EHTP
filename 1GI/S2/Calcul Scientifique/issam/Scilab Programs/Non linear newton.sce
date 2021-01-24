function x = Newton_sys(F, JF, x0, tol, maxit)
    
xold =x0;
disp([0 ])    
iter =1;
while (iter<=maxit)
    y=- feval(xold,JF)\feval(xold,F);
    xnew = xold +y';
    dif = norm(xnew - xold);
    disp([iter   xnew    dif]);
    if dif <= tol then
        x=xnew;
        disp('Newton method has converged')
        return;
    else
        xold=xnew;
    end
    iter=iter+1;
end
disp('Newton method did not converge')
x=xnew;  
    
endfunction
