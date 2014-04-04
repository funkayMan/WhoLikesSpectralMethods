function [phi, D, x, w,gamma,lval]=GLL_Basis(N)
% N=5
[N1,lval,x,w,gamma] = leg_quad(N);
% define derivative of polynomials
lp(1,:)=zeros(size(lval(1,:)));
lp(2,:)=ones(size(lp(1,:)));
for i = 3:N1
    n=i-1;
    lp(i,:)=((2*(n)-1)*lval(i-1,:)+lp(i-2,:));
end
% lval
% lp
% NN=10
% 
% lval(NN,:)
% lp(NN,:)
% 
% plot(x,lval(NN,:),'g','LineWidth',3);
% hold on
% % plot(diff(lval(NN,:))./diff(x'),'r');
% % hold on
% plot(x,lp(NN,:),'LineWidth',3)
% grid on
x=-x;

% Define Basis
for jj=1:N1
    j=jj-1;
    for ii=1:N1
        i=ii-1;
        if i==j;
            phi(jj,ii)=1.0;
        else
            phi(jj,ii)=(-1/(N*(N+1)))*(1-x(ii)^2)/(x(ii)-x(jj))*lp(N1,ii)/lval(N1,jj);
        end
    end
end

% plot(x,phi(10,:))


D=zeros(N1);
for ii = 1:N1
    for jj = 1:N1
        D(ii,jj)=lval(N1,ii)/lval(N1,jj)/(x(ii)-x(jj));
    end
end

for i = 1:N1
    D(i,i)=0;
end
D(1,1)=-N*(N+1)/4;
D(N1,N1)=-D(1,1);
% D(:,N1)=D(:,N1);
