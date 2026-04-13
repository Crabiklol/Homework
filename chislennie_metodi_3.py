# Лабораторная работа №3
# Задание 3.1 Вариант 8
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


#Домашняя работа 3
#Решение систем линейных уравнений приближёнными методами. 
#Метод простой итерации, метод Зейделя.
#Каждый студент выполняет работу в соответствии со своим вариантом. Вариант определяется порядковым номером студента в списке группы.
#Задание 2 Вариант 5
#Преобразовав систему линейных уравнений к виду, удобному для итераций, решить ее методом Зейделя с точностью ε=0.001.
import numpy as np
import math


def seidel(A, b, eps=0.001):
    n = len(A)
    x = np.zeros(n)  # Начальное приближение [0, 0, 0]
    iterations = 0

    while True:
        x_prev = np.copy(x)
        for i in range(n):
            # Используем уже обновленные значения x_j для j < i

            s1 = sum(A[i][j] * x[j] for j in range(i))
            s2 = sum(A[i][j] * x_prev[j] for j in range(i + 1, n))

            x[i] = (b[i] - s1 - s2) / A[i][i]

        iterations += 1

        # проверкаусловия выхода: если максимальная разница между старым и новым x меньше eps...
        if np.linalg.norm(x - x_prev, ord=np.inf) < eps:
            break

    return x, iterations


# Коэффициенты преобразованной системы
A = (np.array
([
    [4.5, -2.1, 3.2],
    [2.5, 5.8, -0.5],
    [0.9, 2.7, -3.8]
]))
b = np.array([-1.2, 3.5, 2.4])

sol, iters = seidel(A, b)
print(f"Результат:")
print(f" x1= {sol[0]:.3f},")
print(f" x2= {sol[1]:.3f},")
print(f" x3= {sol[2]:.3f}")
print(f"Итераций: {iters}")



# 1. Получаем решение из нашей функции (из предыдущего шага)
sol, iters = seidel(A, b)

# 2. Умножаем матрицу A на полученный вектор x
# np.dot — это матричное умножение
check_b = np.dot(A, sol)

print("--- Проверка системы ---")
for i in range(len(b)):
    # Выводим: (результат подстановки) ≈ (исходное значение b)
    print(f"Уравнение {i+1}: {check_b[i]:.4f} ≈ {b[i]}")

# 3. Вычисляем невязку (разницу между левой и правой частью)
residual = np.linalg.norm(check_b - b)
print(f"\nОбщая погрешность (невязка): {residual:.6f}")


