% Data la KB 
genitore(guido, elena).
genitore(guido, luisa).
genitore(elena, giovanni).
genitore(elena, paola).
genitore(luisa, andrea).
genitore(luisa, dario).

% Specificare i seguenti predicati: 
% 1. fratello(X,Y) dove x e y sono fratelli
% 2. cugini(X,Y) dove x e y sono cugini

fratello(X, Y):-
    genitore(Z, X),
    genitore(Z, Y),
    X \= Y. %NB che \= è il simbolo di disuguaglianza

cugino(X, Y):-
    genitore(Z, X),
    genitore(W, Y),
    fratello(Z, W),
    X \= Y.

