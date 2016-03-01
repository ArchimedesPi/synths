import math

sine = [round(127 * math.sin(((2*3.14159)/256) * i)) for i in range(0, 256)]

print(sine)
