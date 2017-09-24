function Lf = polyval2(X, Y, xx)
% Второй метод вычисления значения интерполяционного многочлена в точке с
% использованием многчлена Лагранжа (в одном цикле умножение, а в другом -
% деление)
sum = 0.0;
for i = 1:1:size(X, 2)
    pp = Y(i); % Числитель
    for j = 1:1:size(X, 2)
        if (i ~= j )
            pp = pp * (xx - X(j));
        end
    end
    pd = 1.0; % Значенатель
    for j = 1:1:size(X, 2)
        if (i ~= j )
            pd = pd * (X(i)-X(j));
        end
    end
    sum = sum + pp/pd;
end

Lf = sum;
end