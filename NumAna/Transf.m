

function B = Transf (A)
  s = size(A,1);
  
  v1=2*rand(s,1)-ones(s,1);
  v2=2*rand(s,1)-ones(s,1);
  v3=2*rand(s,1)-ones(s,1);
  
  P1 = eye(s) - (2 * (v1 * v1') /(norm(v1)^2));
  P2 = eye(s) - (2 * (v2 * v2')/(norm(v2)^2));
  P3 = eye(s) - (2 * (v3 * v3')/(norm(v3)^2));
  P = P1 * P2 * P3;
  B = P.' * A * P;
end
