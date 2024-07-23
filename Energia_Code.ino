#define IR_SENSOR_LANE_1A PB_2
#define IR_SENSOR_LANE_1B PF_3
#define TRAFFICL1RED PE_3
#define TRAFFICL1YEL PE_2
#define TRAFFICL1GRE PE_1
#define IR_SENSOR_LANE_2A PD_3
#define IR_SENSOR_LANE_2B PF_2
#define TRAFFICL2RED PA_2
#define TRAFFICL2YEL PA_3
#define TRAFFICL2GRE PA_4
#define IR_SENSOR_LANE_3A PD_2
#define IR_SENSOR_LANE_3B PF_1
#define TRAFFICL3RED PB_6
#define TRAFFICL3YEL PB_7
#define TRAFFICL3GRE PF_0
byte seven_segment_digits[10][7] = { { 0,0,0,0,0,0,1 }, // display '0'
                                     { 1,0,0,1,1,1,1 }, // display '1'
                                     { 0,0,1,0,0,1,0 }, // display '2'
                                     { 0,0,0,0,1,1,0 }, // display '3'
                                     { 1,0,0,1,1,0,0 }, // display '4'
                                     { 0,1,0,0,1,0,0 }, // display '5'
                                     { 0,1,0,0,0,0,0 }, // display '6'
                                     { 0,0,0,1,1,1,1 }, // display '7'
                                     { 0,0,0,0,0,0,0 }, // display '8'
                                     { 0,0,0,1,1,0,0 }  // display '9'
                                   };
void setup() {
  Serial.begin(9600);
  pinMode(TRAFFICL2RED, OUTPUT);
  pinMode(TRAFFICL2YEL, OUTPUT);
  pinMode(TRAFFICL2GRE, OUTPUT);
  pinMode(IR_SENSOR_LANE_2A, INPUT);
  pinMode(IR_SENSOR_LANE_2B, INPUT);
  pinMode(TRAFFICL3RED, OUTPUT);
  pinMode(TRAFFICL3YEL, OUTPUT);
  pinMode(TRAFFICL3GRE, OUTPUT);
  pinMode(IR_SENSOR_LANE_3A, INPUT);
  pinMode(IR_SENSOR_LANE_3B, INPUT);
  pinMode(TRAFFICL1RED, OUTPUT);
  pinMode(TRAFFICL1YEL, OUTPUT);
  pinMode(TRAFFICL1GRE, OUTPUT);
  pinMode(IR_SENSOR_LANE_1A, INPUT);
  pinMode(IR_SENSOR_LANE_1B, INPUT);
  pinMode(3, OUTPUT); // set segment A as output
  pinMode(4, OUTPUT); // set segment B as output
  pinMode(5, OUTPUT); // set segment C as output
  pinMode(6, OUTPUT); // set segment D as output
  pinMode(7, OUTPUT); // set segment E as output
  pinMode(8, OUTPUT); // set segment F as output
  pinMode(9, OUTPUT);  // set segment G as output
  pinMode(10, OUTPUT); // set dot as output
  pinMode(31, OUTPUT); // set segment A as output
  pinMode(32, OUTPUT); // set segment B as output
  pinMode(33, OUTPUT); // set segment C as output
  pinMode(34, OUTPUT); // set segment D as output
  pinMode(35, OUTPUT); // set segment E as output
  pinMode(36, OUTPUT); // set segment F as output
  pinMode(37, OUTPUT);  // set segment G as output
  pinMode(38, OUTPUT); // set dot as output
  for(int i = 31; i < 38; i++) { // start with segments off
    digitalWrite(i, HIGH);
  }
  digitalWrite(38, HIGH);
  for(int i = 3; i < 10; i++) { // start with segments off
    digitalWrite(i, HIGH);
  }
  digitalWrite(10, HIGH);  // start with the dot off
}

