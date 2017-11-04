function plotMNK(a, b, n, N, typeMNK, typeQuadra)
% Основная функция, вычисляет коэффициенты аппроксимирующего полинома по одному из
% методов рассчета и строит сравнительные графики для исходной функции и
% аппроксимирующего полинома, с нанесением узловых точек

% 1 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('x'); 
ylabel('y'); 
hold on; 
grid on; 

% 2 Вычисляем коэффициенты аппроксимирующего полинома и узловые точки через базовую
% функцию:

C = coefMNKBase(a, b, n, N, typeMNK, typeQuadra);

% 3 Печатаем узловые точки:
X = linspace(a, b, N+1); % N+1 узловых точек
Y = f(X);
plot (X, Y, 'ro');

% 3 Печатаем график аппроксимирующего полинома:
XX = linspace(a, b, 10000);
LX = XX * 0;
for i = 1:length(XX)
    LX(i) = pointMNK(C, XX(i));
end
plot(XX, LX, 'b');

% 4 Печатаем график функции:
X = XX;
Y = f(X);
plot(X, Y, 'r--');

% 5 Подписываем легенду
title('Аппроксимация методом наименьших квадратов (МНК)', 'FontName', 'Courier');
name = strcat('Аппроксимирующий полином');
h1 = legend('Узловые точки', 'Аппроксимирующий полином', 'Функция');
set(h1, 'FontName', 'Courier');

% 6 Выставляем более-менее приемлемый масштаб:
axis([a b min(Y)-0.2 max(Y)+0.2]) 

end