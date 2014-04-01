ccc

Nx=3;
Ny=Nx;
N=Nx;
N1=N+1;

[phi_xi, D_xi, xi, w,gamma_xi]=GLL_Basis(Nx);

[phi_eta, D_eta, eta, w,gamma_eta]=GLL_Basis(Ny);

a=0; b=pi;
c=0; d=pi;

x=(a-b)*(xi-1)/2+a;
y=(c-d)*(eta-1)/2+c;
J=(a-b)*(c-d)/4;
%
[xx,yy]=meshgrid(x,y);
f=sin(xx).*sin(yy);
% surfc(xx,yy,f);

%% Mass Matrix
M=zeros(N1);
for i = 1:N1
    for j = 1:N1
        M((i-1)*N1+j,(i-1)*N1+j)=w(i)*w(i);
    end
end
M=M*J;

%% Stiffness Matrix
K_x=zeros((N+1)^2);
%% the xi part
for m = 1:N1
    for i = 1:N1    
        for n = 1:N1
            rInd=(m-1)*N1+n;
            cInd=(m-1)*N1+i;
            for l = 1:N1
                K_x(rInd,cInd)=K_x(rInd,cInd)+D_xi(i,l)*D_xi(i,l)*w(l)*w(n);
                %             end
            end
        end
    end
end
K_x=(2/(a-b))^2*K_x;
%% the eta part
K_e=zeros(N1*N1);
for m = 1:N1
    for j = 1:N1    
        for n = 1:N1
            rInd=(m-1)*N1+n;
            cInd=n+(j-1)*N1;
            for k = 1:N1                
                K_e(rInd,cInd)=K_e(rInd,cInd)+D_xi(j,k)*D_xi(n,k)*w(m)*w(k);
            end
        end
    end
end
K_e=(2/(c-d))^2*K_e;
K=-1*(K_e+K_x)*J;

spy(K,30,'k')
%% Test K
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j,1)=f(i,j);
    end
end
norm(K*u-u)

break
%% Add boundary conditions to K
for m=1:N1
    for n=1:N1
        K((m-1)*N1+1,(n-1)*N1+1:(n-1)*N1+N1)=0;
        K((m-1)*N1+1,(n-1)*N1+1)=1;
        K((m-1)*N1+N1,(n-1)*N1+1:(n-1)*N1+N1)=0;
        K((m-1)*N1+N1,(n-1)*N1+N1)=1;
    end
end
%
K(1:N1,:)=0;
K(N1*(N1-1)+1:N1*N1,:)=0;
K(1:N1,1:N1)=eye(N1);
K(N1*(N1-1)+1:N1*N1,N1*(N1-1)+1:N1*N1)=eye(N1);

%% Time integration
T=0.002;
dt=0.00001;
t=0:dt:T;
n=length(t)
u=zeros(N1*N1,n);
% convert from matrix to vector
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j,1)=f(j,i);
    end
end

tic
for i = 1:n
    u(:,i+1) = (M-dt/2*K)\(M+dt/2*K)*u(:,i);
end
fprintf('Time elapsed for time integration : %6.5f',toc);
%
% Build u back into f for each timestep
alpha=zeros(N1,N1,n);
for i=1:n
    for j = 1:N1
        for k = 1:N1
            alpha(j,k,i)=u((j-1)*N1+k,i);
        end
    end
end

% plot them
for i = 1:n
    surfc(xx,yy,alpha(:,:,i));
    xlabel('x');
    ylabel('y');
    zlabel('z');
    text(pi/2,pi,1,['t = ' num2str(dt*i)]);
    pause(0.01)
end