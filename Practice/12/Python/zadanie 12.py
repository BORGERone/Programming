print("¬ведите число дл€ расчЄта факториала")

a = int(input())
b = 1

for i in range(2, a + 1):
    b *= i

print(b)