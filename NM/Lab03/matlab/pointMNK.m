function p = pointMNK(C, xx)
% Функция рассчета значения аппроксимирующего полинома в точке xx
% На вход получает матрицу коэффициентов C, матрицу узловых точек X и
% значение xx, для которого надо посчитать P(xx)

n = length(C); % Количество узловых точек
p = C(1); % Начальное значение полинома в точке

for i = 2 : n % Внешний цикл по коэффициентам C(i)
    p = p + C(i)*xx^(i-1);    
end


end