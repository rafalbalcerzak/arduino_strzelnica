//piny
int led []={7, 8, 9, 10};
int button []={2, 3, 4, 5};
int buzzer = 11;

int buttonState[] = {0,0,0,0};
int flag2 []={0,0,0,0};
int x = random(0,4);//numer popera
int xOld = x;
int current =0;
int target =20;
int flag = 0;
int remain = 4;


String inData;
char cmd[100];
byte cmdIndex;

unsigned long teraz;
unsigned long watch;
//===============================================
//konfikracja pinow
//===============================================
void setup() {
  pinMode(buzzer, OUTPUT);
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
//===============================================
//informacja za ile start(buzzer)
//===============================================
void intro(){
  Serial.println("Za 3 sekund zaczynamy");
  for(int t=3; t>0; t--){
    Serial.println(t);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(700);
  }
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  
}
//===============================================
//funkcjia random target
//===============================================
void randomTarget(){
  intro();
  current = 0;
  flag = 0;
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
        Serial.println("koniec, twój czas: ");
        teraz = millis();
        Serial.println(teraz - watch);
        }  
}
//===============================================
//funkcja wszystkie na raz
//===============================================
void allAtOnce(){
  intro();
  //odpaleni led
  for(int l = 0; l<4; l++){
    digitalWrite(led[l],HIGH);
  }
  int flag2[4]={0,0,0,0};
  remain=0;
  watch = millis();
  while(remain <4){
    //sprawdzenie stanu wlacznikow
    for(int l = 0; l<4; l++){
       buttonState[l]=digitalRead(button[l]);
    }
    for(int l = 0; l<4; l++){
      if(buttonState[l] == HIGH){
        digitalWrite(led[l],LOW);
        if(flag2[l]==0){
          remain++;
          flag2[l]++;
        }
      }
    }
  }
  Serial.println("koniec, twój czas: ");
  teraz = millis();
  Serial.println(teraz - watch);
}
//===============================================
//test
//===============================================
void test(){
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
//===============================================
//wykonanie komendy  
//===============================================
void exeCmd(){
  String command(cmd);
  if (cmd[0] == '0'){
    test();
  }
  else if (cmd[0] == '1'){
    randomTarget();
  }  
    
  else if (cmd[0] == '2'){
     allAtOnce();
  }
} 
//===============================================
//głowan petla
//===============================================
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


