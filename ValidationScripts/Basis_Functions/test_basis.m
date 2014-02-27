ccc
% problem 2
part = 1;
N=16;
N2=100;
n=20;
switch part
    case 1
        x=linspace(-1,1,N+1);
        u=1./(1+16*x.^2);
        [L, Lp] = leg_poly(x,n);
        
        plot(x,L,'LineWidth',2)
        iFontSize=20;
        strFontName='Times';
        strFontUnit='points';
        strInterpreter='latex';
        strFontWeight='light';
        fLineWidth=1.5;
        TickLength=[0.01 0.01];
        xlabel('$x$','Interpreter','latex','FontSize',iFontSize,'FontName',strFontName,'FontWeight',strFontWeight);
        ylabel('$L(x)$','Interpreter','latex','FontSize',iFontSize,'FontName',strFontName,'FontWeight',strFontWeight,'Rotation',0);
        set(gca,'TickLength',TickLength,'FontName',strFontName,'FontSize',iFontSize-4,'FontWeight',strFontWeight);
        set(gca,'LineWidth',fLineWidth);
        saveas(gcf,'legendre_poly.pdf')
    case 2
        
        x_e=linspace(-1,1,N);
        u_m=1./(1+16*x_e.^2);
        [p_e]=lagrange_interp(x_e,u_m);
        x_e=linspace(-1,1,N2);
        u_e=polyval(p_e,x_e);
        % legendre
        [x_L,wt] = qlgl(N);
        u_L=1./(1+16*x_L.^2);
        [p_L]=lagrange_interp(x_L',u_L');
        [x_L,wt] = qlgl(N2);
        u_L=polyval(p_L,x_L);
        %
        % Base
        x=linspace(-1,1,400);
        u=1./(1+16*x.^2);
        %
        plot(x_e,u_e,'r','LineWidth',4)
        hold on
        plot(x_L,u_L,'b','LineWidth',3)
        plot(x,u,'g','LineWidth',2)
        iFontSize=20;
        strFontName='Times';
        strFontUnit='points';
        strInterpreter='latex';
        strFontWeight='light';
        fLineWidth=1.5;
        TickLength=[0.01 0.01];
        xlim([-1 1])
        xlabel('$x$','Interpreter','latex','FontSize',iFontSize,'FontName',strFontName,'FontWeight',strFontWeight);
        ylabel('$u(x)$','Interpreter','latex','FontSize',iFontSize,'FontName',strFontName,'FontWeight',strFontWeight,'Rotation',0);
        set(gca,'TickLength',TickLength,'FontName',strFontName,'FontSize',iFontSize-4,'FontWeight',strFontWeight);
        set(gca,'LineWidth',fLineWidth);
        c=legend('Equal grid','Gauss Lobatto','Ideal');
        legend('boxoff','on')
        set(c,'Position',[0.25 0.6 0.15 0.2])
        set(c,'FontSize',iFontSize,'FontName',strFontName,'FontWeight',strFontWeight)
%         saveas(gcf,'problem_2.pdf')
end