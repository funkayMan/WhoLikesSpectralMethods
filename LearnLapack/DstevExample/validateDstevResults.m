%% make identical tridiagonal matrix to validate solution from DSTEV
n=5
A=zeros(n);
for i = 1:n
    A(i,i)=i-1;
    
end

for i = 2:n-1
    A(i,i+1)=A(i-1,i)+2;
    A(i+1,i)=A(i,i+1);
end
[v,d]=eig(A)

