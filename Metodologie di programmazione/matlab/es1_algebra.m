% Esercizio 1

clear 
clc

toll=10^-16;
n=10;
diag_0=rand(n,1);
diag_1=rand(n-1,1);
A=diag(diag_0)+diag(diag_1,1)+diag(diag_1,-1);

% calcolo dei detemrinanti
d(1)=1;
d(2)=diag_0(1);
for k=2:n
    if(abs(d(k))<=toll)
        disp('matrice non fattorizzabile')
        return
    else
        d(k+1)=diag_0(k)*d(k)-diag_1(k-1)^2*d(k-1);
    end
end

% calcolo della fattorizzazione LU
if(abs(d(n+1))<=toll)
    disp('matrice singolare')
    %return
else
    disp('il  determinante della matrice è')
    d(n+1)
    
    u(1)=d(2)/d(1);
    for k=1:n-1
        u(k+1)=d(k+2)/d(k+1);
        l(k)=diag_1(k)*d(k)/d(k+1);
    end
    L=eye(n)+diag(l,-1);
    U=diag(u)+diag(diag_1,1);
end