void loop() {
  int irValue1A = digitalRead(IR_SENSOR_LANE_1A);
  int irValue2A = digitalRead(IR_SENSOR_LANE_2A);
  int irValue3A = digitalRead(IR_SENSOR_LANE_3A);
  int irValue1B = digitalRead(IR_SENSOR_LANE_1B);
  int irValue2B = digitalRead(IR_SENSOR_LANE_2B);
  int irValue3B = digitalRead(IR_SENSOR_LANE_3B);
  int irValue1=irValue1A+irValue1B;
  int irValue2=irValue2A+irValue2B;
  int irValue3=irValue3A+irValue3B; 
  //CASE 1 222 
  if(irValue1==2 && irValue2==2 && irValue3==2)
  {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
 //CASE 2 212 
 else if(irValue1==2 && irValue2==1 && irValue3==2)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
  //CASE 3 220 
 else if(irValue1==2 && irValue2==2 && irValue3==0)
 {
  TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3REDHIGH();
     TIMER5();
   }
   //CASE 4 210 
 else if(irValue1==2 && irValue2==1 && irValue3==0)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3REDHIGH();
     TIMER5();
  }
  //CASE 5 211 
 else if(irValue1==2 && irValue2==1 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TIMER5();
    }
  //CASE 6 201 
 else if(irValue1==2 && irValue2==0 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TIMER5();
  }
  //CASE 7 221 
 else if(irValue1==2 && irValue2==2 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(0);
     TIMER5();
  }
 //CASE 8 011 
 else if(irValue1==0 && irValue2==1 && irValue3==1)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(0);
     TIMER5();
  }  
//CASE 9 020 
 else if(irValue1==0 && irValue2==2 && irValue3==0)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TIMER5();
 }
//CASE 10 002 
 else if(irValue1==0 && irValue2==0 && irValue3==2)
 {
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TIMER5();
 }
//CASE 11 200 
 else if(irValue1==2 && irValue2==0 && irValue3==0)
 {
     TRAFFICL1GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TIMER(2);
     TIMER5();
 } 
//CASE 12 010 
 else if(irValue1==0 && irValue2==1 && irValue3==0)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TIMER5();
 }
//CASE 13 001 
 else if(irValue1==0 && irValue2==0 && irValue3==1)
 {
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TIMER5();
 }
//CASE 14 100 
 else if(irValue1==1 && irValue2==0 && irValue3==0)
 {
     TRAFFICL1GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TIMER(0);
     TIMER5();
 }
//CASE 15 112 
 else if(irValue1==1 && irValue2==1 && irValue3==2)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
//CASE 16 122 
 else if(irValue1==1 && irValue2==2 && irValue3==2)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
//CASE 17 202 
 else if(irValue1==2 && irValue2==0 && irValue3==2)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TIMER5();
  }
//CASE 18 120 
 else if(irValue1==1 && irValue2==2 && irValue3==0)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3REDHIGH();
     TIMER5();
  }
//CASE 19 121 
 else if(irValue1==1 && irValue2==2 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(0);
     TIMER5();
  }
//CASE 20 110 
 else if(irValue1==1 && irValue2==1 && irValue3==0)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3REDHIGH();
     TIMER5();
  }
//CASE 21 111 
 else if(irValue1==1 && irValue2==1 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL2YELHIGH();
     TIMER5();
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(0);
     TIMER5();
  }
//CASE 22 101 
 else if(irValue1==1 && irValue2==0 && irValue3==1)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0);
     TIMER5();
  }
//CASE 23 102 
 else if(irValue1==1 && irValue2==0 && irValue3==2)
 {
     TRAFFICL2REDHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1GREHIGH();
     TIMER(0);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL3GREHIGH();
     TRAFFICL2REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TIMER5();
  }
//CASE 24 021 
 else if(irValue1==0 && irValue2==2 && irValue3==1)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(0);
     TIMER5();
  }  
