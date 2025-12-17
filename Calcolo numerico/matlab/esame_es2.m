%Esame - Esercizio 2
%si approssimi sqrt(5) con il metodo di bisezione e accuratezza 10^(-3)

clear
clc
close all

funz=@(x) x.^3-6*x.^2+11*x-6;
a=0; b=5;
x=linspace(a,b);
toll=10^-3;
nmax=100;
sol=sqrt(5);

plot(x,funz(x))
grid on
hold on
title('grafico funzione')

%metodo di bisezione
[xvect_b,fx_b,nit_b]=bisect(funz,a,b,toll,nmax,sol);
plot(xvect_b,fx_b,'o')
xvect_b
% errore sulla soluzione esatta
errore_b=abs(xvect_b-sol)
%numero di iterazioni
nit_b



function [xvect,fx,nit]=bisect(fun,a,b,toll,nmax,nroot)
    %metodo di bisezione
    %INPUT
    %fun=funzione di cui si cerca una radice
    %a,b= estremi intervallo di esistenza della radice
    %toll=tolleranza per l'ampiezza del k-simo sottointervallo
    %nmax=numero massimo di iterazioni
    %root=radice da approssimare
    %OUTPUT
    %xvect=successione di valori approssimanti la radice
    %fx=successione dei residui
    %nit=numero di iterazioni
    nit=0;
    xvect=[];
    fx=[];
    err=abs(b-a);
    while nit<nmax && err>toll
        nit=nit+1;
        x=(a+b)/2; %punto medio
        fx=[fx;abs(fun(x))];
        xvect=[xvect;x];
        if fun(x)*fun(a)>nroot
            a=x;
        elseif fun(x)*fun(a)==nroot
            disp('ho trovato la radice')
            disp(x)
            return
        else
            b=x;
        end
        err=abs(b-a);
    end
end