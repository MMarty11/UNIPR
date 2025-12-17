%flatten a nested list structure
%transform a list, holding lists as elements into a flat list (without nested lists)

flatten([],[]). %empty list case

flatten(H, [H]):- \+ is_list(H), !. %base case 

flatten([H|T], R):- 
flatten(H, R1), 
flatten(T, R2), 
append(R1, R2, R), !. %recursive case
