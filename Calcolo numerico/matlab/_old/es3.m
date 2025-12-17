%close all
clear
clc
t=linspace(0,2*pi,361);
x=@(t) 3+6*cos(t);
y=@(t) 8+6*sin(t);
plot(x(t),y(t))
axis equal
grid on