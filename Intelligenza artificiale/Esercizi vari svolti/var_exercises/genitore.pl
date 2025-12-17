genitore(enrico, maria).
genitore(enrico, mino).
genitore(maria, ettore).
genitore(sofia, aldo).
genitore(sofia, marta).
genitore(aldo, stella).

% definire il predicato parenti(X, Y), che stabilisce se X ed Y appartengono allo stesso albero 
% genealogico.


antenato(X, X).

antenato(X, Y):- 
    genitore(X, Z), 
    antenato(Z, Y). 

parenti(X, Y):- 
    antenato(Z, X),
    antenato(Z, Y). 