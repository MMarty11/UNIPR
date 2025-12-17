%Esame - Esercizio 1
%data la matrice R calcolarne l'inversa con il metodo di sostituzione
%all'indietro

clear
clc

n=4;
diag_0=[1/5 0 11/114];
diag_1=[2/5 1/3];
S=eye(n)+diag(diag_0,+1)+diag(diag_1,+2);
%sol_esatta=ones(n,1);
I=eye(n);
Inv=zeros(n);

% metodo di sostituzione all'indietro
%b=S*sol_esatta;
for i=n:-1:1
    b=I(:,i);
    for j=n:-1:1 
        if (S(j,j)==0)
            disp('La matrice è singolare')
        else
            x(j)=b(j)/S(j,j);
            b(j-1:-1:1)=b(j-1:-1:1)-S(j-1:-1:1,j)*x(j);
        end
    end
    Inv(:,i)=x;
end

disp('Matrice inversa:')
Inv
norm(S*Inv-eye(n),inf)