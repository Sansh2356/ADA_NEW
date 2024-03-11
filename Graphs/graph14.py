import matplotlib.pyplot as plt

# Data from the C++ program (input size vs execution time in seconds)
input_sizes = [10, 20, 30, 40, 50]
execution_times = [2.1e-05, 1.7e-05, 2.4e-05, 2.6e-05, 4.6e-05]  # Replace with your actual data

# Convert execution times to nanoseconds for better readability
execution_times_ns = [time * 1e9 for time in execution_times]

# Plotting the graph
plt.plot(input_sizes, execution_times_ns, marker='o', linestyle='-', color='b')
plt.title('Input Size vs Execution Time')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.grid(True)
plt.show()