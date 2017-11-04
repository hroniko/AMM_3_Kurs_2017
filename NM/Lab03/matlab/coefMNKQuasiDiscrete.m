function cc = coefMNKQuasiDiscrete(X, Y, n, typeQuadra)
% Полудискретный метод вычисления коэфиициентов аппроксимирующего полинома
% X - матрица узловых точек (иксы)
% Y - матрица узловых точек (игреки)
% n - желаемая степень аппроксимирующего полинома
% N - вытаскиваем из размерности X
% type - тип квадратурной формулы для приближенного вычисления интеграла,
% если 1, то по формуле трапеций, если 2 - то по формуле Симпсона

N = length(X); % Количество узловых точек
syms x; %Определение символьной переменной

c = sym('c', [1 n]); % Определяем массив символьных переменных с1, ..., сn

% 1 Собираем матрицу уравнений:
u = sym('u', [1 n]); % Определяем массив символьных переменных u1, ..., un
% Для каждой символьной переменной формируем содержимое:
for k = 1:n % от u1 до u(n-1)
    % 1.1 Считаем левую сумму (как в дискретном варианте):
    summ_L = 0;
    % Организуем цикл по переменным ci
    for i = 1:n % от c1 до c(n-1)
        % 1.1 Для каждой переменной ci организуем цикл по фj (считаем <фi,фk>):
        for j = 1:N
           summ_L = summ_L + ( X(j)^(i-1) ) * ( X(j)^(k-1) ) * c(i);
        end
    end
    % 1.2 Нормируем
    summ_L = 1/N * summ_L;
    
    % 1.3 Считаем правую сумму:
    summ_R = 0;
    if (typeQuadra == 1) % считаем по формуле трапеций  
        % 1.3.1 Собираем полудискретную сумму методом трапеций
        for i = 1:N-1
            summ_R = summ_R + ( Y(i) * X(i)^(k-1) + Y(i+1) * X(i+1)^(k-1) ) * (X(i+1)-X(i))/2; 
        end
        % 1.3.2 Нормируем
        summ_R = 1/(X(N)-X(1)) * summ_R; 
    end
    if (typeQuadra == 2) % считаем по формуле Симпсона  
        % 1.3.3 Собираем полудискретную сумму методом трапеций
        for i = 1:N-1
            summ_R = summ_R + ( Y(i) * X(i)^(k-1) + 4 * f( (X(i)+X(i+1))/2 ) * ((X(i)+X(i+1))/2)^(k-1) + Y(i+1) * X(i+1)^(k-1) ) * (X(i+1)-X(i))/6;
        end
        % 1.3.4 Нормируем
        summ_R = 1/(X(N)-X(1)) * summ_R; 
    end

    
    % 1.5 Вычитаем из левой суммы правую и окончательно формируем уравнение:
    summ = summ_L - summ_R;  
    % 1.6 Переводим к символьному виду и записываем в соответсвующий 
    % элемент символьной матрицы уравнений
    u(k) = sym(summ);  
end
    
% 2 Символьно решаем систему линейных алгебраических уравнений
c = solve (u);
% c.c1
% c.c2

% 3 Получаем массив строк с именами всех полей структуры "c":
cname = fieldnames(c);

% 4 Получаем содержимое каждого поля структуры, обращаясь по имени поля, и
% конвертируем в double, сохраняя в итоговый массив
for i = 1:n % от c1 до сn-1
    %getfield(S, 'field') — возвращает содержимое поля структуры S, что эквивалентно S. field;
    cname_cell = cname(i);
    cc(i) = double(getfield(c, cname_cell{1})); % Фигурные скобки для обращения к содержимому ячейки
end

end