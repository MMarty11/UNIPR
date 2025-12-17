%Es 2 interpolazione
clear
clc
close all

f=@(x) 1./(1+x.^2); %funzione di Runge
a=-5; b=5;
x=linspace(a,b,1000);
n=30; %numero di nodi di interpolazione
nodi=linspace(a,b,n);
y_nodi=f(nodi);
p=polyfit(nodi,y_nodi,n-1); %coefficienti polinomio Lagrange nodi equispaziati
y=polyval(p,x);
nodi_cheb=(a+b)/2-(b-a)/2*cos((2*[0:n-1]+1)/(2*(n-1)+2)*pi);%nodi di Chebyshev
y_cheb=f(nodi_cheb);
p_cheb=polyfit(nodi_cheb,y_cheb,n-1); %coefficienti polinomio Lagrange nodi Cheb
yy=polyval(p_cheb,x);
plot(x,f(x)) %grafico funzione Runge
hold on
plot(nodi,y_nodi,'*') %nodi equispaziati
plot(x,y) %grafico polinomio interpolatore con nodi equispaziati
plot(nodi_cheb,y_cheb,'o') %nodi Cheb
plot(x,yy) %grafico polinomio interpolatore con nodi Cheb
grid on
legend('Funzione di Runge','nodi interpolazione','pol. Lagrange-equispaziati',...
    'nodi Chebyshev','pol. Lagrange-Cheb')