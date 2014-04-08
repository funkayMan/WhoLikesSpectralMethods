clear
clc
clf
warning off all

for N=[10];
    N1=N+1;
    
    [phi_eta, D, eta, w,g,lval]=GLL_Basis(N);
    
    a=-1; b=1;
    c=-1; d=1;
    
    x=(b-a)*(eta-1)/2+b;
    y=(d-c)*(eta-1)/2+d;
    J=(b-a)*(d-c)/4;
    %(i
    [xx,yy]=meshgrid(x,y);
    f=(xx).^2.*(yy).^2;
    % surfc(xx,yy,f);
    % figure
    u = zeros(N1*N1,1);
    for i = 1:N1
        for j = 1:N1
            u((i-1)*N1+j)=f(i,j);
        end
    end
    dF=2*yy.^2;
    d2u = zeros(N1*N1,1);
    for i = 1:N1
        for j = 1:N1
            d2u((i-1)*N1+j)=dF(i,j);
        end
    end
    
    
    
    %% Mass Matrix
    M=zeros(N1*N1);
    for m = 1:N1
        for n = 1:N1
            M((m-1)*N1+n,(m-1)*N1+n)=w(m)*w(n);
        end
    end
    M=M*J;
    
    %% the xi part
    K_x=zeros((N+1)^2);
    dd=zeros(N1,1);
    for m = 1:N1
        for n = 1:N1
            for i = 1:N1
                cInd=(n-1)*N1+i;
                rInd=(n-1)*N1+m;                
                K_x(rInd,cInd) = -D(:,i)'*(D(:,n).*w)*w(m);                
            end
        end
    end
    %% Form the matrix, take a peek, and see if it is a solution to our system
    K=(K_x);
    
    %% Test K
    rhs=K*u;
    lhs=M*d2u;
    err=norm(rhs-lhs,Inf);
    subplot(2,1,1)
    spy(K)
%     text(0.1,0.5,['The Error is ' num2str(err) ],'Interpreter','Latex','FontSize',60)
    fprintf('The Error is %6.4f\n',err)
    subplot(2,1,2)
    plot(rhs,'bo-','LineWidth',4,'MarkerSize',10)
    hold on
    % Define an analytic derivative
    
    plot(lhs,'rs-','LineWidth',2)
    H=legend('K*u','M*d2u');
    set(H,'Location','NorthWest');
    grid on
end




%% Old ideas. Mostly junk.
% Swap the last rows of D around to get it to work, only works for
% x^2y^2...
%             if n == N1
%                 dd=-D(1:N,N1);
%                 dd(N1)=D(N1,N1);
%                 K_x(rInd,cInd) = D(:,i)'*(dd.*w)*w(m);
%                 dd
%             end
%             if n == 1
%                 dd(2:N1)=-D(2:N1,1);
%                 dd(1)=D(1,1);
%                 K_x(rInd,cInd) = D(:,i)'*(dd.*w)*w(m);
%                 dd
%             end
%             spy(K_x)
%             pause(0.1);