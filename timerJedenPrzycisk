const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

const int led1 = 7;
const int led2 = 8;
const int led3 = 9;
const int led4 = 10;

unsigned long teraz;
unsigned long watch;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

char input;
int flag1 =0;
int flag2 =0;
int flag3 =0;
int flag4 =0;

int repeate = 0;
int rando;
void setup(){
  Serial.begin(9600);
  Serial.println("ready");
  pinMode(buttonPin1, INPUT);
  pinMode(led1,OUTPUT);
}

  
void loop(){
   
   
   buttonState2 = digitalRead(buttonPin2);
   buttonState3 = digitalRead(buttonPin3);
   buttonState4 = digitalRead(buttonPin4);
   
   if (Serial.available() > 0) {
                input = Serial.read();
                if(input == '1'){
                  flag1 =0;
                  repeate =0;
                  Serial.println("start ");
                  watch = millis();
          
                  digitalWrite(led1, HIGH);
                  
                  
                }/*koniec if input == 1*/

                
                
   }/*koniec if serial*/
    buttonState1 = digitalRead(buttonPin1);
                  if( (buttonState1 == HIGH) && (flag1 == 0)){
                    flag1 = 1;
                    digitalWrite(led1, LOW);
                    teraz = millis();
                    Serial.println(teraz - watch);
                  }
}/*koniec void loop*/

   



