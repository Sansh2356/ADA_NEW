import matplotlib.pyplot as plt

values = [
    (1000000,1621300),
    (1500000, 3539600),
    (2000000, 3340500),
    (2500000,4778800),
    (3000000, 5626300),
    (3500000,6389800),
    (4000000,6254900),
    (4500000,7175600),
    (5000000,9147300)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()