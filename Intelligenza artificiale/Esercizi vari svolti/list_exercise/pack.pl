% Pack consecutive duplicates of list elements into sublists. 
% If a list contains repeated elements they should be placed in separate sublists.

pack([],[]). % Base case

pack([X|Xs], [Z|Zs]) :-
    transfer(X, Xs, Ys, Z), % Transfer all Xs to Ys, and put them in Z
    pack(Ys, Zs). % Recurse

% transfer (X, Xs, Ys, Z) is the list of Xs with all Xs leadin copies are removed and put in Z

transfer(X, [], [], [X]). % Base case
transfer(X, [Y|Ys], [Y|Ys], [X]) :- X \= Y. % If X is not equal to Y, then put X in Z and put Y in Ys
transfer(X, [X|Xs], Ys, [X|Zs]) :- transfer(X, Xs, Ys, Zs). % If X is equal to X, then put X in Z and recurse