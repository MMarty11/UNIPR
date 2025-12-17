% Esercizio 2

clear 
clc

n=3;
L=tril(rand(n,n));
U=triu(rand(n,n));
sol_esatta=ones(n,1);

% metodo di sostituzione in avanti
b=L*sol_esatta;
for j=1:n
    if (U(j,j)==0)
        disp('the matrix is singular')
    else
        x(j)=b(j)/L(j,j);
        b(j+1:n)=b(j+1:n)-L(j+1:n,j)*x(j);
    end
end

disp('Sostituzione in avanti:')
x
norm(x-ones(n,1),inf)

% metodo di sostituzione all'indietro
b=U*sol_esatta;
for j=n:-1:1
     if (U(j,j)==0)
        disp('the matrix is singular')
     else
        x(j)=b(j)/U(j,j);
        b(j-1:-1:1)=b(j-1:-1:1)-U(j-1:-1:1,j)*x(j);
     end
end

disp('Sostituzione all''indietro:')
x
norm(x-ones(n,1),inf)
