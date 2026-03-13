# Домашняя работа 2. Задание 1. Вариант 8
# Уравнение: x⁴ − x³ − 2x² + 3x − 3 = 0
# Метод: половинное деление (бисекция)
# Точность: 0.001

import numpy as np
import matplotlib.pyplot as plt


def f(x):
    return x**4 - x**3 - 2*x**2 + 3*x - 3


def bisection(a, b, eps=0.001, max_iter=60):
    if f(a) * f(b) >= 0:
        return None

    while (b - a) > 2*eps and max_iter > 0:
        max_iter -= 1
        c = (a + b) / 2
        fc = f(c)
        if abs(fc) < 1e-10:
            return c
        if f(a) * fc < 0:
            b = c
        else:
            a = c

    return (a + b) / 2


# основная часть
print("Задание 1, вариант 8")
print("Уравнение: x⁴ − x³ − 2x² + 3x − 3 = 0\n")

intervals = [
    (-2.0, -1.0),   # левый корень
    (1.0, 2.0)      # правый корень
]

roots = []
for a, b in intervals:
    root = bisection(a, b)
    if root is not None:
        roots.append(root)

print("Найденные корни с точностью 0.001:")
for i, r in enumerate(roots, 1):
    print(f"   x{i} ≈ {r:.6f}")

print("\nИнтервалы локализации корней:")
print(f"   1) [{intervals[0][0]:.1f}, {intervals[0][1]:.1f}] → x ≈ {roots[0]:.6f}")
print(f"   2) [{intervals[1][0]:.1f}, {intervals[1][1]:.1f}] → x ≈ {roots[1]:.6f}")



# График

x = np.linspace(-3.0, 3.0, 1200)
y = f(x)

plt.figure(figsize=(10, 6))
plt.plot(x, y, color='royalblue', linewidth=2.2,
         label=r'$f(x) = x^4 - x^3 - 2x^2 + 3x - 3$')

plt.axhline(0, color='black', lw=0.7, alpha=0.6)
plt.axvline(0, color='black', lw=0.7, alpha=0.6)

for r in roots:
    plt.plot(r, 0, 'ro', markersize=9, markeredgecolor='darkred',
             label=f'корень ≈ {r:.3f}' if r == roots[0] else "")

plt.grid(True, linestyle='--', alpha=0.4)
plt.title("График функции и найденные корни (метод бисекции)", fontsize=13)
plt.xlabel("x", fontsize=11)
plt.ylabel("f(x)", fontsize=11)
plt.ylim(-9, 15)
plt.xlim(-2.5, 2.5)
plt.legend(loc='upper right')
plt.tight_layout()
plt.show()
