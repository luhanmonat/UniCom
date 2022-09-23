# UniCom
Universal (?) bluetooth interface for Arduino projects.

Use the same program to control many different projects.

![UniCom1a](https://user-images.githubusercontent.com/46026730/191946727-d62cf5e2-7418-49cc-b4e3-b1366e27de0b.jpg)

This is how the unit looks before connecting to your project.  Once you connect, it can send commands via bluetooth as follows...

All commands have the format: /[character][number][cr]

/ = the forward slash character

character = any single printable character

number = 1 to 3 digit ascii decimal (text) number

[cr] = carriage return (ascii 13) not newline (ascii 10)



All outgoing commands are shown in RED in the communication window at the top of the screen.

Here are the controls.

Buttons 1-12: Send A thru L as text characters. Here are some examples.

Button #1 Down: /A1[cr]

Button #1 Up:   /A0[cr]

Button #3 Down: /C1[cr]



The SLIDER control sends out values from 0 to 255.

Slider near middle: /X127[cr]

Slider at maximum:  /X255[CR]





