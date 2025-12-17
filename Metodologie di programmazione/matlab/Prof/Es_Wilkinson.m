% Esercizio polinomio di Wilkinson
clear
clc
close all

n=10;
radici=-[n:-1:1];
coeff=poly(radici); %polinomio di Wilkinson
r=roots(coeff);
err=norm(radici'-r,inf);
%polinomio perturbato
coeff_tilde=coeff;
coeff_tilde(2)=coeff_tilde(2)+10^-7;
%[coeff' coeff_tilde']
r_tilde=roots(coeff_tilde);
err_tilde=norm(radici'-r_tilde,inf);
[err err_tilde]

