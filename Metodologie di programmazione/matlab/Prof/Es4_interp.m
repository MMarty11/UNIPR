%Es 4 interpolazione
clear
clc
close all

a=-1; b=1;
x=linspace(a,b);
n=22;
nodi=linspace(a,b,n);
y_nodi=sin(nodi);
y_tilde=y_nodi.*(1+(-1).^[0:n-1]*10^-4);
p=polyfit(nodi,y_nodi,n-1); %coeff. polinomio interpolatore
p_tilde=polyfit(nodi,y_tilde,n-1); %coeff. polinomio interpolatore perturbato
y=polyval(p,x);
yy=polyval(p_tilde,x);

plot(x,sin(x)) %grafico funzione
hold on
plot(x,y) %grafico polinomio interpolatore
plot(x,yy) % grafico polinomio interpolatore perturbato
grid on 
legend('sin(x)','pol. interp.','pol. interp. perturbato')

%calcolo errore
err=norm(sin(x)-y,inf) %errore pol. interpolatore
err_tilde=norm(sin(x)-yy,inf) %errore pol. interp. perturbato

