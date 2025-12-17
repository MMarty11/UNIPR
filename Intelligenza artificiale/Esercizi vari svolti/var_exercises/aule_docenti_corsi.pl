%Supponendo di avere una KB tipo questa 
aula(n1, 220).
aula(n2, 180).

docente(rossi, 5467).
docente(bianchi, 5687).

corso(geometria, rossi).
corso(algebra, bianchi).

orario(geometria, lun, 1, n8).
orario(geometria, mer, 4, n2).
orario(algebra, ven, 7, v1).

prerequisito('analisi 1', 'analisi 2').
prerequisito('calcolatori A', 'calcolatori B').

% Definire le regole per i seguenti predicati: 
% a) docenteOccupato(D, G)
% in cui il docente D ha almeno un’ora di lezione il giorno G;
% b) docenteLibero(D, G)
% in cui il docente D non ha lezione il giorno G;
% c) precedente(P, C)
% in cui P è un corso (direttamente o indirettamente) precedente al corso C.

docenteOccupato(D, G):-
    orario(C, G, _, _), 
    corso(C,D).

docenteLibero(D, G):-
    docente(D, _),
    \+(docenteOccupato(D, G)).  %NB che not è \+ e non !

precedente(P, C):-
    prerequisito(P, C).
precedente(P, C):-
    prerequisito(X, C),
    precedente(P, X).

