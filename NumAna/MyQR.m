function [B,Q,R] = MyQR(A,k)
%MYQR Summary of this function goes here
%   Detailed explanation goes here
    s = size(A,1);
    for i = 1: k
        [Q,R] = qr(A);


        
        A = R*Q;
        
    end
    B = A;
end

