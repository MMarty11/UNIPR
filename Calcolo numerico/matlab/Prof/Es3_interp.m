% Es 3 interpolazione
clear
clc
close all

%f=@(x) exp(x).*cos(4*x);
f=@(x) abs(x-1);
a=-3; b=3;
x=linspace(a,b);
y=f(x);
n=5; %numero nodi
nodi=linspace(a,b,n);
y_nodi=f(nodi)';
V=vander(nodi); %matrice di Vandermonde
coeff=V\y_nodi; %coefficienti polinomio interpolatore
yy=polyval(coeff,x);
nodi_c=[a 1 b]; %suddivisione interpolazione composita
y_c=f(nodi_c);
yyy=interp1(nodi_c,y_c,x);
plot(x,y) %grafico funzione
hold on
plot(nodi,y_nodi,'*') %grafico punti interpolazione
plot(x,yy) %grafico polinomio interpolatore
plot(x,yyy) %interpolazione composita
grid on
legend('funzione','punti interpolazione','pol. interp. semplice',...
    'pol. interp. comp.')
% calcolo errore
err=norm(yy-y) %errore interp. semplice
%cond(V) %condizionamento matrice
err_c=norm(yyy-y) %errore interp. composita

