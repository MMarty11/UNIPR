% duplicate the elements of a list 

duplicate([],[]).% base case
duplicate([X|Xs],[Y|Ys]) :- duplicate(Xs, Ys). %if X is a list, duplicate it and put it in Y
