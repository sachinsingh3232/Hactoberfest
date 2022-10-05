import csv
def write():
    f=open("Items.csv","w",newline='')
    wobj=csv.writer(f)
    wobj.writerow(["Item_no","Item_name","Qty","Price"])
    rec=[]
    while True:
        Item_no=int(input("Enter Item number:"))
        Item_name=input("Enter item name:")
        Qty=int(input("Enter quantity:"))
        Price=int(input("Enter item price:"))
        k=[Item_no,Item_name,Qty,Price]
        rec.append(k)
        c=input("Do you want to enter more records?(y/n)")
        if (c=="n"):
            break
    wobj.writerows(rec)
    f.close()

def read():
    f=open("Items.csv","r")
    robj=csv.reader(f)
    for i in robj:
        print(i)
    f.close()

def search():
    print("Searching for a particular item.")
    f=open("Items.csv","r")
    robj=csv.reader(f)
    found=0
    srch=input("Enter item number to be searched:")
    for i in robj:
        if (i[0]==srch):
            print("Record found")
            print(i)
            found=1
            break
            
    if (found==0):
        print("Item not found")
    f.close()

write()
read()
search()
