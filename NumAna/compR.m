function [R] = compR(B,D,p,k)

R=triu(B(:,p));
R=full(spdiags(D,0,R));
%R=R(:,pt);


end
