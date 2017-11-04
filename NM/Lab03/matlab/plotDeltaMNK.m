function plotDeltaMNK(a, b, N, size_start, size_end, typeQuadra)

color = ['b'; 'g'; 'r']; % Матрица цветов

% 1 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('Степень аппроксимирующего полинома, n'); 
ylabel('Средняя абсолютная погрешность'); 
grid on; hold on;

NN = N;
for typeMNK = 1:3 % Для все трех способов расчета
    EN = size_start : size_end;    
    E = EN * 0; % Создаем матрицу ошибок
    k = 1;
    for n = size_start : size_end
        try
            C = coefMNKBase(a, b, n, NN, typeMNK, typeQuadra);
            % Считаем значения X и Y в равноотстоящих точках на отрезке [a, b] 
            X1 = linspace(a, b, 10000); % 10000 узловых точек
            Y1 = f(X1);

            % Считаем значения полинома в этих 10000 точках:
            Y2 = Y1 * 0;
            for i = 1:length(X1)
                Y2(i) = pointMNK(C, X1(i));
            end

            % Считаем значения ошибок
            E(k) = deltaMNK(Y1, Y2);
        
        catch ME
            E(k) = E(k-1);
        end
            

        k = k+1;    
    end

    % 3 Печатаем график:
    plot (EN, E, color(typeMNK));
end


% 5 Подписываем легенду
title('Точность аппроксимации МНК', 'FontName', 'Courier');
h1 = legend('для полинома №1 (непрерывн.)', 'для полинома №2 (дискретн.)', 'для полинома №3 (полудискр.)');
set(h1, 'FontName', 'Courier');
% 6 Выставляем более-менее приемлемый масштаб:
% axis([size1 size2 0 3]) % axis([size1 size2 0-2 3+2]) 

end