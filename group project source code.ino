int sensor=5;
int led=12;
int a=13;
int button1=3;
int button2=4;
int buttonstate1;
int buttonstate2;
int sensorstate;
int flag1=0;
int flag2=0;
int people=0;

void setup(){
  Serial.begin(115200);
  pinMode(sensor,INPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(led,OUTPUT);
  pinMode(a,OUTPUT);
}

void loop() {
  buttonstate1=digitalRead(button1);
  buttonstate2=digitalRead(button2);
  sensorstate=digitalRead(sensor);
    if((buttonstate1==LOW)&&(buttonstate2==LOW)){
        digitalWrite(a,HIGH);
    }
    else{
        digitalWrite(a,LOW);
        if((buttonstate1==HIGH)&&(buttonstate2==HIGH)){
          flag2++;
        }
        else{
          flag2=0;
        }
    }
    if(sensorstate==HIGH){
      flag1++;
      if((people==0)&&(flag1>=300)){
        digitalWrite(led,HIGH);
        people=1;
        flag1=0;
      }
      else if((people==1)&&(flag1>=300)){
        if(flag2>=10){
          digitalWrite(led,LOW); 
          people=0;
          flag1=0; 
        }
        else{
           digitalWrite(led,HIGH);
           people=1;
           flag1=0; 
        }
      }
    }
    else{
      flag1=0;
    }
}
