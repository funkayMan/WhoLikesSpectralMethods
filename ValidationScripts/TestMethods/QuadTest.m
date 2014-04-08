N=5
[N1,lval,x,w,gamma] = leg_quad(N);

for j=1:N
    D1(j,1)=lval(N1,j)/lval(N1,N1)/(x(N1)-x(j))
end