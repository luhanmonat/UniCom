/*
 * Simple test program to light LED's using UniCom app
 * 
 * All incoming comands have  the format:
 *    /   forward slash
 *    c   a single printable character
 *    n   1 to 5 digit ascii decimal number
 *    \r  the RETURN character (ascii 13)
 *    
 * All outgoing comands must be ascii text strings
 * and end with RETURN ('\r') --- NOT Newline ('\n')
 * 
 */


#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX,TX to HC-06

#define LED1  4
#define LED2  5
#define LED3  6

int   onoff=0;
int   counter=0;
int   clock=0;

void setup() {

  mySerial.begin(9600);
  mySerial.print("T,Test Program\r");
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  analogWrite(LED3,100);

}

void loop() {
char  sync,cmd;
int   val;


  sync=GetChar();        
  if(sync!='/')
    return;               // must have '/' character first
  cmd=GetChar();          // now get the command character
  val=GetDecimal();       // get the command value
                          // val=1 for key down, val=0 for key up

  switch(cmd) {

    case '*': mySerial.print("T,UniCom Test Program\r");    // * is init command
              mySerial.print("B,1,LED1,LED2,Count\r");
              break;
    
    case 'A': if(val) digitalWrite(LED1,HIGH);    // key down = turn on
              else    digitalWrite(LED1,LOW);     // key up = turn off
              break;
        
    case 'B': if(val)           // val=1 is key down
                onoff^=1;       // toggle on/off only on key down
              if(onoff) digitalWrite(LED2,HIGH);
              else      digitalWrite(LED2,LOW);
              break;
              
    case 'X': analogWrite(LED3,val);    // Set PWM value (0-255)
              break;

    case 'C': if(val) {           // count on key down only
                mySerial.print("D1,Count=");
                mySerial.print(counter++);
                mySerial.print('\r');
              } break;

    case '#': clock++;                // if clock is active
              mySerial.print("D2,");  // count seconds
              mySerial.print(clock);
              mySerial.print(" Seconds\r");
              break;
  
  }
}

//  Converts incoming text data to numeric value

int GetDecimal() {
int   val;
char  c;

  val=0;
nxt:
  c=GetChar();
  if(isdigit(c)) {
    val*=10;
    val+=c-'0';
  } else {
    return(val);
  }
  goto nxt;
  
}

//  Waits for next incoming char

char  GetChar() {
char  data;
  
  while(!mySerial.available())      // wait for data
    ;
  data=mySerial.read();             // read data and return
  return(data);
}
