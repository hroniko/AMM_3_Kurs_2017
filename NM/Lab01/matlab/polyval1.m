function Lf = polyval1(X, Y, xx)
% Первый метод вычисления значения интерполяционного многочлена в точке с
% использованием многчлена Лагранжа (в одном цикле и умножение, и деление)
sum = 0.0;
for i = 1:1:size(X, 2)
    pp = Y(i);
    for j = 1:1:size(X, 2)
        if (i ~= j )
            pp = pp * (xx - X(j))/(X(i)-X(j));
        end
    end
    sum = sum + pp;
end

Lf = sum;
end