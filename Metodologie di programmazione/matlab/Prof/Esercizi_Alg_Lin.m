% Esercizi algebra lineare
clear
clc

A=diag(2*ones(3,1))+diag([3],-2)+diag([1],2)
%[L,U]=lu(A)

%risoluzione con metodo di Jacobi
n=3;
A=rand(n);
b=A*ones(n,1);
toll=10^-6;
x_0=2*ones(n,1);
% [x,nit,r]=Jacobi(A,b,x_0,toll);
% norm(ones(n,1)-x(:,end))
[x,nit,r]=GS(A,b,x_0,toll);
norm(ones(n,1)-x(:,end))

