int led []={7, 8, 9, 10};
int button []={2, 3, 4, 5};
int buttonState[] = {0,0,0,0};
char input;
int x = random(0,4);//numer popera
int xOld = x;
int current =0;
int target =22;//cos nie tak
int flag = 0;

void setup() {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(button[0], INPUT);
  pinMode(button[1], INPUT);
  pinMode(button[2], INPUT);
  pinMode(button[3], INPUT);
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  if(current <= target){
    digitalWrite(led[x],HIGH);
    buttonState[x]=digitalRead(button[x]);
    
    if(buttonState[x] == HIGH){
      digitalWrite(led[x],LOW);
      x = random(0,4);
      current ++;
    }
  }
  
  else if(flag ==0){
    flag = 1;
    Serial.println("koniec");
  }
}
