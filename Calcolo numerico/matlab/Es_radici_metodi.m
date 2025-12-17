%Esercizio calcolo radici con metodi implementati
clear
clc
close all

%funz=@(x) x.^3-6*x.^2+11*x-6;
%a=0; b=1.5;
funz=@(x) cos(2*x).^2-x.^2;
a=0; b=1.5;

x=linspace(a,b);
toll=10^-10;
nmax=100;
plot(x,funz(x))
grid on

%metodo di bisezione
[xvect_b,fx_b,nit_b]=bisect(funz,a,b,toll,nmax);
nit_b
% errore sulla soluzione esatta
errore_b=abs(xvect_b-1)

%metodo delle corde
x0=(a+b)/2;
[xvect_c,fx_c,nit_c]=chord(a,b,x0,nmax,toll,funz);
nit_c
% errore sulla soluzione esatta
errore_c=abs(xvect_c-1)

%metodo di Newton
x0=(a+b)/2;
dfunz=@(x) 3*x.^2-12*x+11;
[xvect_n,fx_n,nit_n]=newton(x0,nmax,toll,funz, dfunz);
nit_n
% errore sulla soluzione esatta
errore_n=abs(xvect_n-1)
