import matplotlib.pyplot as plt

values = [
    (18,6221318),
(19,2812452),
(20,10571623),
(21,27133626),
(22,49885788),
(23,110367291),
(24,232394370)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()