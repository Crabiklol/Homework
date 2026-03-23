import math

def f(x):
    return math.sin(x) - x + 3

def g(x):
    return math.sin(x) + 3

# Метод дихотомии
def bisection_method(a, b, tol=1e-2):
    if f(a) * f(b) > 0:
        print("На данном интервале нет корня")
        return None
    while (b - a) / 2 > tol:
        c = (a + b) / 2
        fc = f(c)
        if fc == 0:
            return c
        elif f(a) * fc < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

# Метод итераций
def iteration_method(x0, tol=1e-3, max_iter=1000):
    x_old = x0
    for i in range(max_iter): #цикл итераций
        x_new = g(x_old) #новое приближение корня по формуле
        if abs(x_new - x_old) < tol: #если значение между новым и старым значением меньше точности возвращаем найденное приближение
            return x_new
        x_old = x_new # обновление текущее приблежение корня
    print("Метод итераций не сошелся") # вывод
    return x_old #возврат значения

# Локализация корня
# У меня во время локализации корней уравнения получается 1 корень , так как на графике , на оси х идет 1 пресечение
a, b = 3, 4  # как нашли выше

#точночти для методов
root_bisect = bisection_method(a, b, tol=1e-2)
root_iter = iteration_method(root_bisect, tol=1e-3)  # стартуем с приближенного корня

# вывод в консоль
print(f"Корень методом дихотомии с точностью 1e-2: {root_bisect:.4f}")
print(f"Корень методом итераций с точностью 1e-3: {root_iter:.6f}")
