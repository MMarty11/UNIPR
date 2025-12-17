function [A,deter] = prova(n,cost)
%dato il numero di righe, restituisce la matrice quadrata A con
%elementi uguali a cost e dimensione n e il suo determinante deter
A = cost*ones(n);
deter = det(A); %calcolo del determinante
end

