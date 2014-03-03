ccc
N=5;
[N1,lval,x,w,gamma] = leg_quad(N);

D=zeros(N1);
for ii = 1:N1
    i=ii-1
    for jj = 1:N1
        j=jj-1;
        if ii==jj && i==0
            dum=-N*(N+1)/4;
        elseif i==j && i>0 && i < N
            dum=0.0;
        elseif i~=j
            dum=lval(N1,ii)/(lval(N1,jj)*(x(ii)-x(jj)));
        elseif i==j && i==N
            dum=N*(N+1)/4;
        end
        D(ii,jj)=dum;
    end
end
D;
% The Assembly
Nel=2;
K=zeros((Nel)*(ii)-Nel+1);
for j = 1:Nel
    for m=1:ii;
        row=(ii-1)*(j-1)+m
        for n = 1:ii;
            col=(ii-1)*(j-1)+n;
            K(row,col)=D(m,n)+K(row,col);
        end
    end
end
K