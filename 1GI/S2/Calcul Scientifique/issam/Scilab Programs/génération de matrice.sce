function x=Jacobi(A,b,x0,tol,maxiter)
    [n m]=size(A);
    xold=x0;
    C=-A;
    Z=zeros(1,n);
    Y=zeros(1,n);
    for i=1:n
        C(i,i)=0;
    end
    
    for i=1:n
        C(i,:)=C(i,:)/A(i,i);
    end
    
    for i=1:n
        d(i,1)=b(i)/A(i,i);
    end
    
    i=1;
    while(i<=maxiter)
        xnew=C*xold+d;
        if norm(xnew-xold)<=tol then
            x=xnew;
            disp('Jacobi est convergente');
            disp('Matrice A ');
            disp(A);
            disp('Solution Exacte');
            disp(xnew);
            return;
        else
            xold=xnew;
        end
        
        
        disp(xnew,i);
        //erreur
        err=norm(b-A*xnew);
        disp('Erreur');
        disp(err);
        i=i+1;
        
        Z(1,i)=err;
        Y(1,i)=i;
        plot(Z,Y);
    end
    disp('Jacobi non convergente');
    x=xnew
    disp(x,i);
    
    
    //S=return(S);
endfunction
