%Draw N different random numbers from the set 1..M

:- ensure_loaded(extract_N).
:- ensure_loaded(create_intlist_rnd).

lotto(L1,L2):- 
    range(1,M,R), rnd_selectL1(L1,N,L2). 