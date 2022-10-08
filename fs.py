import csv

print("\n\t\t\t\tWelcome to THE FUNSCOOP IceCream Parlour\n")
print("==================================================================================")

def line():
    print("-----------------------------------------------------------------------------------------------------------------------------------------------------")

print("Hi! I am an IceCream ordering, billing interface and can help you with your delicious IceCream choices!!\n")
line()
while True:
    print("\nHere's what all I can do ~~~>")
    print("    [1] See the IceCream flavours  available along with their prices. (per scoop 70g)")
    print("    [2] Add something to your cart.")
    print("    [3] Delete something from your cart.")
    print("    [4] Check your cart.")
    print("    [5] Buy the items in your cart and get the bill for your purchase.")
    print("    [6] Exit the application.")
    line()    
    task=int(input("So, What do you want to do first?(Enter the serial number for the task you want to perform)"))
    l1=["Mango","50", "Strawberry","50", "Pineapple","80", "Tutty fruity","70", "Oreo","90", "Cookie Crumble","90"]
    if (task==1):
        d1={"Mango             ":"50", "Strawberry":"50", "Pineapple":"80", "Tutty fruity":"70", "Oreo           ":"90", "Cookie Crumble":"90"}
        print("\nITEM\t\t\t\t\tPRICE\n")
        for i in d1:

            print(i+"\t\t\t\t"+d1[i])
        
    if (task==2):
        def write():
            f1=open("cart.csv","w",newline='')
            cwrt=csv.writer(f1)
            cwrt.writerow(["ITEM" , "PRICE"])
            rec=[]
            while True:
                itms=input("Enter flavour to be added:")
                prc=int(input("Enter price for the chosen flavour:"))
                lst1=[itms,prc]
                rec.append(lst1)
                choice=input("Do you want to add more flavours?(yes/no)")
                if (choice=="no"):
                    break
            cwrt.writerows(rec)
            f1.close()
            print("Cart Updated!")
            line()
        #write()
        
    if(task==3):
        def read():
            lst1=[itms,prc]
            f1=open("cart.csv","r")
            cr=csv.reader(f1)
            print("Your cart currently has --->")
            for i in cr:
                print(i)
                
        def search():
            f1=open("cart.csv","r")
            itm=input("Enter flavour to be deleted:")
            fnd=0
            cr=csv.reader(f1)
            for i in cr:
                if (i[0]==itm):
                    lst1.pop(i)
                    fnd=1
                    break

                else:
                    print("Flavour not in cart")
            f1.close()
        read()
        search()
    
    if (task==4):
        def read():
            f1=open("cart.csv","r")
            cr=csv.reader(f1)
            print("Your cart currently has --->")
            for i in cr:
                print(i)
        read()

    if(task==5):
        serc=input("Order type (Take Away or Pick from store)")
        payment=input("How do you want to pay?")
        def transfer():
            f1=open("cart.csv","r",newline='')
            f2=open("bill.csv","w",newline='')
            tr=csv.reader(f1)
            t=csv.writer(f2)
            m=next(tr)
            t.writerow(m)
            t.writerow(["Order type",serc])
            t.writerow(["Payment mode",payment])
            for i in tr:
                t.writerow(i)
                
            f1.close()
            f2.close()
            
        def reading():
            f2=open("bill.csv","r",newline='')
            tr=csv.reader(f1)
            for i in tr:
                print(i)

        transfer()
        reading()


    if (task==6):
        print("Thanks! It was a pleasure serving you!!")
        break

    if (task>6):
        print("Please enter a valid input.")
