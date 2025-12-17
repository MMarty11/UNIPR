% find the second to last element of a list

sectolast(H, [H,_]). % Quando X è uguale al penultimo elemento di una lista, di cui non ci interessa l'ultimo (quindi _)

sectolast(X, [_|R]):-    % splitta la lista, toglie la testa e lascia il resto 
    sectolast(X,R), !.   % chiamiamo di nuovo, usando solo la coda 