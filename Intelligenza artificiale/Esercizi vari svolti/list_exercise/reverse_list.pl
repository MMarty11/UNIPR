%invertire una lista 

reverse([], []).                % caso base, le due liste sono vute 
reverse([_], [_]).              % caso base2, le due liste hanno un solo elemento  
reverse([H1, H2], [H2, H1]).    % caso per due elementi 
reverse([H | R], L) :-          % splittiamo, togliamo la testa 
    reverse(R, K),              % recursive call without head
    append(K, [H], Z),          % append head as last item 
    L = Z,                      
    !.