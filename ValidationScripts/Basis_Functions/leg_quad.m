function [N1,lval,xl,w,gamma] = leg_quad(N)


% Function to return the Gauss-Lobotto quadrature for the
% Legendre polynomials.
%
%    Arguments:
%        N   - Degree of the polynomials to be used
%
%    Returns:
%        N1    - N + 1
%        lval  - Values of the Legendre polynomials on the abscissa
%               lval(i,j) = value of Legendre polynomial i on
%                           the abscissa point j
%        xl    - abscissa of the quadrature
%        w     - Weight of the quadrature
%        gamma - Normalization.  Value of the integral on [-1,1]
%                of the square of the Legendre polynomials.
%
%  Author: Kelly Black
%          Center for Research in Scientific Computing
%          NC State University
%          black@crsc1.math.ncsu.edu
%
% N=6;

N1 = N+1;
[xl,w] = qlgl(N);

% lval is the values of the Legendre polys
% on the grid points.  
lval = zeros(N1);
lval(1,:) = ones(1,N1);
lval(2,:) = xl';
for i=3:N1,
  l = i-1;
  lval(i,:) = (2*l-1)/l*xl'.*lval(i-1,:) - (l-1)/l*lval(i-2,:);
end


% Find the normalization parameters
% Page 62 (& 59) Spectral Methods in Fluid Dynamics, Canuto et al.
% Found from the inner product <pn,pn>
gamma = zeros(N1,1);
for n=1:N1,
  l = n-1;
  gamma(n) = 1/(l+0.5);
end

