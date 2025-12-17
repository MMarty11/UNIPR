% I prova intermedia calcolo numerico 08/04/2021

%close all
clear
clc

x=linspace(-pi,pi,200);
plot(x,sin(x))
hold on
for N=1:3
    approx=Funz_Soluzione(x,N);
    plot(x,approx)
    Err(N)=norm(sin(x)-approx,inf);
end
legend('sin','p_1','p_2','p_3')
grid on
xlabel('angoli')
ylabel('seno e approssimanti')
Err'


