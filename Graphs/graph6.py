import matplotlib.pyplot as plt

values = [
(1000, 3812),

(3000, 16874),
(4000, 21663),
(5000, 30111),
(6000, 35862),
 (7000, 34181),
(8000, 38398),
(9000, 38409),
(10000, 42505)
]



comparison_values = [
(1000, 1200),
(2000, 6800),
(3000, 73000),
(4000, 73000),
(5000, 78000),
(6000, 78000),
(7000, 85000),
(8000, 77000),
(9000, 77000),
(10000, 78000)

]

x_values, y_values = zip(*values)

x_comparison, y_comparison = zip(*comparison_values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.plot(x_comparison, y_comparison, marker='s', linestyle='--', color='r', label='Comparison Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()