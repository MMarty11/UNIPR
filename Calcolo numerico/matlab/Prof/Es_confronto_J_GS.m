% Esercizio di confronto tra i metodi di Jacobi e di Gauss-Seidel
clear
clc

A=[3 0 4; 7 4 2; -1 -1 -2];
%A=[-3 3 -6; -4 7 -8; 5 7 -9];
sol=[1 1 1]';
b=A*sol;
x_0=2*sol;
toll=10^-6;
[x_J,nit_J,r_J]=Jacobi(A,b,x_0,toll); %metodo di Jacobi
[x_GS,nit_GS,r_GS]=GS(A,b,x_0,toll); %metodo di Gauss Seidel


