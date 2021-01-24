function [Tab]=tableau_initial(A,b,c)
    [m,n]=size(A);
    I=eye(n);
    Tab=[A,I,b;c',zeros(1,m+1)];
endfunction
function [varS,varE,Pivot]=VarES_Pivot(Tab)
    [m,n]=size(A);
    [maxi,varE]=max(Tab(m,1:n));
    tmp=Tab(1:m,varE);
    for (i=1:m)
        if (tmp(i)==0)tmp(i)=10^5;end
    end
    [maxi,varS]=min(Tab(n+m,1:m)./tmp);
    Pivot=Tab(varS,varE);
endfunction

function  [Tab_New]=tableau_new(Pivot,varE,varS,tab)
    Tab_New=tab;
    for (i=1:m+1)
        if (==varS)
            Tab_New(i,:)=Tab_New(i,:)-(Tab_New(i,varS)/Pivot)*Tab_New(varS,:);
        end      
    end
    Tab_New(varS,:)=Tab_New(varS,:)/Pivot;
endfunction
