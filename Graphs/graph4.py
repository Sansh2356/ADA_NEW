import matplotlib.pyplot as plt

values = [
    (10,0),
    (13, 0),
    (16, 1076300),
    (19,4862400),
    (22, 40249500)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()