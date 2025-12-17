n=100;
A=hilb(n);
alpha=n;
AA=A+alpha*eye(n);
cond(AA)
cond(A)
