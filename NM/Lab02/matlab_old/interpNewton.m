function y0 = interpNewton(X, Y, xx)
% Вычисление полинома Ньютона в точке xx.
n = length(X); % Количество узловых точек
A(1) = Y(1);
for k = 1 : n - 1
   D(k, 1) = (Y(k+1) - Y(k))/(X(k+1) - X(k));
end
for j = 2 : n - 1
   for k = 1 : n - j
      D(k, j) = (D(k+1, j - 1) - D(k, j - 1))/(X(k+j) - X(k));
   end
end
%D
for j = 2 : n
   A(j) = D(1, j-1);
end
Df(1) = 1;
C(1) = A(1);
for j = 2 : n
   Df(j)=(xx - X(j-1)) .* Df(j-1);
   C(j) = A(j) .* Df(j);
end
y0 = sum(C);

end