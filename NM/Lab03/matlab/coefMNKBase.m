function cc = coefMNKBase(a, b, n, N, typeMNK, typeQuadra)
% Интерфейсная функция для вызова всех других функций
% a - начало отрезка
% b - конец отрезка
% n - степень полинома
% N - количество точек разбиения
% typeMNK - тип МНК, 1 - непрерывный, 2 - дискретный, 3 - полудискретный 
% typeQuadra (только для 3 типа МНК) - тип квадратурной формулы, 1 -
% трапеций, 2 - Симпсона

if (typeMNK == 1) % Если непрерывный способ, то
    cc = coefMNKSolid(a, b, n); % вычисляем
end
if (typeMNK == 2) % Если дискретный способ, то
    % Считаем значения X и Y в равноотстоящих точках на отрезке [a, b] 
    X = linspace(a, b, N+1); % N+1 узловых точек
    Y = f(X);
    cc = coefMNKDiscrete(X, Y, n); % вычисляем
end
if (typeMNK == 3) % Если полудискретный способ, то
    % Считаем значения X и Y в равноотстоящих точках на отрезке [a, b] 
    X = linspace(a, b, N+1); % N+1 узловых точек
    Y = f(X);
    cc = coefMNKQuasiDiscrete(X, Y, n, typeQuadra); % вычисляем
end
% Во всех остальных случаях вернем как по первому случаю
if (typeMNK < 1)
    cc = coefMNKSolid(a, b, n); % вычисляем
end
if (typeMNK > 3)
    cc = coefMNKSolid(a, b, n); % вычисляем
end

end