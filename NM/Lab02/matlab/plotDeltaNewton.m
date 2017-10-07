function plotDeltaNewton(a, b, size1, size2)

color = ['b'; 'g'; 'r']; % Матрица цветов

% 1 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('Степень полинома Ньютона, n'); 
ylabel('Средняя абсолютная погрешность'); 
grid on; hold on;

for number = 1:3 % Для все трех способов расчета
    N = size1 : size2;
    E = N * 0; % Создаем матрицу ошибок
    k = 1;
    for n = size1 : size2
        [D, X] = coefPolyNewtonBase(a, b, n, number);
        % Считаем значения X и Y в равноотстоящих точках на отрезке [a, b] 
        X1 = linspace(a, b, 10000); % 10000 узловых точек
        Y1 = f(X);

        % Считаем значения полинома в этих 10000 точках:
        Y2 = Y1 * 0;
        for i = 1:1:length(X1)
            Y2(i) = pointNewton(D, X, X1(i));
        end

        % Считаем значения ошибок
        E(k) = deltaNewton(Y1, Y2);
        k = k+1;    
    end

    % 3 Печатаем график:
    plot (N, E, color(number));
end


% 5 Подписываем легенду
title('Полиномиальная интерполяция', 'FontName', 'Courier');
h1 = legend('для полинома Ньютона №1', 'для полинома Ньютона №2', 'для полинома Ньютона №3');
set(h1, 'FontName', 'Courier');
% 6 Выставляем более-менее приемлемый масштаб:
axis([size1 size2 0 3]) % axis([size1 size2 0-2 3+2]) 

end