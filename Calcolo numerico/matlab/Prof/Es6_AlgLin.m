% Esercizio 6
clear
clc
A=hilb(1000); % matrice di Hilbert
B=rand(1000); % matrice di numeri casuali
A_inv=inv(A);
A_inv_bis=invhilb(1000);
err=norm(A*A_inv-eye(1000));
err_bis=norm(A*A_inv_bis-eye(1000));
sol=ones(1000,1);
b=A*sol;
c=B*sol;
x=A\b;
y=B\c;
err_Hilb=norm(x-sol)/norm(sol);
err_rand=norm(y-sol)/norm(sol);
disp('matrice Hilbert')
[err_Hilb cond(A)]
disp('matrice di numeri casuali')
[err_rand cond(B)]

% grafico
for k=2:50
    condiz(k)=cond(hilb(k));
end
semilogy([2:50],condiz(2:50))
title('condizionamento matrice Hilbert')
xlabel('dimensione della matrice')
grid on


