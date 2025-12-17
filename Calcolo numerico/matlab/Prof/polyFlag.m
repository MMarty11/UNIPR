function y=polyFlag(nodi,y_nodi,x)
% function con implementazione dei polinomi fondamentale di Lagrange
%INPUT
%nodi
%y_nodi=valori nei nodi
%x=ascissa di valutazione del polinomio interpolatore lagrangiano
%OUTPUT
%y=valore del polinomio interpolatore lagrangiano in x
n=length(nodi);
y=eye(n);
xx=linspace(min(nodi),max(nodi));
m=length(xx);
P_n=zeros(m,1);
for i=1:n
    for j=1:m
        P_n(j)=0;
        for k=1:n %valutazione del k-simo polinomio di Lagrange nell'ascissa xx(j)
            space=[1:k-1,k+1:n];
            L_k=prod(xx(j)-nodi(space))/prod(nodi(k)-nodi(space));
            P_n(j)=P_n(j)+y(k,i)*L_k;
        end
    end
    % grafici
    figure(i)
    plot(xx,P_n,'b-',nodi,y(:,i),'ro')
    title(sprintf('l_%d',i))
    grid on 
%    pause
end
%calcolo del polinomio interpolatore in x
y=0;
for k=1:n
    space=[1:k-1,k+1:n];
    L_k=prod(x-nodi(space))/prod(nodi(k)-nodi(space));
    y=y+y_nodi(k)*L_k;
end
            
