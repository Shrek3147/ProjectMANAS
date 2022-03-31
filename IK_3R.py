import math
import matplotlib.pyplot as plt
from numpy import *
a1 = 2
a2 = 2
a3 = 2
pos_x = 4
pos_y = 2
phi= 90

phi = deg2rad(phi)
wx =  pos_x - a3*math.cos(phi)
wy = pos_y -a3*math.sin(phi)
c2 = (wx*wx + wy*wy -a1*a1 - a2*a2)/(2*a1*a2) 
print(c2)


s2_1 = math.sqrt(1- c2*c2)
    

theta2_1 = math.atan2(s2_1, c2)#angle of 2nd angle by 1st method

denom_1 = a1*a1 + a2*a2 +2*a1*a2*math.cos(theta2_1)# denominator created for the calculation of the theta 1
s1_1 =(wy*(a1 + a2*math.cos(theta2_1)) - a2*math.sin(theta2_1)*wx)/denom_1# finding the sin of theta1 of 1st method 

c1_1 = (wx*(a1+a2*math.cos(theta2_1)) + a2*math.sin(theta2_1)*wy)/denom_1# finding the cos of theta1 of 1st method 
    
theta1_1 = math.atan2(s1_1, c1_1) #first solution

theta3_1 = phi - theta1_1 - theta2_1 #calulting the angle of theta3 by first method




ax_1 = a1*math.cos(theta1_1)
ay_1 = a1*math.sin(theta1_1)
ax_2 = ax_1 + a2*math.cos(theta2_1)
ay_2 = ay_1 + a2*math.sin(theta2_1)
ax_3 = pos_x
ay_3 = pos_y
print (ax_1,ay_1,ax_2,ay_2,ax_3,ay_3)

x_coord = [0,ax_1,ax_2,ax_3]
y_coord = [0,ay_1,ay_2,ay_3]
plt.xlim(-5,5)
plt.ylim(-5,5)
plt.plot(x_coord, y_coord, label = "first method" )
plt.plot
plt.xlabel("x coordinates")
plt.ylabel("y coordinates")
plt.title(" 3R planar simulator")
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
