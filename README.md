#Point Charge Electric Field Simulator
This simulation shows the magnitude and direction of the electric field all
around a fixed -1 coulomb point charge and a moving +1 coulomb point charge.
This is only a proof of concept and I plan on adding a proper user interface
soon.

##Running
Clone the repository:
`git clone https://github.com/kylecs/Point-Charge-Electric-Field-Simulator`

Compile and run:
'make'

##Demo
*Click to play*

[![Demo Video HERE](https://img.youtube.com/vi/XSmAxIcmJ8Y/0.jpg)](https://youtu.be/XSmAxIcmJ8Y)

##Physics / Math

The fixed blue charge is -1 C, while the mobile red charge is +1 C. The electric
field is calculated with the formula `E = kQ / r`, and some trigonometry is
used to get an angle and scale the electric field in the proper direction.
