list_order([X, Y | Tail]) :- X =< Y, list_order([Y|Tail]).
list_order([X]).