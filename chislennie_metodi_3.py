# Лабораторная работа №3
# Задание 3.1
#Метод: простая итерация , метод Зейделя

# ___
# |x_1 = 0.17x_2 - 0.31x_3 + 0.16x_4 - 1.2x
# |x_2 = 0.18x_2 + 0.43x_3 - 0.08x_4 + 0.38
# |x_3 = 0.22x_1 + 0.18x_2 + 0.25x_3 + 0.07x_4 + 0.48
# |x_4 = 0.08x_1 + 0.07x_2 + 0.71x_3 + 0.04x_4 - 1.24
# ---
import math
import numpy as np
import matplotlib.pyplot as plt

# Задаём функции для обновления переменных
def iterate(x):
    x1 = 0.17*x[1] - 0.31*x[2] + 0.16*x[3] - 1.2
    x2 = 0.18*x[1] + 0.43*x[2] - 0.08*x[3] + 0.38
    x3 = 0.22*x[0] + 0.18*x[1] + 0.25*x[2] + 0.07*x[3] + 0.48
    x4 = 0.08*x[0] + 0.07*x[1] + 0.71*x[2] + 0.04*x[3] - 1.24
    return np.array([x1, x2, x3, x4])

def simple_iteration(epsilon=0.001, max_iterations=1000):
    x_old = np.zeros(4)  # начальное приближение [0,0,0,0]
    for iteration in range(max_iterations):
        x_new = iterate(x_old)
        # Проверяем критерий остановки по норме разности
        if np.linalg.norm(x_new - x_old, ord=np.inf) < epsilon:
            print(f'Решение достигнуто за {iteration+1} итераций')
            return x_new
        x_old = x_new
    print("Достигнут максимум итераций, решение не сошлось")
    return x_old

# Запускаем метод
solution = simple_iteration()
print("Приближенное решение:")
for i, val in enumerate(solution, start=1):
    print(f"x{i} = {val:.5f}")
