function [P]=lagrange_interp(x,y);
N=length(x);
for j = 1:N;
    pp=poly(x((1:N)~=j));
    pvals(j,:)=pp ./ polyval(pp,x(j));
end
P=y*pvals;