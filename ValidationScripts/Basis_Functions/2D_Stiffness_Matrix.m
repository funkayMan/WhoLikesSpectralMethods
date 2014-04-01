Nx=5;
Nx1=Nx+1;

Ny=5;
Ny1=Ny+1;

[xx,yy]

[phi_xi, D_xi, xi, w_xi]=GLL_Basis(Nx);

[phi_eta, D_eta, eta, w_eta]=GLL_Basis(Ny);

K_el=zeros(N1);
for m=1:Nx1
    for n=1:Ny1
        el=0;
        for l = 1:Nx1
            for k=1:Ny1
                el=el+D(n,k)*D(m,k)*w(k);
            end
        end
        K_el(m,n)=el;
    end
end