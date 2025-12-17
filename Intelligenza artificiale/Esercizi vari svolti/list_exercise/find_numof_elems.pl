% trova il numero di elementi in una lista 
% per farlo, togliamo la testa finché non rimaniamo senza elementi e aumentiamo una variabile finché non abbiamo finito 

numelems([],0).       % caso base per lista vuota 
numelems([_], 1):- !. % caso per lista di un elemento 
numelems([_|R], X):-  % splittiamo e togliamo la testa 
    numelems(R,B), !, X is 1+B. 