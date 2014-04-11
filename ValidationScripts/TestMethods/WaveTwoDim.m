clf
clear
clc

warning off all

N=10;
N1=N+1;

[phi, D, x, w,gamma]=GLL_Basis(N);


a=-1; b=1;
c=-1; d=1;

x=(b-a)*(x+1)/2+a;
y=(d-c)*(x+1)/2+c;
J=(b-a)*(d-c)/4;
%(i
[xx,yy]=meshgrid(x,y);
f=zeros(N1);
f=exp(-(xx).^2*7).*exp(-(yy).^2*7);
% f=sin(pi*(3*xx-1)).*sin(pi*(3*yy-1));
surfc(xx,yy,f)
% break
u = zeros(N1*N1,1);



for i = 1:N1
    for j = 1:N1
        u((j-1)*N1+i)=f(j,i);
    end
end
% subplot(2,1,1)
% surfc(xx,yy,f);
% subplot(2,1,2)
% surfc(xx,yy,reshape(u,[N1 N1]))
% break
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
%% the xi part
K_x=zeros((N+1)^2);
for m = 1:N1
    for n = 1:N1
        for i = 1:N1
            rInd=(n-1)*N1+i;
            cInd=(n-1)*N1+m;
            tmp = D(:,m)'*w;
            K_x(rInd,cInd) = -tmp*w(n)*(2/(d-c));
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
            rInd=(j-1)*N1+m;
            cInd=(n-1)*N1+m;
            tmp = D(:,n)'*w;
            K_e(rInd,cInd) = -tmp*w(m)*(b-a)/2.0;
        end
    end
end

a=10
K=a*(K_x);
% break
%% Add boundary conditions to K
% K(1:N1,:)=0;
% K(N1*(N1-1)+1:N1*N1,:)=0;
% % K(1:N1,1:N1)=eye(N1);
% % K(N1*(N1-1)+1:N1*N1,N1*(N1-1)+1:N1*N1)=eye(N1);
%
% for row=2:N
%     K((row-1)*N1+1,:)=0;
% %         K((row-1)*N1+1,(row-1)*N1+1)=1;
%     K((row-1)*N1+N1,:)=0;
% %         K((row-1)*N1+N1,(row-1)*N1+N1)=1;
% end


%% Time integration
T=5;
dt=0.1;
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
%% plot them

% caxis manual;          % allow subsequent plots to use the same color limits

% vidObj = VideoWriter(['ElegantAdiabaticBC_0.avi'],'Motion JPEG AVI');
% open(vidObj);
% hfig=figure;
for i = 1:n
    
%     clf
surfc(xx,yy,reshape(u_iterat(:,i),[N1 N1]));
%     contourf(xx,yy,reshape(u_iterat(:,i),[N1 N1]),50);
    colorbar
    caxis([0 1])
%     shading flat
%     set(gcf,'edgecolor','none');
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(['i = ' num2str(i)]);
    zlim([0 1])
    pause(0.001)
%     mov=getframe(hfig);
%     writeVideo(vidObj,mov);
%     %    clf
end
% close(vidObj);
