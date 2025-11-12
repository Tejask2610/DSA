# Taking input from user
text = input("Enter the text: ")
pattern = input("Enter the pattern to search: ")
# Get lengths
n = len(text)
m = len(pattern)
# Flag to check if pattern found
found = False
# Slide the pattern over text
for i in range(n - m + 1):
j = 0
# Check for match
while j < m and text[i + j] == pattern[j]:
j += 1
if j == m:
print("\nPattern found at positions:")
print(f"Pattern found at index {i}")
found = True
if not found:
print("No pattern match found in given string.")
