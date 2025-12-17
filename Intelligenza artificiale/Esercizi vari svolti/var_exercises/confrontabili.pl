node(0, [1,2]).
node(1, [3]).
node(2, [3,4]).
node(3, [5]).
node(4, []).
node(5, []).

% Ogni nodo è rappresentato dal suo identificatore e dalla lista di nodi successivi. Il grafo stabilisce un 
% ordinamento temporale parziale tra eventi. Ad esempio, l’evento 0 accade prima di ogni altro evento. Gli 
% eventi 1 e 2 accadono dopo l’evento 0. L’evento 3 accade dopo gli eventi 1 e 2. L’evento 1 accade prima 
% dell’evento 5. D’altra parte, alcuni eventi non sono confrontabili. Ad esempio, non è possibile stabilire una 
% relazione d’ordine tra gli eventi 1 e 2, nemmeno tra 4 e 5. Per definizione, ogni evento è confrontabile con 
% se stesso. In sintesi, due eventi possono essere o meno confrontabili. 
% Sulla base di tale interpretazione del grafo, si chiede di specificare la seguente regola:
% confrontabili(N1, N2)
% in cui gli eventi N1 ed N2 sono confrontabili

link(N1, N2):- node(N1, F), node(N2, _), member(N2, F).
collegato(N1, N2):- link(N1, N2). 
collegato(N1, N2):- link(N1, N), collegato(N, N2).
confrontabili(N, N):- node(N, _).
controntabili(N1, N2):- collegato(N1, N2).
controntabili(N1, N2):- collegato(N2, N1). 