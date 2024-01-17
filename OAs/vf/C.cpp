class Solution:
        def transformArray(self, arr: List[int]) -> List[int]:
change = True

while change:
left = arr[0]
change = False

for i in range(1, len(arr) - 1):
temp_left = left
left = arr[i]

if arr[i] > temp_left and arr[i] > arr[i + 1]:
change = True
arr[i] -= 1

elif arr[i] < temp_left and arr[i] < arr[i + 1]:
change = True
arr[i] += 1

return arr
