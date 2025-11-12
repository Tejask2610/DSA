Program:-
# Fractional Knapsack Problem 
def fractional_knapsack(weights, profits, capacity): 
    n = len(weights) 
    ratio = [(profits[i] / weights[i], weights[i], profits[i]) for i in range(n)] 

    # Sort by profit-to-weight ratio (descending) 
    ratio.sort(reverse=True, key=lambda x: x[0]) 

    total_profit = 0 
    remaining_capacity = capacity 

    print("\nSelected Parcels:") 
    for r, w, p in ratio: 
        if remaining_capacity >= w: 
            remaining_capacity -= w 
            total_profit += p 
            print(f"Weight: {w}, Profit: {p}, Taken: 100%") 
        else: 
            # Take fractional part 
            fraction = remaining_capacity / w 
            total_profit += p * fraction 
            print(f"Weight: {w}, Profit: {p}, Taken: {fraction * 100:.2f}%") 
            break  # Truck is full

    return total_profit 


# --- User Input ---
n = int(input("Enter number of parcels: "))

weights = []
profits = []

for i in range(n):
    weights.append(float(input(f"Enter weight of parcel {i+1}: ")))
    profits.append(float(input(f"Enter profit of parcel {i+1}: ")))

capacity = float(input("Enter truck capacity: "))

# --- Calculate Maximum Profit ---
max_profit = fractional_knapsack(weights, profits, capacity)

print(f"\nMaximum Profit = {max_profit:.2f}")


Output:-
Enter number of parcels: 3
Enter weight of parcel 1: 10
Enter profit of parcel 1: 60
Enter weight of parcel 2: 20
Enter profit of parcel 2: 100
Enter weight of parcel 3: 30
Enter profit of parcel 3: 120
Enter truck capacity: 50

Selected Parcels:
Weight: 10.0, Profit: 60.0, Taken: 100%
Weight: 20.0, Profit: 100.0, Taken: 100%
Weight: 30.0, Profit: 120.0, Taken: 66.67%

Maximum Profit = 240.00

