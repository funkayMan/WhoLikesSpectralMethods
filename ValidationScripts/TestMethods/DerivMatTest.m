clf
tic
n=1:200;
N=70;
for i=1:length(n);
[phi, D, x, w,gamma]=GLL_Basis(N);


err(i)=norm(D*(x.^i)-i.*x.^(i-1));
end
toc
loglog(n,err,'bo-')