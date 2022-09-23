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
    
CLEAR:  Clears the communicaion window.

SEND: Sends out a slash (/) followed by any text you entered (manually) into the communicaton windowd.

Clock:  Hold for 2 seconds to begin sending out the clocking sequence once per second.

    /#1[cr]
    
    Keeps sending out until Clock is hit again.
    
    This can be used by your project to take some action like keep track of time or to send out a stream of data readings.
    
    
INIT: Sends out the initialization request sequence: / * 1 [cr].
    
    This command is sent out automatically when the app starts.  It is used to tell your device  to send out Title and Button legends as shown below.

You may do whatever you want with this data in your project just as is.  However, you can also send data back to the app as follows...

T,[title text string][cr]
    Puts the text string in the Title Box near the top of the screen.  This lets you know what project you are connected to.  Example...
    
    T,My New Project[cr]
    
B,[button number],string1,string2,etc.
    This puts new legends on your buttons starting at 'button number'.  You can load all of the buttons at once if you wish...
    
    Load all 12 legends: B,1,FIRST,SECOND,...,Last one[cr]
    Re-legend buttons 5 and 6: B,5,but5,but6[cr]
    Re-legend only button 10: B,10,XYZ[cr]
    
    
Dn,[any text][cr] - where n=1-4. Puts text into one of 4 data windows. You can put any type of data you want but it must be as text. For example -

    D1,125 Volts[cr]
    D3,*error*[cr]
    D4,Zzzzz[cr]



    
    
    
    




