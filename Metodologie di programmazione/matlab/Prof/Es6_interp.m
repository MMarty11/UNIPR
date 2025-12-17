% Es 6 interpolazione
clear
clc
close all

% xi=[0.49 0.64 0.81];
% yi=[0.7 0.8 0.9];
xi=[0.36 0.49 0.64 0.81];
yi=[0.6 0.7 0.8 0.9];
xbar=0.6;
ybar=polyFlag(xi,yi,xbar)
y_esatto=sqrt(xbar)
err=abs(ybar-y_esatto)