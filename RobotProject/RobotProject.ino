//ARDUINO robot with omni wheels
//Joshua Rowan
//Oscar P
//

const int MA1 = 2; //intializing the pins for motor control. 
const int MA2 = 3; //pins are slightly out of order due to the ordering and rearrangement of the 
const int MB1 = 8; // robots direction
const int MB2 = 9;
const int MC1 = 6;
const int MC2 = 7;
const int MD1 = 4;
const int MD2 = 5;



void setup() {
  pinMode(MA1,OUTPUT);// setting up the pins on the arduino nano
  pinMode(MA2,OUTPUT);

  pinMode(MB1,OUTPUT);
  pinMode(MB2,OUTPUT);

  pinMode(MC1,OUTPUT);
  pinMode(MC2,OUTPUT);

  pinMode(MD1,OUTPUT);
  pinMode(MD2,OUTPUT);
 
  Serial.begin(9600); //bluetooth module uses the standard Serial connection
 


}

//function Master is used as an easy way to to decide what the wheels should be set to at a given moment. 
// when integers a-h are set to 1, they turn the wheels on and 0 for off.
void Master(int a,int b,int c,int d,int e,int f,int g,int h){ 
  
  digitalWrite(MA1,a);
  digitalWrite(MA2,b);
  digitalWrite(MB1,c);
  digitalWrite(MB2,d);
  digitalWrite(MC1,e);
  digitalWrite(MC2,f);
  digitalWrite(MD1,g);
  digitalWrite(MD2,h);
}


//function to test the ouput of the arduino board and show and test the wheels
//system cycles each wheel from A through D, forward first then backwards.
//there is a longer delay at the end of the cycle to show end of cycle
void CycleTest(){
  delay(1000);
  Master(1,0,0,0,0,0,0,0);

  delay(1000);
  Master(0,1,0,0,0,0,0,0);

  delay(1000);
  Master(0,0,1,0,0,0,0,0);

  delay(1000);
  Master(0,0,0,1,0,0,0,0);

  delay(1000);
  Master(0,0,0,0,1,0,0,0);

  delay(1000);
  Master(0,0,0,0,0,1,0,0);

  delay(1000);
  Master(0,0,0,0,0,0,1,0);
  
  delay(1000);
  Master(0,0,0,0,0,0,0,1);

  delay(1000);
  Master(0,0,0,0,0,0,0,0);

  delay(3000); //delay at the end to show end of cycle

}
//DemoMode is a function designed to showcase the robots capabilities. Not currently used in the programming, but can be used still.
void DemoMode(){ 
   Forward();
   delay(500);
   Allstop();
   delay(500);
   
   Backward();
   delay(500);
   Allstop();
   delay(500);
   
   StrafeLeft();
   delay(500);
   Allstop();
   delay(500);
   
   StrafeRight();
   delay(500);
   
   SpinClock();
   delay(500);
   Allstop();
   delay(500);
   
   SpinCounterClock();
   delay(500);
   Allstop();
   delay(500);

   Diag1();
   delay(500);
   Diag2();
   delay(500);
   Diag3();
   delay(500);
   Diag4();
   delay(500);
   Allstop();

   
   
}

// this set of functions is used to make directional movement more obvious in the digital envrionment. 
//diagonals start at 45 degrees right from straight and are 90 degrees separate going clockwise
void Allstop(){
  Master(0,0,0,0,0,0,0,0);
}

void Forward(){
  Master(1,0,0,0,0,1,0,0);
}

void Backward(){
  Master(0,1,0,0,1,0,0,0);
}

void StrafeLeft(){
  Master(0,0,0,1,0,0,1,0);
}
void StrafeRight(){
  Master(0,0,1,0,0,0,0,1);
}

void SpinClock(){
  Master(1,0,1,0,1,0,1,0);
  
}

void SpinCounterClock(){
  Master(0,1,0,1,0,1,0,1);
}
void Diag1(){
  Master(1,0,1,0,0,1,0,1);
}
void Diag2(){
  Master(0,1,1,0,1,0,0,1);
}
void Diag3(){
  Master(0,1,0,1,1,0,1,0);
}
void Diag4(){
  Master(1,0,0,1,0,1,1,0);
}
// END OF COMMANDS

// CommandDecider pulls in a single char and calls the function it needs. Default is stop, 0 is stop. 
//remote is designed to send a constant 0 if it is not given another direction.
void CommandDecider(char i){
 switch(i){
    case '1':
      Forward();
      break;
    case '2':
      Diag1();
      break;
    case '3':
      StrafeRight();
      break;
    case '4':
      Diag2();
      break;
    case '5':
      Backward();
      break;
    case '6':
      Diag3();
      break;
    case '7':
      StrafeLeft();
      break;
    case '8':
      Diag4();
      break;
    case '9':
      SpinClock();
      break;
    case 'a':
      SpinCounterClock();
      break;
    case 'd':
      DemoMode();
      break;
    case '0':
      Allstop();
      break;
    default:
      Allstop();
      break;
   }
   
}


char ic = '0'; //ic for incoming, stores the data received via bluetooth

void loop() {

 //primary command set. Receives data and moves arduino.
   if (Serial.available()>0){
    ic = Serial.read();
    //Serial.print(ic);
    //Serial.print(" <- Serial\n");
    CommandDecider(ic);
   }

}
