import random

def wins(comp ,you):
    if comp==you:
       return None
    elif comp=="r":
        if you=='p':
           return True
        else:
            return False
    elif comp=="p":
        if you=='s':
           return True
        else:
           return False

    elif comp=="s":
        if you=='r':
           return True
        else:
            return False

print("computer is selecting Rock(r) Paper(p) scissors(s)......")
ran=random.randint(1,3)
if ran==1:
    comp ='r'
elif ran==2:
    comp='p'
elif ran==3:
    comp ='s'

you=input("your's turn select any one  Rock(r) Paper(p) scissors(s)...")
winer=wins(comp,you)
print("Computer's Choice is "+comp)
print("your Choice is " + you)
if winer==None:
    print("The match is tied.")
elif winer:
    print("You Won.")
else:
    print("You Lost.")


