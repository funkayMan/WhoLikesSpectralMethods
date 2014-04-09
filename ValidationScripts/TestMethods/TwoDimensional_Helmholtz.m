clf
clear
clc

warning off all

N=20;
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
% f=ones(N1);
f=sin(pi*xx).*sin(pi*yy);
% f=(-xx .^2+1).*(-yy.^2-1);
surfc(xx,yy,f)
pause
% break
u = zeros(N1*N1,1);



for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j)=f(i,j);
    end
end

%% Mass Matrix
M=zeros(N1*N1);
for m = 1:N1
    for n = 1:N1
        M((m-1)*N1+n,(m-1)*N1+n)=w(m)*w(n);
    end
end
M=M*J;

%% Allocate space for the Stiffness Matrix and then calculate that
%% bad boy.
K_x=zeros((N+1)^2);


%% the xi part
for m = 1:N1
    for n = 1:N1
        for i = 1:N1
            rInd=(n-1)*N1+i;
            cInd=(n-1)*N1+m;
            tmp = D(:,i)'*(D(:,m).*w);
            K_x(rInd,cInd) = -tmp*w(n)*(2.0/(b-a))*((d-c)/2.0);
        end
    end
end
% spy(K_x)
% sum(K_x')
% break

%% the eta part
K_e=zeros(N1*N1);
for m = 1:N1
    for n = 1:N1       
        for j = 1:N1
            rInd=(m-1)*N1+j;
            cInd=(n-1)*N1+j;
            tmp = D(:,j)'*(D(:,n).*w);
            K_e(rInd,cInd) = -tmp*w(m)*(2.0/(b-a))*((d-c)/2.0);
        end
    end
end
% spy(K_e)
% sum(K_e')
% break
% subplot(2,1,1)
%% Form the matrix, take a peek, and see if it is a solution to our system
% sum(K_e')
K=(K_e+K_x);
% spy(K)
% sum(K')
% break
% spy(K,30,'k')
%% Test K
% rhs=K*u;
% lhs=M*d2u;
% err=norm(rhs+lhs,2);
% fprintf('The Error is %6.4f\n',err)
% surfc(xx,yy,reshape
% xlabel('x')
% ylabel('y')
% subplot(2,1,1)
% plot(rhs,'bo-','LineWidth',4)
% hold on
% % Define an analytic derivative
% 
% plot(lhs,'rs-','LineWidth',2)
% H=legend('M\K*u','Analytic Soln');
% set(H,'Location','SouthWest');

% subplot(2,1,2)



% break
%% Add boundary conditions to K
% K=ones(N1*N1);
% K(1:N1,:)=0;
% K(N1*(N1-1)+1:N1*N1,:)=0;
% K(1:N1,1:N1)=eye(N1);
% K(N1*(N1-1)+1:N1*N1,N1*(N1-1)+1:N1*N1)=eye(N1);
% 
% for row=2:N
%     for col=1:N1
%         if row == col
%             K((row-1)*N1+1,((col-1)*N1+1):((col-1)*N1+N1))=0;
%             K((row-1)*N1+1,(col-1)*N1+1)=1;
%             K((row-1)*N1+N1,((col-1)*N1+1):((col-1)*N1+N1))=0;
%             K((row-1)*N1+N1,(col-1)*N1+N1)=1;
%         else
%             K((row-1)*N1+1,(col-1)*N1+1)=0;
%             K((row-1)*N1+1,(col-1)*N1+N1)=0;
%             K((row-1)*N1+N1,(col-1)*N1+1)=0;
%             K((row-1)*N1+N1,(col-1)*N1+N1)=0;
%         end
%     end
% end
%
% spy(K,'k.',50)
% break
%% Time integration
T=.5;
dt=0.001;
t=0:dt:T;
n=length(t);
u_iterat=zeros(N1*N1,n);
% convert from matrix to vector
u_iterat(:,1)=u;

tic
for i = 1:n
    u_iterat(:,i+1) = (M-dt/2*K)\(M+dt/2*K)*u_iterat(:,i);
end
fprintf('Time elapsed for time integration : %6.5f',toc);
%
% Build u back into f for each timestep
% plot them
for i = 1:n
    surfc(xx,yy,reshape(u_iterat(:,i),[N1 N1]));
%     zlim([0 1])
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(['t = ' num2str(dt*i)]);
    pause(0.001)
end
