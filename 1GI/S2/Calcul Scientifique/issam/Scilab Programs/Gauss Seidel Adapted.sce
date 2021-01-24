function x=SOR(A,b,x0,w,tol,maxit)    
    
    [n,m]=size(A); x=x0; C=-A;
    for i=1:n
        C(i,i)=0;
    end
    
    for i=1:n
    C(i,1:n) = C(i,1:n)/A(i,i);
    end

    for i=1:n
        r(i,1) = b(i)/A(i,i);
    end
    
    i = 1;
    disp('      i       x1      x2      x3');
    while(i <= maxit)
        xold=x;
        for j=1:n
            x(j) = (1-w)*xold(j) + w*( C(j,:)*x + r(j) );
        end
        
        if norm(xold-x)<=tol then
            disp('SOR Method converged'); return;
        end
        
        disp([i     x']);
        i=i+1;
        
    end
    disp('SOR method did not converge');
   

    
endfunction
