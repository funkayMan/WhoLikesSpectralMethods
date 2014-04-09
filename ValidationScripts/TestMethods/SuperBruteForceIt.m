clf
clear
clc

N=10;
N1=N+1;
[phi, D, x, w,gamma]=GLL_Basis(N);

[xx,yy]=meshgrid(x,x);

for m = 1:N1
    for n = 1:N1
        M((n-1)*N1+m,(n-1)*N1+m)=w(m)*w(n);
    end
end
P=zeros(N1*N1);
K=P;
for m = 1:N1
    for n = 1:N1
        i1=(m-1)*N1+n;
        for j = 1:N1
            for k = 1:N1
                i2=(j-1)*N1+k;
                for xi = 1:N1
                    for eta = 1:N1
                        P(i1,i2)=P(i1,i2)+1;
% %                         tmp=(phi(j,eta)*D(i,xi)+phi(i,xi)*D(j,eta))*(phi(m,xi)*D(n,eta)+phi(n,eta)*D(m,xi))+...
% %                             (phi(i,xi)*D(j,eta)+phi(j,eta)*D(i,xi))*(phi(m,xi)*D(n,eta)+phi(n,eta)*D(m,xi));

                        tmp =phi(m,eta)*D(n,xi)*phi(k,eta)*D(j,xi)+phi(n,xi)*D(m,eta)*phi(j,xi)*D(k,eta);
                        K(i1,i2)=-tmp*w(xi)*w(eta)+K(i1,i2);
                    end
                end
            end
        end
    end
end
% K

%% Boundary Conditions
K(1:N1,:)=0;
K(N1*(N1-1)+1:N1*N1,:)=0;
K(1:N1,1:N1)=eye(N1);
K(N1*(N1-1)+1:N1*N1,N1*(N1-1)+1:N1*N1)=eye(N1);

for row=2:N
    K((row-1)*N1+1,:)=0;
    K((row-1)*N1+N1,:)=0;
end


f=sin(pi/2.*xx-pi/2).*sin(pi/2.*yy-pi/2);
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j)=f(i,j);
    end
end
% surf

%% Time integration
T=0.05;
dt=0.0001;
t=0:dt:T;
n=length(t);
u_iterat=zeros(N1*N1,n);
% convert from matrix to vector
u_iterat(:,1)=u;
fprintf('Time integration has begun\n')
tic
for i = 1:n
    u_iterat(:,i+1) = (M-dt/2*K)\(M+dt/2*K)*u_iterat(:,i);
end
fprintf('Time elapsed for time integration : %6.5f',toc);
%
% Build u back into f for each timestep
% plot them
%% Plot it.
for i = 1:n
    surfc(xx,yy,reshape(u_iterat(:,i),[N1 N1]));
    zlim([0 1])
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(['t = ' num2str(dt*i)]);
    pause(0.001)
end