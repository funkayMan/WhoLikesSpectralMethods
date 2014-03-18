ccc

N=5;






% K_el=zeros(N1);
% for m=1:N1
%     M_el(m,m)=w(m);
%     for n=1:N1
%         el=0;
%         for k=1:N1
%             el=el+D(n,k)*D(m,k)*w(k);
%         end
%         K_el(m,n)=el;
%     end
% end
% 
% % The Assembly
% Nel=3;
% K=zeros((Nel)*(ii)-Nel+1);
% for j = 1:Nel
%     for m=1:ii;
%         row=(ii-1)*(j-1)+m;
%         for n = 1:ii;
%             col=(ii-1)*(j-1)+n;
%             K(row,col)=K_el(m,n)+K(row,col);
%         end
%     end
% end
% 
% 
% loc=zeros(length(K),1);
% M=zeros(size(K));
% for j = 1:Nel
%     for ind = 1:N1
%         i=ind+N1*(j-1)-1*(j-1);
%         i_old=N1*(j-1)-j+2;
%         if j==1
%             loc(i)=-x(ind)+1;
%             M(i,i)=w(ind);
%         else
%             M(i,i)=w(ind);
%             loc(ind+N1*(j-1)-1*(j-1))=-x(ind)+1+loc(i_old);
%         end            
%     end
% end
% 
% 
% 
% 
% u=zeros(size(x));
% u(3)=1;
% % a = 
% % for i = 1:N1;
% % 
% A=M_el\K_el;
% T=0.02;
% dt=0.001;
% t=0:dt:T;
% 
% figure
% NNN=length(t);
% for i=1:NNN
%     clf
%     plot(x,u(:,i),'LineWidth',2)
%     u(:,i+1)=u(:,i)+dt*A*u(:,i);
%     u(1,end)=0;
%     u(1,1)=0;
%     pause(0.1)
% end
    