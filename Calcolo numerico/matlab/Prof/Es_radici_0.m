% Esercizio (x-1)^2
clear
clc
close all

c=[1 -2 1];
r=roots(c);
fun=@(x) x.^2-2*x+1;
fzero(fun,-1)