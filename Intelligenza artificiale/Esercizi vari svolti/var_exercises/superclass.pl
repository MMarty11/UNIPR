class(persona).
var(nome, persona).
var(indirizzo, persona).
var(codice, persona).
class(studente).
inherits(studente, persona).
var(matricola, studente).
var(scuola, studente).
class(lavoratore).
inherits(lavoratore, persona).
var(professione, lavoratore).
var(stipendio, lavoratore).
class(studLavor).
inherits(studLavor, studente).
inherits(studLavor, lavoratore).

% data la KB soprastante, definire 

% a) superclass(C1, C2)
% in cui C1 è (direttamente o indirettamente) una superclasse di C2;
% b) ambref(V, C)
% in cui V è una variabile definita in C o ereditata da una superclasse di C.

superclass(C1, C2):- inherits(C2, C1).
superclass(C1, C2):- inherits(C, C1), superclass(C, C2).

ambref(V, C):- var(V, C).
ambref(V, C):- var(V, C1), superclass(C1, C).    