% Es 7 interpolazione
clear
clc
close all

a=-1; b=1;
n=15; %numero nodi
x=linspace(a,b,1000);
nodi=linspace(a,b,n); %nodi equispaziati
nodi_cheb=(a+b)/2-(b-a)/2*cos((2*[0:n-1]+1)/(2*(n-1)+2)*pi);%nodi di Chebyshev
for i=1:length(x)
    w(i)=prod(x(i)-nodi);
    w_cheb(i)=prod(x(i)-nodi_cheb);
end
plot(x,abs(w))
grid on
hold on
plot(nodi,zeros(size(nodi)),'*')
plot(x,abs(w_cheb))
plot(nodi_cheb,zeros(size(nodi_cheb)),'o')
legend('Omega','nodi equispaziati','Omega Chebyshev','nodi Chebyshev')