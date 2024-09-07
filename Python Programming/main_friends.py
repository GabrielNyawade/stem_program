from friends import *

def print_friend(friend):
  print("{} is a {} year old {} and likes {} color" 
        .format(friend.name, friend.age, friend.gender, friend.fav_color))
  
f_1 = Friends("Francis", 23, "Male", "Yellow")
f_2 = Friends("Patience", 21, "Female", "Green")
f_3 = Friends("Imelda", 19, "Female", "Lilac")


f_1.set_name("Francisca")
f_1.set_gender("Female")

print_friend(f_1)
print_friend(f_2)
print_friend(f_3)
