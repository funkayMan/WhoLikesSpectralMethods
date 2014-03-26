ccc

Nx=3;
Ny=Nx;
N=Nx;
N1=N+1;

[phi_xi, D_xi, xi, w_xi,gamma_xi]=GLL_Basis(Nx);

[phi_eta, D_eta, eta, w_eta,gamma_eta]=GLL_Basis(Ny);

a=0; b=pi;
c=0; d=pi;

% x=(a-b)*(xi-1)/2+a;
% y=(c-d)*(eta-1)/2+c;
%
% [xx,yy]=meshgrid(x,y);
% f=sin(xx).*sin(yy);
% surfc(xx,yy,f);
% break
%% Mass Matrix
% M=zeros(N1);
% for i = 1:N1
%     M(i,i)=w_xi(i)*w_eta(i);
% end
% M=M.*(a-b)*(c-d)/4;

%% Stiffness Matrix
K=zeros((N+1)^2);
a_i=zeros(N+1);
for n = 1:N1
    ni=(n-1)*N1+1;
    for m = 1:N1
        mi=(m-1)*N1+1;
        for k = 1:N1
            if m==n
                for l = 1:N1
                    K(mi+k-1,ni+l-1)=1+K(mi+k-1,ni+l-1);
                end
            else
                K(mi+k-1,ni+k-1)=1+K(mi+k-1,ni+k-1);
            end
        end
    end
end
K
