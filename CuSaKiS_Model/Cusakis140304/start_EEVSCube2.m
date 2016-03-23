% Initialization File
clear all; close all; clc;

dt=0.005; 

%EE
mesh_A1 = [-0.5  0.3  0.3  0.5  0.3  0.3  -0.5  
           0.1  0.1   0.2  0    -0.2  -0.1   -0.1];
mesh_A = [mesh_A1;
          zeros(1,size(mesh_A1,2))];

%Cube
mesh_B1 = [-0.5    0.5    0.5   -0.5; 
            0.5    0.5   -0.5   -0.5];
mesh_B = [mesh_B1;
          zeros(1,size(mesh_B1,2))];  



