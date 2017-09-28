function interpolateNewtonAndPlot(a, b, size)

% 1 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('x'); 
ylabel('y'); 
hold on; 
grid on; 

% 2 Печатаем узловые точки:
X = linspace(a, b, size + 1);
Y = f(X); 
plot (X, Y, 'ro');

% 3 Печатаем график полинома Ньютона:
XX = linspace(a, b, 1000);
LX = XX;
for i = 1:1:length(XX)
    LX(i) = interpNewton(X, Y, XX(i));
end
plot(XX, LX, 'b');

% 4 Печатаем график функции:
X = XX;
Y = f(X);
plot(X, Y, 'r--');

% 5 Подписываем легенду
title('Полиномиальная интерполяция', 'FontName', 'Courier');
h1 = legend('Узловые точки', 'Полином Ньютона', 'Функция');
set(h1, 'FontName', 'Courier');

% 6 Выставляем более-менее приемлемый масштаб:
axis([a b min(Y)-0.2 max(Y)+0.2]) 

end