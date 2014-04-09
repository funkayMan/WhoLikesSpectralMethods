clear all
close all
clc

global K M

N=10;
[phi, D, x, w,gamma]=GLL_Basis(N);
N1=N+1;
M=zeros(N1);
K=M;
for i = 1:N1
    M(i,i)=w(i);
    for j = 1:N1
        for k=1:N1
            K(i,j)=K(i,j)-D(i,k)*D(j,k);
        end
    end
end
% set u on the ends to zero...
K(1,:)=0;
K(N1,:)=0;
K(1,1)=1;
K(N1,N1)=1;
u(:,1)=sin(pi*x);



T=2;
dt=0.001;
t=0:dt:T;
n=length(t);
for i = 1:n
    plot(x,u(:,i));
    ylim([-1 1])
    %
    u(:,i+1) = (M-dt/2*K)\(M+dt/2*K)*u(:,i);
    %
    pause(0.01)
end
    

