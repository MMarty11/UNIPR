%Extract a given number of randomly selected elements from a list 

:- ensure_loaded(remove_K_elem).

rnd_select(_,0,[]). %if we want to extract 0 elements, we return an empty list
rnd_select(Xs,N,[X|Zs]) :- N>0,
length(Xs,L), %we get the length of the list
I is random(L), %we get a random number between 0 and L-1
remove_at(X,Xs,I,Ys), %we remove the element at position I from the list
N1 is N-1, %we decrease the number of elements we want to extract
rnd_select(Ys,N1,Zs). %we call the function recursively with the new list and the new number of elements we want to extract 