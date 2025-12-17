%Here backtracking will happen and all rules will be checked, even though rule 1 will be true
%and there is no need to check rule 2 and 3 

f(X,0) :- X < 3.              % Rule 1
f(X,2) :- 3 =< X, X < 6.      % Rule 2
f(X,4) :- 6 =< X.             % Rule 3

%versus the cut version that will not executre rule 3 since the cut (!) operator is used 

f(X,0) :- X < 3,!.            % Rule 1
f(X,2) :- 3 =< X, X < 6,!.    % Rule 2
f(X,4) :- 6 =< X.             % Rule 3