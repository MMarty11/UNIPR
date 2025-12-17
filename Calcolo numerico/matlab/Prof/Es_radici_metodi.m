%Esercizio calcolo radici con metodi implementati
clear
clc
close all

%funz=@(x) x.^3-6*x.^2+11*x-6;
funz=@(x) cos(2*x).^2-x.^2;
a=0; b=1.5;
x=linspace(a,b);
toll=10^-10; %10^-6;
nmax=200;
%x=linspace(-b,b);
plot(x,funz(x))
grid on
sol=fzero(funz,b)
title('grafico funzione')
figure
%metodo di bisezione
[xvect_b,fx_b,nit_b]=bisect(funz,a,b,toll,nmax);
nit_b
semilogy([1:nit_b],abs(xvect_b-sol))
grid on
ylabel('errore rispetto soluzione riferimento')
xlabel('numero iterazioni')
% errore sulla soluzione esatta
errore_b=abs(xvect_b-sol);
%metodo delle corde
x0=0.6; %(a+b)/2;
[xvect_c,fx_c,nit_c]=chord(a,b,x0,nmax,toll,funz);
nit_c
hold on
semilogy([1:nit_c],abs(xvect_c(2:end)-sol))
% errore sulla soluzione esatta
errore_c=abs(xvect_c-sol);
%metodo di Newton
dfun=@(x) -4*cos(2*x)*sin(2*x)-2*x;
[xvect_N,fx_N,nit_N]=Newton(x0,nmax,toll,funz,dfun);
nit_N
semilogy([1:nit_N],abs(xvect_N(2:end)-sol))
% errore sulla soluzione esatta
errore_N=abs(xvect_N-sol);
legend('bisezione','corde','tangenti')


