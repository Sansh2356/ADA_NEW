from math import radians
import numpy as np
import matplotlib.pyplot as plt

values = [
    (3,772),
    (5,7323),
    (7, 321847),
    (9,24059966),
    (11, 3517819827 )

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
