import matplotlib.pyplot as plt

values = [
    (1000, 0),
    (3000, 4),
    (5000, 10),
    (7000,17),
    (9000, 29),
    (11000, 43),
    (13000,63),
    (15000,80),
    (17000,103),
    (19000,133)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('Seconds')
plt.title('Inputs Vs Time Graph')

plt.show()