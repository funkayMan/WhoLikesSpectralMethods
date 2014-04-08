%ccc
% clf
clear
clc
close
warning off all

N=5;
N1=N+1;

[phi, D, x, w,gamma]=GLL_Basis(N);

% [phi_eta, D_eta, eta, w,gamma_eta]=GLL_Basis(Ny);

a=-1; b=1;
c=-1; d=1;

x=(b-a)*(x+1)/2+a;
y=(d-c)*(x+1)/2+c;
J=(b-a)*(d-c)/4;
%(i
[xx,yy]=meshgrid(x,y);
f=xx;
% surfc(xx,yy,f);
u = zeros(N1*N1,1);
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j)=f(i,j);
    end
end
dF=ones(N1);
d2u = zeros(N1*N1,1);
for i = 1:N1
    for j = 1:N1
        d2u((i-1)*N1+j)=dF(i,j);
    end
end



%% Mass Matrix
M=zeros(N1*N1);
for m = 1:N1
    for n = 1:N1
        M((n-1)*N1+m,(n-1)*N1+m)=w(m)*w(n);
    end
end
M=M*J;
% M=eye(N1*N1)*J

%% Allocate space for the Stiffness Matrix and then calculate that
%% bad boy.
K_x=zeros((N+1)^2);


%% the xi part
for m = 1:N1
    for n = 1:N1
        rInd=(n-1)*N1+m;
        for i = 1:N1
            cInd=(n-1)*N1+i;
            tmp = D(:,i)'*(D(:,m).*w);
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
            tmp = D(:,j)'*(D(:,n).*w);
            K_e(rInd,cInd) = -tmp*w(m)*(2.0/(c-d))*((a-b)/2.0);
        end
    end
end
% subplot(2,1,1)
%% Form the matrix, take a peek, and see if it is a solution to our system
K=(K_e+K_x);

% spy(K,30,'k')
%% Test K
rhs=K*u;
lhs=M\d2u;
err=norm(rhs+lhs,2);
fprintf('The Error is %6.4f\n',err)
surfc(xx,yy,reshape(rhs-lhs,[N1 N1]))
xlabel('x')
ylabel('y')
% subplot(2,1,1)
% plot(rhs,'bo-','LineWidth',4)
% hold on
% % Define an analytic derivative
% 
% plot(lhs,'rs-','LineWidth',2)
% H=legend('M\K*u','Analytic Soln');
% set(H,'Location','SouthWest');

% subplot(2,1,2)



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
