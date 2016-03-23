%%%% load variables
 count=1;
for i=1:20:length(A)
    figure(1)
     clf
     hold on
      
      kmax=size(Q1,2)-1;
  
       plot(Q1(i,1),Q1(i,2),'r*') %%point on
       plot(Q2(i,1),Q2(i,2),'r*')
       %sensor plot
       plot(si_a(i,1),si_a(i,2),'b*')
       plot(si_b(i,1),si_b(i,2),'b*')
       
       plot(Xcmc_k(i,1),Xcmc_k(i,2),'g*')
   
        line([Q1(i,1) Q2(i,1)],[Q1(i,2) Q2(i,2)],'Color',[.6 .6 .6])
        
       % line([-5 5],[-5 -5])

        jmax=size(A,2);
      
      for j=1:2:jmax-3
      line([A(i,j) A(i,j+2)],[A(i,j+1) A(i,j+3)])
      end
      
      jmax=size(B,2);
%      
      for j=1:2:jmax-3
      line([B(i,j) B(i,j+2)],[B(i,j+1) B(i,j+3)])
      end
      
      xlabel('X')%,'Interpreter','Latex')
      ylabel('Y')%,'Interpreter','Latex')
      axis([-5 8 -2 2])
      axis equal
      drawnow;
       M(count)=getframe;
      count=count+1;
end

%movie2avi(M,'docking.avi','compression','Cinepak');


