close all
clear
clc
%curve nella stessa finestra grafica
for m=1:6
    x1=linspace(-m,0);
    x2=linspace(0,m);
    f1=@(x) (m-x.^2/m).^m;
    f2=@(x) (x.^2/m+m).^m;
    plot(x1,f1(x1),x2,f2(x2)) %semilogy
    hold on
end
legend('m=1','m=1','m=2','m=2','m=3','m=3','m=4','m=4','m=5','m=5','m=6','m=6')
grid
xlabel('x')
ylabel('f(x)')
figure
% curve in sottofinestre
for m=1:6
    subplot(2,3,m)
    x1=linspace(-m,0);
    x2=linspace(0,m);
    f1=@(x) (m-x.^2/m).^m;
    f2=@(x) (x.^2/m+m).^m;
    plot(x1,f1(x1),x2,f2(x2))
    title(m)
    grid
    xlabel('x')
    ylabel('f(x)')
end
