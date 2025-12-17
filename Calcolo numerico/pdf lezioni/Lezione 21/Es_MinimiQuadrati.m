%Minimi Quadrati
clear
clc
close all

sforzi=[0 0.06 0.14 0.25 0.31 0.47 0.6 0.7];
deformaz=[0 0.08 0.14 0.20 0.23 0.25 0.28 0.29];
plot(sforzi,deformaz,'*')
grid on
xlabel('sforzi')
ylabel('deformazioni')
%coefficienti retta regressione
den=length(sforzi)*sum(sforzi.^2)-(sum(sforzi))^2;
q=(sum(deformaz)*sum(sforzi.^2)-sum(sforzi)*sum(sforzi.*deformaz))/den
m=(length(sforzi)*sum(sforzi.*deformaz)-sum(sforzi)*sum(deformaz))/den
x=linspace(min(sforzi),max(sforzi),200);
y=m*x+q; %retta regressione
R=sum((deformaz-(m*sforzi+q)).^2); %somma quadrati residui
R_tilde=sum((deformaz-(0.37*sforzi+0.065)).^2); %test variazione coefficienti
hold on
plot(x,y)
%Coeff=polyfit(sforzi,deformaz,1) %retta regressione Matlab
Coeff_2=polyfit(sforzi,deformaz,2); %polinomio grado 2 minimi quadrati
p2=polyval(Coeff_2,x);
plot(x,p2)
Coeff_3=polyfit(sforzi,deformaz,3); %polinomio grado 3 minimi quadrati
p3=polyval(Coeff_3,x);
plot(x,p3)
Coeff_interp=polyfit(sforzi,deformaz,length(sforzi)-1); %polinomio interpolatore
p_interp=polyval(Coeff_interp,x);
plot(x,p_interp)
%minimi quadrati con funzione non polinomiale
fun=@(beta,x) log(beta*x+1);
beta=nlinfit(sforzi,deformaz,fun,1);
plot(x,fun(beta,x))
%retta di regressione passante per l'origine degli assi
fun=@(beta,x) beta*x;
beta=nlinfit(sforzi,deformaz,fun,1)
plot(x,fun(beta,x))
legend('dati','retta di regressione','parabola di regressione',...
    'cubica di regressione','polinomio interpolatore','log(\beta+1)',...
    'retta per origine assi')
