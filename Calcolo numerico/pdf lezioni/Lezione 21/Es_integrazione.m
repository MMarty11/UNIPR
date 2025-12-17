%Esercizio stima numero intervalli integrazione
clear
clc
close all

I_esatto=2/3;
m=10000
%m=ceil(sqrt(4/(3*10^-8))); %stima numero sottointervalli
nodi=linspace(-1,1,m+1);
y_nodi=nodi.^2;
I=trapz(nodi,y_nodi)
abs(I_esatto-I)