n = int(input("Enter no of rows"))

for i in range(1,n+1):
  j = i
  print(" "*(n-i+1),end="")
  while j>=1:
    print(j,end=" ")
    j-=1
  print()
