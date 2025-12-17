%    Primo elem in lista in pos 1.
%    Example:
%    ?- findk(X,[a,b,c,d,e],3).
%    X = c

findk([], [], _).        % caso per lista vuota 
findk(H, [H|_], 1):- !.  % caso in cui l'eleme
findk(E, [_|R], I):- 
    integer(I),
    I>1,
    I2 is I-1,
    findk(E, R, I2).

