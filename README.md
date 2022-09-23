# UniCom
Universal bluetooth interface for Arduino projects. Instead of writing apps for each of your bluetooth connected projects, use the same program to control many different projects.  It features...

    A communication window to show both outgoing (RED) and incomming (BLUE) data.
    
    A Title window that can be set by your project.
    
    A slider bar that sends out positional data.
    
    4 Data windows to show data sent from you project.
    
    12 Buttons that can have custom legends controlled by your project.
    
![UniCom 5](https://user-images.githubusercontent.com/46026730/192060404-824c941c-ae6b-4235-98d9-372d9ffe7f43.gif)


This is how the unit looks when connecting to a project.  Once you connect, it can send commands via bluetooth as follows...

All commands have the format: /[character][number][cr]

    / = the forward slash character

    character = any single printable character

    number = 1 to 3 digit ascii decimal (text) number

    [cr] = carriage return (ascii 13) - not newline (ascii 10)



All outgoing commands are shown in RED in the communication window at the top of the screen.

Here are the controls.

Buttons 1-12: Send A thru L as text characters.
    
    Examples...

    Button #1 Down: /A1[cr]

    Button #1 Up:   /A0[cr]

    Button #3 Down: /C1[cr]

Note: holding any button down for over one second will prevent the 'button up' code from being sent.  Your project can use this to 'latch' a function.  The button legend is highlighted in this mode.  Hitting the same button again (for less than one second) sends the normal on/off sequences and un-highlights the button legend.


The SLIDER control sends out values from 0 to 255.

    Slider near middle: /X127[cr]

    Slider at maximum:  /X255[CR]
    
CLEAR:  Clears the communicaion window.

SEND: Sends out a slash (/) followed by any text you entered (manually) into the communicaton windowd.

Clock:  Hold for 2 seconds to begin sending out the clocking sequence once per second.

    /#1[cr]
    
    Keeps sending out until Clock is hit again.

This can be used by your project to take some action like keeping track of time or to send out a stream of data readings.
    
    
INIT: Sends out the initialization request sequence: / * 1 [cr].
    
    This command is sent out automatically when the app starts.
    It is normally used to tell your device to send out Title and Button
    legends as shown below.

            *   *   *   *   *   *   *   *   *   *
            
You may do whatever you want with this data in your project just as is.  However, you can also send data back to the app as follows...

T,[title text string][cr]
    Puts the text string in the Title Box near the top of the screen.
    This lets you know what project you are connected to.
    Example...
    
    T,My New Project[cr]
    
B,[button number],string1,string2,etc[cr]
    This puts new legends on your buttons starting at 'button number'.
    You can load all of the buttons at once if you wish...
    
    Load all 12 legends: B,1,FIRST,SECOND,...,TWELFTH[cr]
    Re-legend buttons 5 and 6: B,5,but5,but6[cr]
    Re-legend only button 10: B,10,XYZ[cr]
    
    
Dn,[any text][cr] - where n=1-4. Puts text into one of 4 data windows. You can put any type of data you want but it must be as text. For example -

    D1,125 Volts[cr]
    D3,*error*[cr]
    D4,Zzzzz[cr]

X,[0-255][cr]

    Set slider position to specifed location.

    
    
    
    




