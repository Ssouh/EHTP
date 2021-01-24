function x=GaussSeidel(A,b,es,maxit)    
    if nargin < 4 then maxit=50; end
    if nargin < 3 then es=0.00001; end
    
    [m,n] = size(A);
    if m~=n then error('Matrix A doit etre caree'); end
    C=A;
    
    for i=1:n
        C(i,i)=0;
        x(i)=0;
    end
    
    x=x';
    for i=1:n
        C(i,1:n) = C(i,1:n) / A(i,i);
    end
    
    for i=1:n
        d(i)=b(i) / A(i,i);
    end
       
iter=0;
disp('          i         x1      x2        x3          x4') ;
while(1)
    xold=x;
    for i=1:n
        x(i) =  d(i) - C(i,:) * x';
        if x(i) ~=i then            
            ea(i) = (abs(x(i) - xold(i)) / x(i)) * 100;
        end
    end
    iter=iter+1;
    disp([iter x]);
    if max(ea) <= es | iter >=maxit then break; end
end
if iter >=maxit
disp('Gauss Seidel methode a convergé');
disp('Resulsts arès le maximum d'itérations');
else
    disp('Gauss Seidel method a convergé');
end
x;
            
        
        

    
endfunction
