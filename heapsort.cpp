# Heap Sort in Python
def heapify(arr, n, i):
largest = i # Initialize largest as root
left = 2 * i + 1 # Left child index
right = 2 * i + 2 # Right child index
# If left child exists and is greater than root
if left < n and arr[left] > arr[largest]:
largest = left
# If right child exists and is greater than largest so far
if right < n and arr[right] > arr[largest]:
largest = right
# If largest is not root
if largest != i:
arr[i], arr[largest] = arr[largest], arr[i] # Swap
# Recursively heapify the affected subtree
heapify(arr, n, largest)
def heap_sort(arr):
n = len(arr)
# Build a maxheap
for i in range(n // 2 - 1, -1, -1):
heapify(arr, n, i)
# Extract elements from heap one by one
for i in range(n - 1, 0, -1):
arr[0], arr[i] = arr[i], arr[0] # Swap root with the last element
heapify(arr, i, 0)
# Example usage
arr = [12, 11, 13, 5, 6, 7]
print("Original array:", arr)
heap_sort(arr)
print("Sorted array:", arr)
