%Esercizio calcolo radici con Metodo di Newton e confronto criteri arresto
clear
clc
close all

eta=10^-9;
funz=@(x) exp(-x)-eta;
sol=-log(eta);
a=19; b=21;
x=linspace(a,b);
plot(x,funz(x))
grid on
title('grafico funzione')
figure
toll=10^-10;
nmax=200;
dfunz=@(x) -exp(-x);
x0=a;
[xvect,fx,nit]=Newton(x0,nmax,toll,funz,dfunz);
err=abs(sol-xvect);
plot([1:nit],err(2:end))
grid on
ylabel('errore')
xlabel('numero iterazioni')

