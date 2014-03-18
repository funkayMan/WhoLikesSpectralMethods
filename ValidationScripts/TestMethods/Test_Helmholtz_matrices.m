ccc
global K M

N=20;
[phi, D, x, w]=GLL_Basis(N);
N1=N+1;
M=zeros(N1);
K=M;
for i = 1:N1
    M(i,i)=w(i);
    for j = 1:N1
        for k=1:N1
            K(i,j)=K(i,j)+D(i,k)*D(j,k);
        end
    end
end

u(:,1)=sin(pi*x);



T=0.1;
dt=0.0001;
t=0:dt:T;
n=length(t);
for i = 1:2
    plot(x,u(:,i));
    k1=RHS(u(:,i));
    k2=RHS(u(:,i)+dt/2*k1);
    k3=RHS(u(:,i)+dt/2*k2);
    k4=RHS(u(:,i)+dt*k3);
    u(:,i+1)=u(:,i)+dt/6*(k1+2*k2+2*k3+k4);
end
    

