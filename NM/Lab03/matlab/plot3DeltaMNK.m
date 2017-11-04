function plot3DeltaMNK(a, b, n_start, n_end , N_start, N_end, typeMNK, typeQuadra)

% Формируем сетку (плоскость независимых переменных)
[n, N] = meshgrid(n_start:1:n_end, N_start:1:N_end);

% Формируем заготовку для матрицы ошибок, покрывающей сетку
E = n + N;


% Считаем значения X и Y в равноотстоящих точках на отрезке [a, b] 
X1 = linspace(a, b, 10000); % 10000 узловых точек (a, b, 10000)
Y1 = f(X1);

for i = 1:size(E, 2) %
    nn = n(1, i);
    for j = 1 : size(E, 1) %
        
        NN = N(j, 1);
        try
            C = coefMNKBase(-1, 2, nn, NN, typeMNK, typeQuadra);
            % Считаем значения полинома в этих 10000 точках:
            Y2 = Y1 * 0;
            for k = 1:length(X1)
                Y2(k) = pointMNK(C, X1(k));
            end

            % Считаем значения ошибок
            E(j, i) = deltaMNK(Y1, Y2);
        catch ME
            
            E(j, i) = E(j-1, i-1);
        end
        

    end    
end

figure; 
xlabel('Степень полинома, n'); 
ylabel('Число узловых точек, N'); 
zlabel('Абсолютная погрешность'); 
grid on; hold on;

surf(n, N, E) % Строим график

% 5 Подписываем легенду
title('Зависимость точности аппроксимации МНК от n и N', 'FontName', 'Courier');

end