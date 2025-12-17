%create a list containing all integers within a given range
%range(I,K,L).

range(I,I,[I]). %base case
range(I,K,[I|L]) :- I < K, I1 is I+1, range(I1,K,L). %recursive case