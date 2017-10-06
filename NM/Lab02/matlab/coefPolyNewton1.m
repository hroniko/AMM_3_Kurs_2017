function D = coefPolyNewton1(X, Y)
% Функция для вычисления коэффициентов полинома Ньютона методом решения n+1
% линейных алгебраических уравнений

D = X * 0;
n = length(X); % Количество узловых точек

for i = 1 : n % внешний цикл по D "слева"
    chislitel = Y(i);
    for j = 1 : i-1 % Вложенный цикл по D "справа"
        pp = D(j);
        for k = 1 : j-1 % Внутренний цикл по Х
            pp = pp * (X(i) - X(k));            
        end
        chislitel = chislitel - pp;
    end
    % К этому моменту мы посчитали числитель, пора и за знаменатель взяться
    znamenatel = 1;
    for j = 1 : i-1
        znamenatel = znamenatel * (X(i) - X(j));        
    end
    % Посчитали знаменатель, делим одно на другое и сохраняем коэффициент в
    % матрицу коэффициентов D:
    D(i) = chislitel / znamenatel;     
end

end