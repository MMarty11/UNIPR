genitore(andrea, [lucia, mino]).
genitore(lucia, [anna, enzo, marta]).
genitore(mino, [sandra, giuseppe, tina]).
genitore(anna, [emma]).
genitore(marta, [luisa, lino, sofia]).

% definire le regole per i seguenti predicati:
% • nonno(X, Y)
%  in cui X è nonno (o nonna) di Y;
% • antenato(X, Y)
%  in cui X è un antenato di Y

antenato(X, X).
antenato(X, Y):- 
    genitore(X, L), 
    member(Y, L).  
antenato(X, Y):-
    genitore(X, L),
    member(Z, L), 
    antenato(Z, Y). 

nonno(X, Y):- 
    genitore(X, L1),
    member(Z, L1),
    genitore(Z, L2),
    member(Y, L2). 