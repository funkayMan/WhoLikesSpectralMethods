ccc
N=5;
[N1,lval,x,w,gamma] = leg_quad(N);
lp(1,:)=zeros(N+1,1);
lp(2,:)=ones(N+1,1);
for i = 3:N+1
    lp(i,:)=(2*(i-1)-1)*lval(i-1,:)+lp(i-2,:);
end

x=x'
% make basis funcs.
xx=linspace(0,1,10);
for j = 1:N1
    for i = 1:N1
        n=i-1;
        phi(j,:)=-((1-x.^2)./(n*(n+1)*(x-x(j)))).*(lp(i,:)/lval(i,j));
    end
end
phi
plot(x,phi)
hold on
plot(x,zeros(size(x)),'rs','LineWidth',4)
ylim([-1e-10 1])
grid on