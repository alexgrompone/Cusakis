



%Inputs

r=0.13;

Xi=[0,0];

Xf=[0.1,-0.1];

D=sqrt((Xf(1)-Xi(1))^2+(Xf(2)-Xi(2))^2);

alpha=asin((Xf(2)-Xi(2))/D);

if Xf(1)>Xi(1) && Xf(2)>Xi(2) 
R=(D/2)*(1/(sin((pi-2*alpha)/2)));
S=(pi-2*alpha)*R;    
    
Sl=(pi-2*alpha)*(R+r);
Sr=(pi-2*alpha)*(R-r);
elseif Xf(1)<Xi(1) && Xf(2)>Xi(2) 
R=(D/2)*(1/(sin((pi-2*alpha)/2)));
S=(pi-2*alpha)*R;    
    
Sl=(pi-2*alpha)*(R-r);
Sr=(pi-2*alpha)*(R+r);
elseif Xf(1)<Xi(1) && Xf(2)<Xi(2)
R=(D/2)*(1/(sin((pi+2*alpha)/2)));
S=(pi+2*alpha)*R;    
    
Sl=-(pi+2*alpha)*(R-r);
Sr=-(pi+2*alpha)*(R+r);  
elseif  Xf(1)>Xi(1) && Xf(2)<Xi(2) 
R=(D/2)*(1/(sin((pi+2*alpha)/2)));
S=(pi+2*alpha)*R;    
    
Sl=-(pi+2*alpha)*(R+r);
Sr=-(pi+2*alpha)*(R-r);   
end
