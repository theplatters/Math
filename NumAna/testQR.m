A = diag([1,2,3,4,5,6]);
A = A + diag([2,3,2,4,2],1);
A = Transf(A);

B = MyQR(A,100)

A = diag([1,1+1i,1-1i,4,5,6]);
A = A + diag([2,4,2,1,2],1);
A = Transf(A);

B = MyQR(A,1000)

%doens´t converge :(%

A = diag([1,1,1,2,2,3]);
A = A + diag([2,2,2,9,2],1);
A = Transf(A);

B = MyQR(A,40000)


