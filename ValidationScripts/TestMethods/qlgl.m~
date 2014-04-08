function [x,wt] = qlgl(N)
%
% [x,wt] = qlgl(N)
%
% x  - Gauss-Lobatto Points
% wt - Gauss-Lobatto Weights
% N  - Polynomial Degree
%
% by
% Kelly Black
%
% Routine to find the Legendre-Gauss-Lobatto quadrature.
% It uses the algorithm in "Calculation of Gauss
% Quadrature Rules", Golub & Welsch, Mathematics
% of Computation (23) 1969.
%
%
% N=5
N1 = N + 1;
t = zeros(N+1);
beta = 1/sqrt(3);
t(1,2) = beta;
t(2,1) = beta;
for i=2:N,
  t(i+1,i) = sqrt((2*i-1)/(2*i+1))*i/(2*i-1);
  t(i,i+1) = t(i+1,i);
end
t(N+1,N) = sqrt(N/(2*N-1));
t(N,N+1) = t(N+1,N);


[wt,x] = eig(t);
[x,k] = sort(diag(x));
x = x;
wt = 2*wt(1,k).^2';