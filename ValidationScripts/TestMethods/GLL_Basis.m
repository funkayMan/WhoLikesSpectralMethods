function [phi, D, x, w,gamma]=GLL_Basis(N)
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


% Define Basis
for jj=1:N1
    j=jj-1;
    for ii=1:N1
        i=ii-1;
        if i==j;
            phi(jj,ii)=1.0;
        else
            phi(jj,ii)=(-1/(N*(N+1)))*(1-x(ii)^2)/(x(ii)-x(jj))*lp(end,ii)/lval(end,jj);
        end
    end
end

% plot(x,phi(10,:))


D=zeros(N1);
for ii = 1:N1
    i=ii-1;
    for jj = 1:N1
        j=jj-1;
        if i==j && i==0
            dum=N*(N+1)/4;
        elseif i==j && i>0 && i < N
            dum=0.0;
        elseif i~=j
            dum=lval(end,ii)/(lval(end,jj)*(x(ii)-x(jj)));
        elseif i==j && i==N
            dum=-N*(N+1)/4;
        end
        D(ii,jj)=dum;
    end
end