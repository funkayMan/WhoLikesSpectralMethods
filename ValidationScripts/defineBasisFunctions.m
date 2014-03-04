clc

syms  dP_n(x) dP_m(x) P_n(x) P_m(x) n x x_j x_i

phi_n=-(1-x^2)/((x-x_j)*(n*(n+1))*P_n)*diff(P_n(x),x);

pretty(phi_n)


dPhi=diff(phi_n,x)
% dPhi=subs(dPhi,x,x_i);

% term1=(2*x*diff(P_n(x), x))/(n*P_n(x)*(x - x_j)*(n + 1));

% diff(




