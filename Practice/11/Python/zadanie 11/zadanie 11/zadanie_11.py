print ("Этот калькулятор вычисляет степень числа \nВведите число которое нужно возвести в степень:")
a = float(input())
print ("Введите саму степень:")
c = float(input())
e = a
d = 1
if c == 0:
    print("0")
else:
    while (c != d):
        a = (e * a)
        d = (d + 1)
print (a)