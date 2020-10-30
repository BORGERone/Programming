x = 0;
print ("Введите целое число:")
a = int(input())

if a >= 1:
 x += 1

while a > 1:
 a //= 2
 x += 1
print (x)
