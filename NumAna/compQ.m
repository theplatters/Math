
function [Q] = compQ(B,p,k)
[m,~]=size(B);
Q=eye(m);

for j=1:k
    
    v=zeros(m,1);
    if(j>1)
        v(1:j-1)=0;
    end
    v(j:m)=B(j:m,p(j));

    P=eye(m)-(2/dot(v,v))*(v*transpose(v));
    Q=Q*P;
end
end
