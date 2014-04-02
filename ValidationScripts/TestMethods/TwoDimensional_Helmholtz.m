%ccc
% clf
clear
clc
clf
warning off all

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
%(i
[xx,yy]=meshgrid(x,y);
f=xx.^2.*yy.^2;
% surfc(xx,yy,f);
u = zeros(N1*N1,1);
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j)=f(i,j);
    end
end
dF=2.*xx.^2;
d2u = zeros(N1*N1,1);
for i = 1:N1
    for j = 1:N1
        d2u((i-1)*N1+j)=dF(i,j);
    end
end



%% Mass Matrix
M=zeros(N1*N1);
for i = 1:N1
    for j = 1:N1
        M((i-1)*N1+j,(i-1)*N1+j)=w(j)*w(i);
    end
end
M=M*J;

%% Allocate space for the Stiffness Matrix and then calculate that
%% bad boy.
K_x=zeros((N+1)^2);


%% the xi part
for m = 1:N1
    for n = 1:N1
        rInd=(n-1)*N1+m;
        for i = 1:N1
            cInd=(n-1)*N1+i;
            tmp = 0.0;
            for l = 1:N1
                tmp = tmp + D_xi(l,i)*D_xi(l,m)*w(l);
            end
            K_x(rInd,cInd) = -tmp*w(n)*(2.0/(a-b))*((c-d)/2.0);
        end
    end
end


%% the eta part
K_e=zeros(N1*N1);
for m = 1:N1
    for n = 1:N1
        
        for j = 1:N1
            rInd=(n-1)*N1+m;
            cInd=(j-1)*N1+m;
            tmp = 0.0;
            for k = 1:N1
                tmp = tmp + D_eta(k,j)*D_eta(k,n)*w(k);
            end
            K_e(rInd,cInd) = -tmp*w(m)*(2.0/(c-d))*((a-b)/2.0);
     

        end
    end
end
subplot(2,1,1)
spy(K_e)
% pause(0.001)

%% Form the matrix, take a peek, and see if it is a solution to our system
K=(K_e);

% spy(K,30,'k')
%% Test K
rhs=M\K*u;
err=norm(rhs+d2u,2);
fprintf('The Error is %6.4f\n',err)
subplot(2,1,2)
plot(rhs,'bo-','LineWidth',2)
hold on
% Define an analytic derivative

plot(d2u,'rs-','LineWidth',2)
H=legend('M\K*u','Analytic Soln');
set(H,'Location','SouthWest');

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