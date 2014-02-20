ccc
N=20;
[N1,lval,x,w,gamma] = leg_quad(N);
lp(1,:)=zeros(N+1,1);
lp(2,:)=ones(N+1,1);
for i = 3:N+1
    lp(i,:)=(2*(i-1)-1)*lval(i-1,:)+lp(i-2,:);
end

% for j = 1:N
%     clf
%     plot(x,lp(j,:),'r');
%     hold on
%     plot(x,lval(j,:))
%     grid on
%     pause
%
%
% end

% Lets make a basis
for k=2:N
    phi(k-1,:)=(lval(k+1,:)-lval(k-1,:));
    phiP(k-1,:)=lp(k+1,:)-lp(k-1,:);
end

K=zeros(N-1);
for m = 1:N-1
    for n = 1:N-1
        for i = 1:N+1
            K(m,n)=K(m,n)+phiP(n,i)*phiP(m,i)'*w(i);
        end
    end
end
K
