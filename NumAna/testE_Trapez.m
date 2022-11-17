%tests%

[I,e] = E_Trapez(@(x) sqrt(abs(x)), -1.25, 1)

fprintf("diverges, let´s try increasing number of steps \n");

[I,e] = E_Trapez(@(x) sqrt(abs(x)), -1.25, 1,12)

fprintf("still not better, let´s try a bigger N0 and a smaller eps \n");

[I,e] = E_Trapez(@(x) sqrt(abs(x)), -1.25, 1, 20, 100, 1.e-6)

fprintf("finally, now with sinus \n");

[I,e] = E_Trapez(@sin,0,pi, 20, 100)

fprintf("that worked, now with the last function \n")

[I,e] = E_Trapez(@(x) exp(x) - x^2/2,1.1,3.7)

fprintf("maybe a little bit more steps and a bigger N0")

[I,e] = E_Trapez(@(x) exp(x) - x^2/2,1.1,3.7,20, 300)

fprintf("okay, we are not getting there, but we are close, but still, here are three more functions \n");

fprintf("1/x: ")
[I,e] = E_Trapez(@(x) 1/x, 0.5, 1.5,15,100)

fprintf("log x: ")
[I,e] = E_Trapez(@log,1, 10, 20, 100, 1.e-6)

fprintf("tanh x:")

[I,e] = E_Trapez(@tanh, 0, pi, 20, 100)

%Conclusio: The method works, but for it to be exact it needs a lot of processing power%

