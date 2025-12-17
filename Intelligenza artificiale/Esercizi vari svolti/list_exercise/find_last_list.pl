% find the last element of a list 
% ex: 
% ?- last(X, [a,b,c,d]). 
% X = d

last(_, []). % caso lista vuota 

last(H, [H]). % -> sarà vero quando H è l'unico (e ultimo) elemento della lista

last(X, [_|R]):-   % splittiamo la lista, dimentichiamoci (togliamo) la testa 
    last(X,R), !.  % chiamiamo di nuovo last/2, ma usando solo la coda della lista. Il cut serve a fermarci quando sarà vero.