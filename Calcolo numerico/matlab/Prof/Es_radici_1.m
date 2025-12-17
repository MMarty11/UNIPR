% Esercizio radici equazioni non lineari
clear
clc
close all

C=[1 -6 11 -6];%coefficienti primo polinomio
x=linspace(0,4,200);
y=polyval(C,x);
plot(x,y) %grafico polinomio
grid on

%calcolo radici attraverso la funzione roots
radici=roots(C);
%verifica radici
% polyval(C,radici(1))
% polyval(C,radici(2))
% polyval(C,radici(3))

%calcolo radici attraverso la funzione fzero
f=@(x) x.^3-6*x.^2+11*x-6;
r(1)=fzero(f,1.5);
q=@(x) (x.^3-6*x.^2+11*x-6)./(x-r(1));
r(2)=fzero(q,1.5);
g=@(x) (x.^3-6*x.^2+11*x-6)./((x-r(1)).*(x-r(2)));
r(3)=fzero(g,1.5)
