% Esercizio 1 interpolazione
clear
clc
close all

fun=@(x) exp(x).*sin(2*x);
a=0; b=2;
x=linspace(a,b,1000); %ascisse grafico
n=20; %grado polinomio interpolatore
nodi=linspace(a,b,n+1); %nodi di interpolazione
val=fun(nodi);
coeff=polyfit(nodi,val,n); %coefficienti polinomio interpolatore di Lagrange
pol=polyval(coeff,x);
plot(nodi,val,'*')
hold on
plot(x,fun(x),'r')
plot(x,pol,'k--')
grid on
legend('punti interpolazione','funzione','polinomio interpolatore di Lagrange')



