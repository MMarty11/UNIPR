%create a list containing all integers withing a given range 

range(I,I,[I]).
range(I,K,[I|L]) :- 
    I < K, I1 is I+1, range(I1,K,L). 