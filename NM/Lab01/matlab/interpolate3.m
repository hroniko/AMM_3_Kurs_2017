function interpolate3(a, b, size)

% 1 Находим коэффициенты полинома Лагранжа:
d = abs(a-b)/size;
X = a:d:b; 
Y = f(X); 
coef = polyfit(X, Y, size);

% 2 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('x'); 
ylabel('y'); 
hold on; 
grid on; 

% 3 Печатаем узловые точки:
plot (X, Y, 'ro');

% Печатаем график полинома Лагранжа:
XX = a:0.01:b;
LX = polyval(coef, XX);
plot(XX, LX, 'b');

% 4 Печатаем график функции:
X = XX;
Y = f(X);
plot(X, Y, 'r--');

% 5 Подписываем легенду
title('Полиномиальная интерполяция', 'FontName', 'Courier');
h1 = legend('Узловые точки', 'Интерполяция', 'Функция');
set(h1, 'FontName', 'Courier');

% 6 Выставляем более-менее приемлемый масштаб:
axis([a b min(Y)-0.2 max(Y)+0.2]) 

end