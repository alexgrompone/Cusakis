function [ dec1,dec2 ] = hex2decAG1( u )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
u=200;

if u>0

%decimal to numeric hex vector

A=zeros(4,1);
B=zeros(4,1);
d=u;
i=1;
while d>16
A(i)=rem(d,16);
d=floor(d/16);
i=i+1;
end

A(i)=d; %inverted numeric hex vector
l=size(A);
n=l(1)+1;
 
for z=1:4 
B(z)=A(n-z);
end

%numeric hex vector to 2 decimal values
    
dec1=B(1)*16+B(2);
dec2=B(3)*16+B(4);
else
uneg=u+2^16;
 
A=[];
B=zeros(1,2);
d=uneg;
i=1;
while d>16
A(i)=rem(d,16);
d=floor(d/16);
i=i+1;
end

A(i)=d; %inverted numeric hex vector
l=size(A);
n=l(2);
 
for z=0:n-1 
B(z+1)=A(n-z);
end

%numeric hex vector to 2 decimal values
    
dec1=B(1)*16+B(2);
dec2=B(3)*16+B(4);   
    
end