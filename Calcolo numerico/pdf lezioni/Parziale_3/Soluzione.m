clear
clc
close all
format long

f=@(x) sin(2*x)+exp(x)+1;
a=-2; b=0.1;
nodi=[-2 -1.25 -0.7 0.1];
y_nodi=f(nodi);
x=linspace(a,b,1000);
%interpolazione lagrangiana semplice
coeff_Lagrange=polyfit(nodi,y_nodi,length(nodi)-1);
y_lagr=polyval(coeff_Lagrange,x);
err_lagr=norm(y_lagr-f(x),inf)
%approssimazione polinomio 2° grado minimi quadrati
coeff_quadr=polyfit(nodi,y_nodi,2);
y_quadr=polyval(coeff_quadr,x);
err_quadr=norm(y_quadr-f(x),inf)
disp('meglio interpolazione lagrangiana')
%grafico
plot(x,f(x))
grid on
hold on
plot(nodi,y_nodi,'*')
plot(x,y_lagr)
plot(x,y_quadr)
legend('funzione','punti interpolazione','polinomio Lagrange','parabola minimi quadrati')
%integrale esatto
primitiva=@(x) -cos(2*x)/2+exp(x)+x;
I=primitiva(b)-primitiva(a)
%I_quad=quad(f,a,b,10^-14);
%integrale approssimato
integranda_lagr=@(x) polyval(coeff_Lagrange,x);
I_lagr=quad(integranda_lagr,a,b,10^-14);
err_int_lagr=abs(I-I_lagr)
integranda_quadr=@(x) polyval(coeff_quadr,x);
I_quadr=quad(integranda_quadr,a,b,10^-14);
err_int_quadr=abs(I-I_quadr)
disp('errore integrale minimi quadrati è più piccolo')