//CASE 25 022 
 else if(irValue1==0 && irValue2==2 && irValue3==2)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(2);
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
//CASE 26 012 
 else if(irValue1==0 && irValue2==1 && irValue3==2)
 {
     TRAFFICL2GREHIGH();
     TRAFFICL3REDHIGH();
     TRAFFICL1REDHIGH();
     TIMER(0   );
     TRAFFICL3YELHIGH();
     TIMER5();
     TRAFFICL2REDHIGH();
     TRAFFICL3GREHIGH();
     TRAFFICL1REDHIGH();    
     TIMER(2);
     TIMER5();
  }
        
//CASE 27 000
else
{
  TRAFFICL2REDHIGH();
  TRAFFICL3REDHIGH();
  TRAFFICL1REDHIGH();
}

}
void TRAFFICL2REDHIGH(void)
{
    digitalWrite(TRAFFICL2GRE, LOW);
    digitalWrite(TRAFFICL2YEL, LOW);
    digitalWrite(TRAFFICL2RED, HIGH);  
}
void TRAFFICL2GREHIGH(void)
{
    digitalWrite(TRAFFICL2GRE, HIGH);
    digitalWrite(TRAFFICL2YEL, LOW);
    digitalWrite(TRAFFICL2RED, LOW);  
}

void TRAFFICL2YELHIGH(void)
{
    digitalWrite(TRAFFICL2GRE, LOW);
    digitalWrite(TRAFFICL2YEL, HIGH);
    digitalWrite(TRAFFICL2RED, LOW);  
}
void TRAFFICL1REDHIGH(void)
{
    digitalWrite(TRAFFICL1GRE, LOW);
    digitalWrite(TRAFFICL1YEL, LOW);
    digitalWrite(TRAFFICL1RED, HIGH);  
}
void TRAFFICL1GREHIGH(void)
{
    digitalWrite(TRAFFICL1GRE, HIGH);
    digitalWrite(TRAFFICL1YEL, LOW);
    digitalWrite(TRAFFICL1RED, LOW);  
}

void TRAFFICL1YELHIGH(void)
{
    digitalWrite(TRAFFICL1GRE, LOW);
    digitalWrite(TRAFFICL1YEL, HIGH);
    digitalWrite(TRAFFICL1RED, LOW);  
}
void TRAFFICL3REDHIGH(void)
{
    digitalWrite(TRAFFICL3GRE, LOW);
    digitalWrite(TRAFFICL3YEL, LOW);
    digitalWrite(TRAFFICL3RED, HIGH);  
}
void TRAFFICL3GREHIGH(void)
{
    digitalWrite(TRAFFICL3GRE, HIGH);
    digitalWrite(TRAFFICL3YEL, LOW);
    digitalWrite(TRAFFICL3RED, LOW);  
}

void TRAFFICL3YELHIGH(void)
{
    digitalWrite(TRAFFICL3GRE, LOW);
    digitalWrite(TRAFFICL3YEL, HIGH);
    digitalWrite(TRAFFICL3RED, LOW);  
}
void TIMER(int start)
{
  while(start>0)
  { 
    for (int count = start; count > 1; --count) 
     {
      int pin = 3;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     }
     for (int count = 10; count > 0; --count) 
     {
      int pin = 31;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     delay(1000); // this is the same as delay() but saves power
     }
     start=start-2;
      // this is the same as delay() but saves power
   }
   for (int count = 1; count > 0; --count) 
     {
      int pin = 3;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     }
     for (int count = 10; count > 5; --count) 
     {
      int pin = 31;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     delay(1000); // this is the same as delay() but saves power
     }
     delay(1000);
}
void TIMER5(void)
{
  for (int count = 1; count > 0; --count) 
     {
      int pin = 3;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     }
     for (int count = 5; count > 0; --count) 
     {
      int pin = 31;
      for (int segCount = 0; segCount < 7; ++segCount) {
        digitalWrite(pin, seven_segment_digits[count-1][segCount]);
        ++pin;
      
     }
     delay(1000); // this is the same as delay() but saves power
     }
     delay(1000);
}
