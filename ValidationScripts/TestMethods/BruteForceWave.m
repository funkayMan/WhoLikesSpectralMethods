clf
clear
clc

N=15;
N1=N+1;
[phi, D, x, w,gamma]=GLL_Basis(N);

[xx,yy]=meshgrid(x,x);

for m = 1:N1
    for n = 1:N1
        M((n-1)*N1+m,(n-1)*N1+m)=w(m)*w(n);
    end
end
K=zeros(N1*N1);
for m = 1:N1
    for n = 1:N1
        i1=(m-1)*N1+n;
        for j = 1:N1
            for k = 1:N1
                i2=(j-1)*N1+k;
                for xi = 1:N1
                    for eta = 1:N1
                        tmp = phi(m,eta)*D(n,xi)*phi(k,eta)*D(j,xi)+phi(n,xi)*D(m,eta)*phi(j,xi)*D(k,eta);
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
% K(1:N1,1:N1)=eye(N1);
% K(N1*(N1-1)+1:N1*N1,N1*(N1-1)+1:N1*N1)=eye(N1);
% 
for row=2:N
    K((row-1)*N1+1,:)=0;
%     K((row-1)*N1+1,(row-1)*N1+1)=1;
    K((row-1)*N1+N1,:)=0;
%     K((row-1)*N1+N1,(row-1)*N1+N1)=1;
end

%% Initial Condition
f=zeros(N1);
u=zeros(N1*N1,1);
f=sin(pi/2.*xx-pi/2).*sin(pi/2.*yy-pi/2);
% f(floor(N1/2),floor(N1/2))=1;
for i = 1:N1
    for j = 1:N1
        u((i-1)*N1+j)=f(i,j);
    end
end
% surf

%% Time integration
T=0.0183;
dt=0.0001;
t=0:dt:T;
n=length(t);
u_iterat=zeros(N1*N1,n);
% convert from matrix to vector
u_iterat(:,1)=u;
fprintf('============================\n')
fprintf('Time integration has begun\n')
fprintf('============================\n')


tic
for i = 1:n
    u_iterat(:,i+1) = (M-dt/2*K)\(M+dt/2*K)*u_iterat(:,i);      
end
clc
fprintf('\n\n============================\n')
fprintf(' Time elapsed for time integration : %6.5f\n',toc);
fprintf('============================\n')
%
%% Plot it.
vidObj = VideoWriter(['BruteForcedUnstable.avi'],'Motion JPEG AVI');
open(vidObj);
hfig=figure;
for i = 140:170
    surfc(xx,yy,reshape(u_iterat(:,i),[N1 N1]));
    zlim([0 1])
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(['n = ' num2str(i)]);
    pause(0.001)
    mov=getframe(hfig);
    writeVideo(vidObj,mov);
end
close(vidObj);