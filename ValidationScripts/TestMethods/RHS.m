function [du]=RHS(u)
global K M
du=M\K*u;