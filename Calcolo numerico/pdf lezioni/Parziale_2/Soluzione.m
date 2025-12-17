% II prova intermedia calcolo numerico 06/05/2021

%close all
clear
clc
close all

n=10;
for k=1:10;
    alpha=10^k;
    A=eye(n)+diag(alpha*ones(n-1,1),-1);
    sol=ones(n,1);
    b=A*sol;
    x=Funz_Soluzione(alpha,n,b);
    %x=A\b;
    condiz(k)=cond(A,inf);
    err(k)=norm(x-sol,inf);
end
subplot(1,2,1)
loglog(10.^[1:10],condiz)
grid on
ylabel('condizionamento')
xlabel('\alpha')
subplot(1,2,2)
semilogx(10.^[1:10],err)
ylabel('errore sulla soluzione')
xlabel('\alpha')
grid on

figure
alpha=10;
for n=10:10:100;
    A=eye(n)+diag(alpha*ones(n-1,1),-1);
    sol=ones(n,1);
    b=A*sol;
    x=Funz_Soluzione(alpha,n,b);
    %x=A\b;
    condiz(n/10)=cond(A,inf);
    err(n/10)=norm(x-sol,inf);
end
subplot(1,2,1)
semilogy([10:10:100],condiz)
grid on
ylabel('condizionamento')
xlabel('dimensione della matrice')
subplot(1,2,2)
plot([10:10:100],err)
ylabel('errore sulla soluzione')
xlabel('dimensione della matrice')
grid on

%in entrambe le figure si nota che nonostante il condizionamento sia molto
%elevato, le soluzioni vengono approssimate in doppia precisione
