%split a list into two parts

split(L,0,[],L). %if the first part is empty, the second part is the whole list
split([X|Xs], N, [X|Ys], Zs):- %if the first part is not empty, the second part is the rest of the list
    N > 0, %if the number is greater than 0
    N1 is N-1, %decrement the number
    split(Xs, N1, Ys, Zs). %split the rest of the list recursively