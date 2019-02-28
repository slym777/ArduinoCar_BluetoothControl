#define REMOTEXY_MODE__SOFTWARESERIAL
#include <SoftwareSerial.h>             //Including the software serial library
#include <RemoteXY.h>                   //Including the remotexy library

/* RemoteXY connection settings */
#define REMOTEXY_SERIAL_RX 0            //defining the pin 2 as RX pin
#define REMOTEXY_SERIAL_TX 1            //defining the pin 3 as TX pin
#define REMOTEXY_SERIAL_SPEED 9600      //setting baudrate at 9600

unsigned char RemoteXY_CONF[] =
  { 3,0,23,0,1,5,5,15,41,11 
  ,43,43,1,2,0,6,5,27,11,5 
  ,79,78,0,79,70,70,0};

struct {                            //Function for declaring the variables
  signed char x_axis;         //joystick x-axis
  signed char y_axis;         //joystick y-axis
  unsigned char switch_button;           //variables for switch
  unsigned char connect_flag;
} RemoteXY;

//defining the pins for first motor
#define IN1 3
#define IN2 4
#define ENA 5

//defining the pins for second motor
#define IN3 7
#define IN4 8
#define ENB 6
#define blue 10
#define red 9


//defining the LED pin
#define ledpin 13
#define buzzer 11

unsigned char first_motor[3] =
  {IN1, IN2, ENA};
unsigned char second_motor[3] =
  {IN3, IN4, ENB};

long int time_now = 0;
int period = 250;
bool color_flag = true;

void Speed (unsigned char * pointer, int motor_speed)
{
  if (motor_speed>100) 
    motor_speed=100;
  if (motor_speed<-100) 
    motor_speed=-100;
  if (motor_speed>0) {
    digitalWrite(pointer[0], HIGH);
    digitalWrite(pointer[1], LOW);
    analogWrite(pointer[2], motor_speed*2.55);
  }
  else if (motor_speed<0) {
    digitalWrite(pointer[0], LOW);
    digitalWrite(pointer[1], HIGH);
    analogWrite(pointer[2], (-motor_speed)*2.55);
  }
  else {
    digitalWrite(pointer[0], LOW);
    digitalWrite(pointer[1], LOW);
    analogWrite(pointer[2], 0);
  }
}

void setup()
{
  //defining the motor pins as the output pins
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ledpin, OUTPUT);
  pinMode (blue, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (buzzer,OUTPUT);
  RemoteXY_Init ();
}

void loop()
{
  RemoteXY_Handler ();
  
  digitalWrite(ledpin, (RemoteXY.switch_button == 0)?LOW:HIGH);
  if(RemoteXY.switch_button != 0)
  {
     if(millis() >+ time_now + period){
        time_now = millis();
        digitalWrite(red, color_flag);
        digitalWrite(blue, !color_flag); 
        color_flag = !color_flag;
     }
  }
  else 
  {
    time_now = millis();
    period = 250;
    color_flag = true;
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }
  Speed(first_motor, RemoteXY.y_axis - RemoteXY.x_axis);
  Speed(second_motor, RemoteXY.y_axis + RemoteXY.x_axis);
}
