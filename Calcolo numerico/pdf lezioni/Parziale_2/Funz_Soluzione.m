function x = Funz_Soluzione(alpha,n,b)
%forward substitution
for j=1:n
    x(j)=b(j);
    if j<n
        b(j+1)=b(j+1)-alpha*x(j);
    end
end
