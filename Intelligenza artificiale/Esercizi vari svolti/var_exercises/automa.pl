state(0).
state(1).
state(2).
state(3).
initial(0).
final(2).
final(3).
trans(0,a,1).
trans(1,b,2).
trans(2,c,3).
trans(3,d,3).
trans(3,e,0).

% l’automa ha uno ed un solo stato iniziale ed almeno uno stato finale, definire le regole per i seguenti 
% predicati:
% a) gen(S, L)
%  in cui la lista (eventualmente vuota) L di simboli è generata da un cammino (eventualmente
% vuoto) che parte dallo stato S e termina in uno stato finale;
% b) generates(L)
% in cui la lista L è generata da un cammino che parte dallo stato iniziale e termina in uno stato
% finale.

gen(S, []):- final(S). 
gen(S, [X|Y]):- trans(S, X, S2), gen(S2, Y).

generates(L):- initial(S0), gen(S0, L).