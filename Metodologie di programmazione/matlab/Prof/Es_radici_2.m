% Esercizio radici equazioni non lineari
clear
clc
close all

C=[1 -7 15 -13 4];%coefficienti secondo polinomio
x=linspace(-1,5,200);
y=polyval(C,x);
plot(x,y) %grafico polinomio
grid on

%calcolo radici attraverso la funzione fzero
f=@(x) x.^4-7*x.^3+15*x.^2-13*x+4;
r(1)=fzero(f,5);
q=@(x) (x.^4-7*x.^3+15*x.^2-13*x+4)./(x-r(1));
r(2)=fzero(q,5);
g=@(x) (x.^4-7*x.^3+15*x.^2-13*x+4)./((x-r(1)).*(x-r(2)));
r(3)=fzero(g,5)

%calcolo radici attraverso la funzione roots
radici=roots(C)
%verifica radici
% polyval(C,radici(1))
% polyval(C,radici(2))
% polyval(C,radici(3))

