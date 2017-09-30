int led []={7, 8, 9, 10};
int button []={2, 3, 4, 5};
int buttonState[] = {0,0,0,0};
int x = random(0,4);//numer popera
int xOld = x;
int current =0;
int target =20;
int flag = 0;

String inData;
char cmd[100];
byte cmdIndex;

unsigned long teraz;
unsigned long watch;

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
  randomSeed(analogRead(0));
}

void exeCmd(){
  String command(cmd);
  if (command == "test"){
    for(int l; l<4; l++){
      digitalWrite(led[l],HIGH);
      delay(100);
      digitalWrite(led[l],LOW);
    }
    delay(100);
    for(int l=3; l>=0; l--){
      digitalWrite(led[l],HIGH);
      delay(100);
      digitalWrite(led[l],LOW);
    }
  }
  else if (cmd[0] == '1'){
    target  = atof(cmd + 1);
    watch = millis();
    while(current < target){
          digitalWrite(led[x],HIGH);
          buttonState[x]=digitalRead(button[x]);
          
          if(buttonState[x] == HIGH){
            digitalWrite(led[x],LOW);
            do{
            x = random(0,4);
            }while(x == xOld);
            
            if(x!=xOld){
              xOld=x;
              current ++;
            }
            //Serial.println(current);
          }
        }
        
        if(flag ==0){
          flag = 1;
          Serial.println("koniec");
          teraz = millis();
          Serial.println(teraz - watch);
        }
    }
}

void loop() {
  if(Serial.available()>0){
  char c = (char)Serial.read();
  if(c =='\n'){
    cmd[cmdIndex] = 0;
    exeCmd();
    cmdIndex = 0;
    char cmd[100];
    }
    else{
      cmd[cmdIndex] = c;
      if(cmdIndex <99) cmdIndex++;
      }
    
          
  } 
}


