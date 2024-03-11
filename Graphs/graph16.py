import matplotlib.pyplot as plt

# Data from the C++ program (input size vs execution time in seconds)
input_sizes = [1000, 5000, 10000, 50000, 100000]
execution_times = [0.000273, 0.001751, 0.004481, 0.042268, 0.141558]  # Replace with your actual data

# Convert times to nanoseconds for better readability
execution_times_ns = [time * 1e9 for time in execution_times]

# Plotting the graph
plt.plot(input_sizes, execution_times_ns, marker='o', linestyle='-', color='b')
plt.title('Input Size vs Execution Time (Iterative QuickSort)')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.grid(True)
plt.show()