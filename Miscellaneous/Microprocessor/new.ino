
#include<input.h>
int n;
scanf("%d",&n);
int  motor= n;

int x=0;


void setup() {
  
Serial.begin(9600);
}

void loop() {
  
  if(n ==9)
  {
    while(x<250){
  x = x+15;
   analogWrite(motor,x);
   delay(1000);
   analogWrite(motor,0);
  Serial.println(x);
    }
  }
   

}
