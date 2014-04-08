N=10;
[phi, D, eta, w,gamma]=GLL_Basis(N);

syms x y

f=x^2*y^2


a=0;
b=3.14159;
c=0;
d=b;

j=1;
n=1;

% x=(b-a)*(eta-1)/2+b;
% y=(d-c)*(eta-1)/2+d;
J=(b-a)*(d-c)/4;

double(int(diff(f,x,2)*D(2,:)*D(n,:)',-1,1))
