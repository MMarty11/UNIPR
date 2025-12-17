function [D,C]=fun_Es5(n)
% function Esercizio 5
%INPUT
% n=dimensione della matrice
%OUTPUT
% D=determinante della matrice
% C=condizionamento della matrice
for k=1:n
    A(k,n-k+1)=2;
    if k~=n
        A(k,n-k)=-1;
    end
    if k~=1
        A(k,n-k+2)=-1;
    end
end
% disp(A)
D=det(A);
C=cond(A);