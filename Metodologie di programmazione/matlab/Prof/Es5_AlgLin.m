% Esercizio 5
close all
clear
clc
tic
for nn=1:50
    [DD(nn),CC(nn)]=fun_Es5(nn);
end
toc
subplot(1,2,1)
plot([1:50],DD,'*')
axis square
title('Determinante')
xlabel('dimensione della matrice')
grid on
subplot(1,2,2)
plot([1:50],CC,'*')
axis square
title('Condizionamento')
xlabel('dimensione della matrice')
grid on

