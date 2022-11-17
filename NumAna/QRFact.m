function [A,D,p,k] = QRFact(A)

[m,n]=size(A);
n_=n;
D = zeros([min(m,n),1]);

p=1:n;

for j=n:-1:1
    sigma_(j) = dot(A(:,j),A(:,j));
    sigma(j) = sigma_(j);
    if sigma(j)==0
        temp=p(j);
        p(j) = p(n_);
        p(n_)=temp;
        n_= n_-1;
    end
end

for j=1:n_
   

   
   piv = j-1;
   val=-1;
   for l=j:n_
       div=sigma(p(l))/sigma_(p(l));
       
       if div>val
           val=div;
           piv=l;
       end
   end
   
   if piv < j
       k=j-1;
       return;
   end
   
   temp=p(j);
   p(j)=p(piv);
   p(piv)=temp;
   
   
   sigma(p(j)) = dot(A(j:m,p(j)),A(j:m,p(j)));
   
   if sigma(p(j))<m*eps^2 * sigma_(p(j))
       k=j-1;
       return;
   end
   
   D(j)= - sign(A(j,p(j)))*sqrt(sigma(p(j)));
   A(j,p(j))= A(j,p(j))-D(j); 
   
   for i=j+1:n_
       gamma = dot(A(j:m,p(i)),A(j:m,p(j)))/(-D(j)*A(j,p(j)));
       A(j:m,p(i))=A(j:m,p(i))-gamma*A(j:m,p(j));
       sigma(p(i))=sigma(p(i))-(A(j,p(i)))^2;
       if sigma(p(i))<m*eps*sigma_(p(i))
           sigma(p(i))=dot(A(j+1:m,p(i)),A(j+1:m,p(i)));
       end       
   end   
end
k=n_;   
    
end
