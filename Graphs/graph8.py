import matplotlib.pyplot as plt

values = [
    (100000, 400100),
 (120000, 799900),
  (140000, 700400),
  (160000, 699500),
  (180000, 900300),
  (200000, 1103200),
  (220000, 1201400),
  (240000, 1100600),
   (260000, 1401600),
  (280000, 1699600),
  (300000, 1500200),
  (320000, 1899700),
  (340000, 1798900),
  (360000, 1899700),
  (380000, 1899500),
  (400000, 2099700),
  (420000, 2302200),
  (440000, 2300400),
  (460000, 2800400),
   (480000, 3199800),
  (500000, 3397200)
  ]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()