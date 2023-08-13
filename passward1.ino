#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(38,16,2);
char k[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rpins[4]={2,3,4,5};
byte cpins[4]={6,7,8,9};
char myk;
Keypad mypad (makeKeymap(k),rpins,cpins,4,4);
char pass[]={'1','3','4','5'};
char upass[sizeof(pass)]={0};
byte counter=0,i=0;

void reslcd(){
 lcd.home();
 lcd.clear();
 lcd.print("Enter password");
 lcd.setCursor(0,1);
}

void setup() {
  
  Serial.begin(9600);
  pinMode(10,0);
  pinMode(11,0);
  pinMode(12,0);
   pinMode(13,0);
 lcd.init();
 lcd.backlight();
 reslcd();

}
void loop() {
  
  myk=mypad.getKey();
  while(!myk){
  if(digitalRead(10)==1){
    lcd.clear();
  lcd.home();
    lcd.setCursor(0,0);
  lcd.print("The ID is:1");
  }
    else if(digitalRead(11)==1){
    lcd.clear();
  lcd.home();
    lcd.setCursor(0,0);
  lcd.print("The ID is:2");
  }
  else if(digitalRead(12)==1){
    lcd.clear();
  lcd.home();
    lcd.setCursor(0,0);
  lcd.print("The ID is:3");
  }   else if(digitalRead(13)==1){
    lcd.clear();
  lcd.home();
    lcd.setCursor(0,0);
  lcd.print("The ID is:4");
  }myk=mypad.getKey();}
  lcd.home();
  lcd.print("Enter password");
  lcd.setCursor(counter,1);
  lcd.print("*");
  if(myk=='D'){
    Serial.println(counter);
    lcd.clear();  
    lcd.home();
    for(i=0;i<sizeof(upass);i++){
      if(upass[i]!=pass[i])break;}
      //Serial.println(upass[i]);
  if((i==sizeof(upass))&&(counter==0)){
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("User authorized");
  //digitalWrite(10,1);
  //delay(3000);
  //digitalWrite(10,0);
  lcd.clear();
  lcd.home();
     lcd.print("Enter your fingere");
 lcd.setCursor(0,1);
// reslcd();
  }
  else {
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("Wrong password");
  delay(2000);
  reslcd();
  }
  }
  else
    *(upass+counter)=myk;
 counter=(counter>=3)?-1:counter;
 counter++; 
  }