import matplotlib.pyplot as plt

values = [
(3,00 ),
(5,00 ),
(7,00 ),
  (9,10 ),
   (11,20 ),
    (13,20 ),
     (15,30 ),
      
]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()