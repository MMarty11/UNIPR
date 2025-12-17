vicolo(garibaldi, lima).
vicolo(lima, leonardo).
vicolo(leonardo, loreto).
vicolo(leonardo, scala).
vicolo(leonardo, duomo).
vicolo(loreto, scala).
vicolo(duomo, lima).
vicolo(duomo, brusati).

% definire le regole per i seguenti predicati:
% a) raggiungibile(P1, P2)
% in cui la piazza P2 è raggiungibile dalla piazza P1 percorrendo una serie (non vuota) di vicoli;
% b) circolare(P)
% in cui P è una piazza che si trova su un tragitto circolare di vicoli.

raggiungibile(X, Y):- 
    vicolo(X, Y). 

raggiungibile(X, Y):- 
    vicolo(X, Z), raggiungibile(Z, Y); 

circolare(P):- raggiungibile(P, P). 