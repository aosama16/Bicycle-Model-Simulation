![banner](https://user-images.githubusercontent.com/44305804/83749959-d7760d80-a664-11ea-8f44-013e24022554.png)

A simple simulation of the bicycle model using Qt.

## Tools
- Qt Creator 4.8.1
- Qt 5.12.1
- GNU Make 3.82.90

## Steps
1. Defined vehicle paramaters
    1. X position.
    2. Y position.
    3. Wheelbase, which is the distance between the centers of the front and back wheels.
    4. Theta, which is the orientation of the vehicle.
    5. Steering angle.
    6. Velocity, which in this project is set as a constant number.
2. Implemented WASD Controls
    - On keypress W -> Set max positive velocity to go forward.
    - On keypress S -> Set max negative velocity to go backward.
    - On keypress A -> Set max positive steering angle to go left.
    - On keypress D -> Set max negative steering angle to go right.
    - On Keyrelease W or S -> Reset the velocity to zero.
    - On Keyrelease A or D -> Reset the Steerng angle to zero.
3. Update X position, Y position and theta every 20 msec based on vehicle paramaters set by the keyboard inputs.
    - Delta(X) = Velocity * cos(Theta).
    - Delta(Y) = Velocity * sin(Theta).
    - Delta(Theta) = (Velocity / Wheelbase) * tan(Steering angle).
    - Set the new paramater to old paramaters + deltas.
