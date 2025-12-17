%eliminate consecutive duplicates of list elements.
%If a list contains repeated elements they are replaced with a single copy of the element. The order of the elements is not changed.

%Example:
%?- compress([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
%X = [a,b,c,a,d,e]

compress([],[]). %empty list case 

compress([A,A | B],X) :- 
    compress([A | B], X), !. %if the first two elements are the same, remove the first one and try again
    
compress([A, B | C], [A | X]) :- 
    compress([B | C], X), ! %if the first two elements are different, keep the first one and try again