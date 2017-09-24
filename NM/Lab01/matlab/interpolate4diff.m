function interpolate4diff(a, b, size)

% 1 Находим коэффициенты полинома Лагранжа:
d = abs(a-b)/size;
X = a:d:b; 
Y = f(X); 

% 2 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('x'); 
ylabel('y'); 
hold on; 
grid on; 

% 3 Печатаем узловые точки:
plot (X, Y, 'ro');

% Печатаем график полинома Лагранжа (первый способ):
XX = a:0.01:b;
LX = XX * 0;
for i = 1:1:length(XX)
    LX(i) = polyval1(X, Y, XX(i));
end
plot(XX, LX, 'b');

% Печатаем график полинома Лагранжа (второй способ):
XX = a:0.01:b;
LX = XX * 0;
for i = 1:1:length(XX)
    LX(i) = polyval2(X, Y, XX(i));
end
plot(XX, LX, 'g');

% 4 Печатаем график функции:
X = XX;
Y = f(X);
plot(X, Y, 'r--');

% 5 Подписываем легенду
title('Полиномиальная интерполяция', 'FontName', 'Courier');
h1 = legend('Узловые точки','Интерполяция 1','Интерполяция 2','Функция');
set(h1, 'FontName', 'Courier');

% 6 Выставляем более-менее приемлемый масштаб:
axis([a b min(Y)-0.2 max(Y)+0.2]) 

end