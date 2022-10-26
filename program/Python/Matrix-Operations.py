def createMatrix():
  matrix = []
 
  ms=int(input("Enter no. of matrices to create: "))
 
  for i in range(ms):
    print("\nMatrix %i"%(i+1))
    r=int(input("\tEnter no. of rows: "))
    c=int(input("\tEnter no. of columns: "))
 
    m=[]
    b=[]
 
    for i in range(r):
      for j in range(c):
        v= int(input("\tEnter value for row "+str(i)+" column "+str(j)+": "))
        b.append(v)
      m.append(b)
      b=[]
   
    matrix.append(m)
 
  return matrix
 
matrix = createMatrix()
    

m1 = matrix[0]
m2 = matrix[1]
print(m1)
print(m2)

def display1(m1):
    print("Matrix 1 is : ")
    for i in m1:
        print()
        for j in i:
            
            
            print(j,end="  ")
display1(m1)
def display2(m2):
    print("\nMatrix 2 is : ")
    for a in m2:
        print()
        for b in a:
            
            
            print( b,end="  ")

display2(m2)
c=[]






#SUM

for i in range(len(m1)):
  if (len(m1) != len(m2)) or (len(m1[i]) != len(m2[i])):
    print("Not possible")
    break
  list=[]
  for j in range(len(m1[i])):
    c.append(m1[i][j]+m2[i][j])
    
nrow =[c[0],c[1]]
ncol =[c[2],c[3]]
list.append(nrow)
list.append(ncol)


print("\n\nSum Of the matrix is : ")


for sum in list:
    print()
    for p in sum:    
        print( p,end="  ")

def multiply(m1,m2):
    if len(m1[1]) != len(m2[0]):
        print("multiplication is not possible")
    else:    
    
        result = [[0,0],[0,0]]

        for q in range(len(m1)):
        
            
            for w in range(len(m2[0])):
        
                
                for e in range(len(m2)):
                    result[q][w] += m1[q][e] * m2[e][w]


    mul = []
    for r in result:
        
        mul.append(r)
    return mul

print('\n\nMultiplication of matrices is :')
for pro in multiply(m1,m2):
    print()
    for z in pro:    
        print( z,end="  ")

        
        


def transpose(matrix):
    rows = len(matrix)
    columns = len(matrix[0])

    matrix_T = []
    for j in range(columns):
        row = []
        for i in range(rows):
           row.append(matrix[i][j])
        matrix_T.append(row)

    return matrix_T


print("\n\nTranspose of matrix 1 : ")

for t1 in transpose(m1):
    print()
    for trans1 in t1:    
        print( trans1,end="  ")


print("\n\nTranspose of matrix 2 : ")

for t2 in transpose(m2):
    print()
    for trans2 in t2:    
        print( trans2,end="  ")
