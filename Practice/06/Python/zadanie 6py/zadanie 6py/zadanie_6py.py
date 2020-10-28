import math
  
print ("Введите значение a: ")
a = int(input())
print ("Введите значение b: ")
b = int(input())
print ("Введите значение c: ")
c = int(input())

if a == 0:
 if b == 0:
  if c == 0:
   print ("Бесконечно корней \(º □ º *)/")

if a == 0:
 if b != 0:
  if c == 0:        
   print ("Решений нет")
                
if a == 0:
 if b == 0:
  if c != 0:
   print ("Решений нет")

if a == 0:
 if b != 0:
  if c != 0:
   x = (b / -c)
   print ("x1 = ", x )

if (b * b - 4 * a * c) > 0:
  if a != 0:
   x = (-1 * b + math.sqrt(b * b - 4 * a * c)) / (2 * a)
   print ("x1 = ", x )
   x = (-1 * b - math.sqrt(b * b - 4 * a * c)) / (2 * a)
   print ("x2 = ", x )

if ((b * b - 4 * a * c) == 0):
 if (a != 0):
  x = (b * b - 4 * a * c)
  print ("x1 = ", x )

if ((b * b - 4 * a * c) < 0):
 if (a != 0):
  print ("Решения нет ")
