%Remove the K'th elementh from a list. 
%The first element in the list is number 1.

remove_at(X,[X|Xs],1,Xs).  %base case
remove_at(X,[Y|Xs],K,[Y|Ys]) :- K > 1, %if K > 1, then K1 is K - 1, remove_at(X,Xs,K1,Ys).
   K1 is K - 1, remove_at(X,Xs,K1,Ys). 
