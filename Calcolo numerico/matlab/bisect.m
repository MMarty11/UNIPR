function [xvect,fx,nit]=bisect(fun,a,b,toll,nmax)
%metodo di bisezione
%INPUT
%fun=funzione di cui si cerca una radice
%a,b= estremi intervallo di esistenza della radice
%toll=tolleranza per l'ampiezza del k-simo sottointervallo
%nmax=numero massimo di iterazioni
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
    if fun(x)*fun(a)>0
        a=x;
    elseif fun(x)*fun(a)==0
        disp('ho trovato la radice')
        disp(x)
        return
    else
        b=x;
    end
    err=abs(b-a);
end


