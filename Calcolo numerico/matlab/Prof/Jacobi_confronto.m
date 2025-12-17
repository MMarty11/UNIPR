function [x,nit,r]=Jacobi(A,b,x_0,toll)
%INPUT
%A=matrice sistema
%b=termine noto sistema
%x_0=vettore di innesco
%toll=tolleranza richiesta
%OUTPUT
%x=matrice contenente la successione di vettori approssimanti
%nit=numero di iterazioni
%r=vettore dei residui

%metodo di Jacobi
x=x_0;
D=diag(diag(A));
C=A-D;
B_Jacobi=-inv(D)*C;
nit=0;
inc(1,1)=1;
r(1,1)=1;
rho=max(abs(eig(B_Jacobi)));
% if rho<1
    %while inc(end,1)>toll %criterio dell'incremento
    while r(end,1)>toll %criterio del residuo
        nit=nit+1;
        x_1=B_Jacobi*x_0+inv(D)*b;
        x=[x x_1];
        inc(nit,1)=norm(x_1-x_0); %calcolo incremento
        x_0=x_1;
        r(nit,1)=norm(b-A*x_0); %calcolo del residuo
    end
% else
%     disp('metodo Jacobi non convergente')
%     disp(rho)
% end