//**************************************************
// Algorithme de Dijstra
//**************************************************

function W=Matrice_Poids(G)
n=G.node_number//nombre de sommets
W=%inf+zeros(n,n)//initialisation matrice des poids
m=length(G.tail)//nombre d'arcs/arêtes
for i=1:m
    x=G.tail(i),y=G.head(i)//sommets de l'arc/arête
    W(x,y)=G.edge_weight(i)// on remplit W
    //si le graphe est non orienté on symétrise
    if G.directed==0 then W(y,x)=G.edge_weight(i)
    end
end
endfunction


function [C,x] = Sommet_Optimal(Dist,C)
//Dist= matrice de distances (1 ligne )
//x= numéro de sommet (présent dans C) tel que Dist(x) 
//   soit minimal (par rapport aux Dist(y) pour y dans C)
//C= matrice de numéros de sommets (1 ligne)
//   en sortie  C ne contient plus x
endfunction


function [Dist,Pred]=Dijkstra(G,s)
//G= graphe scilab à n sommets
// Dist, Pred = matrices de taille 1 ligne et n n colonnes
endfunction

 //****************************************************
// Algorithme de Bellman-Ford-Kalaba
//****************************************************

function [Dist,Pred]=Bellman(G,s)
//G=graphe scilab à n sommets
//s=sommet du graphe G
//Dist,Pred= matrices de taille 1 * n
//à compléter
endfunction
 //***********************************************
// Chemins de longueur maximale
//***********************************************


function [Dist,Pred]=Bellman_Max(G,s)
//G=graphe scilab à n sommets
//s=sommet du graphe G
//Dist,Pred= matrices de taille 1 * n
//à compléter
endfunction

//****************************************************
// Algorithme de Ford
//****************************************************

function selectionSommet(L,n)
    s=-1;
    for i=1:n
        if L(i)~=-1
            s=i;
            break;
        end
    end
    
endfunction

function ch=Ford(P,a,b) 
     [n,m]=size(P);
     d(1)=0;
     for i=2:n  // Initialisation 
        d(i)=0;
     end
     for i=1:n
         trace(i)=0;
     end
     L(1)=1;
     for i=2:n 
         L(i)=-1;
     end
     s=selectionSommet(L,n)
     while s<>-1
        for j=1:n
            if P(s,j)>0
                if d(j)-d(s)>=P(s,j)
                      d(j)=d(s)+P(s,j);
                      trace(j)=s;
                      L(j)=j;
                end
            end 
         end
         L(s)=-1;
         s=selectionSommet(L,n);
     end
    i=1;
    ch(i)=b;
    while ch(i)~=a
        ch(i+1)=trace(ch(i));
        i=i+1;
    end
    [e,f]=size(ch)
    while e>0
        disp(ch(e));
        e=e-1;
    end  
endfunction


