# Program:-
# Function to join (merge) two sorted lists
def merge(list1, list2):
    result = []  # final sorted list
    i = 0  # pointer for left list
    j = 0  # pointer for right list

    # Pick smaller element from both lists
    while i < len(list1) and j < len(list2):
        if list1[i]['delivery_time'] < list2[j]['delivery_time']:
            result.append(list1[i])
            i = i + 1
        else:
            result.append(list2[j])
            j = j + 1

    # Add any left items from list1
    while i < len(list1):
        result.append(list1[i])
        i = i + 1

    # Add any left items from list2
    while j < len(list2):
        result.append(list2[j])
        j = j + 1

    return result


# Function to apply merge sort
def merge_sort(orders):
    # If list has 0 or 1 order, no need to sort
    if len(orders) <= 1:
        return orders

    # Find middle point
    mid = len(orders) // 2

    # Split into left and right
    left = orders[:mid]
    right = orders[mid:]

    # Recursive call to the left and right separately
    left_sorted = merge_sort(left)
    right_sorted = merge_sort(right)

    # Merge both sorted halves
    return merge(left_sorted, right_sorted)


# ----------------------- MAIN PROGRAM -----------------------
orders = []  # list to store all orders

# Take input from user
n = int(input("How many orders? "))

for i in range(n):
    order_id = input("Enter Order ID: ")
    time = int(input("Enter delivery time (minutes): "))
    orders.append({'order_id': order_id, 'delivery_time': time})

# Sort using merge sort
sorted_orders = merge_sort(orders)

# Show result
print("\nOrders sorted by delivery time:")

for order in sorted_orders:
    print(order['order_id'], "->", order['delivery_time'], "minutes")
