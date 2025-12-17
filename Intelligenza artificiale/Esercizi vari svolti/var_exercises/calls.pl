calls(p1, p2).
calls(p1, p3).
calls(p2, p4).
calls(p2, p5).
calls(p3, p6).
calls(p5, p7).

% Data la KB sopra definita, che descrive chiamate di procedure in un linguaggio imperativo, 
% definire il predicato activates(P, Q) in cui la procedura Q è direttamente o non chiamata dalla procedura P 

activates(P, Q):- calls(P, Q).

activates(P, Q):- calls(P, R), activates(R, Q). 
