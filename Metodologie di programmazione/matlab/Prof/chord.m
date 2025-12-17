function [xvect,fx,nit]=chord(a,b,x0,nmax,toll,fun)
%metodo delle corde
%INPUT
%a,b=estremi intervallo di esistenza della radice
%x0=ascissa di innesco del metodo
%nmax=numero massimo di iterazioni
%toll=tolleranza criterio d'arresto
%fun=funzione di cui si cerca una radice
%OUTPUT
%xvect=successione di valori approssimanti
%fx=successione dei residui
%nit=numero di iterazioni
q=(fun(b)-fun(a))/(b-a);
nit=0;
xvect=x0;
fx=abs(fun(x0));
err=abs(b-a);
%while nit<nmax && err>toll %criterio dell'incremento
while nit<nmax && fx(end)>toll %criterio del residuo
    nit=nit+1;
    x=x0-fun(x0)/q;
    xvect=[xvect;x];
    fx=[fx;abs(fun(x))];
    err=abs(x-x0);
    x0=x;    
end
