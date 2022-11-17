function [I,exitFlag] = E_Trapez(fun,a,b,m_max,N0, e)

    if(nargin < 6)
        e = 1.e-10;
    end
    if(nargin < 5)
        N0 = ceil((b-a)/0.1);
    end
    if(nargin < 4)
        m_max = 6;
    end

    exitFlag = 0;
    m = 2;
    F = max([fun(a),fun(b)]);

    h(1) = (b-a) / N0;
    for i = 1 : m+1
          
        T(i,1) = h(i)*(fun(a)/2 + fun(b)/2);
        j = 1;
        while(a + j * h(i) <= b)
            f = fun(a + (j * h(i)));
            F = max([F,f]);
            T(i,1) = T(i,1) + (h(i) * f);
            j = j+1;
        end
        h(i+1) = h(1) / (i+1);
    end
    i = 2;
 

    while(i <= m+1)
        for k = 2 : i
            T(i,k) = T(i,k-1) + (T(i,k-1) - T(i-1,k-1))/((h(i-k + 1)/h(i))^2 -1);
        end
        i = i+1;
    end

    for k = 1 : i-1
       if(abs(T(i-1,k) - T(i-2,k)) <= (e * abs(b-a) * F))
            I = T(i-1,k);
            return
       end
    end

    while(m <= m_max) 

        for k = 1 : i
            if(k == 1)
                h(i) = h(i-2)/2;
                T(i,k) = h(i)*(fun(a)/2 + fun(b)/2);
                j = 1;
                while(a + j * h(i) <= b)
                    f = fun(a+ j*h(i));
                    F = max([F,f]);
                    T(i,k) = T(i,k) + h(i) * f;
                    j = j+1;
                end
            else
                T(i,k) = T(i,k-1) + (T(i,k-1) - T(i-1,k-1))/((h(i-k + 1)/h(i))^2 -1);
                if(abs(T(i,k) - T(i-1,k)) <= (e * abs(b-a) * F))
                    I = T(i,k);
                    return
                end
            end
        end
        
        m = m+1;
        i = i+1;
    end


    exitFlag = 1;
    I = T(i-1,i-1);
end

