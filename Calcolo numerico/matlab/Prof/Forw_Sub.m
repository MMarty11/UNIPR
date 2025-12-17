% Algoritmo di sostituzione in avanti
clear
clc

for i=1:10
    n=i*10;
    L=tril(rand(n));
    sol_esatta=ones(n,1);
    b=L*sol_esatta;
    %forward substitution
    for j=1:n
        if (L(j,j)==0)
            disp('the matrix is singular')
        else
            x(j)=b(j)/L(j,j);
            b(j+1:n)=b(j+1:n)-L(j+1:n,j)*x(j);
        end
    end
    err(i,1)=norm(x-ones(n,1),inf);
    condiz(i,1)=cond(L);
end
[[10:10:100]' err condiz]


