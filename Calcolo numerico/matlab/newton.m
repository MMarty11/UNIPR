function [xvect,fx,nit]=newton(x0,nmax,toll,fun,dfun)
%metodo di Newton
%INPUT
%x0=ascissa di innesco del metodo
%nmax=numero massimo di iterazioni
%toll=tolleranza criterio d'arresto
%fun=funzione di cui si cerca una radice
%dfun=derivata della funzione
%OUTPUT
%xvect=successione di valori approssimanti
%fx=successione dei residui
%nit=numero di iterazioni
q=dfun(x0);
nit=0;
xvect=x0;
fx=abs(fun(x0));
err=1;
while nit<nmax && err>toll %criterio dell'incremento
%while nit<nmax && fx(end)>toll %criterio del residuo
    nit=nit+1;
    if(q==0)
        disp('arresto: derivata = 0')
        return
    else
        x=x0-(fun(x0)/q);
        xvect=[xvect;x];
        fx=[fx;fun(x)];
        err=abs(x-x0);
        x0=x;
        q=dfun(x0);
    end
end