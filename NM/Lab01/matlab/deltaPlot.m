function deltaPlot(a, b, size1, size2)

X = size1:1:size2;
Y= X * 0;
for i = 1:1:size(X, 2)
    Y(i) = delta(a,b,X(i));
end

% 2 Создаем новое окно для графика и подписываем оси
figure; 
xlabel('Степень полинома Лагранжа, n'); 
ylabel('Абсолютная погрешность'); 
grid on; hold on;

% 3 Печатаем узловые точки:
plot (X, Y, 'b');

% 5 Подписываем
title('Погрешность интерполяции', 'FontName', 'Courier');

% 6 Выставляем более-менее приемлемый масштаб:
axis([size1 size2 0-2 60+2]) 

end