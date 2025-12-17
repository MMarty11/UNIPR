%caso base -> la lista è vuota e quindi N sarà sempre 0 
card(_,[],0).

%caso 1 -> l'elemento HEAD della lista è quello che stiamo contando 
card(X, [X|T], N):-
    card(X, T, OldN), N is OldN+1. 

%caso 2 -> l'elemento che vogliamo contare non è nella testa della lista 
card(X2, [X|T], N2):- 
    dif(X2, X), card(X2, T, N2).