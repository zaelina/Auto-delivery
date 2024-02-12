#include "sonar.h"
// левая сторона
int enA = 9;
int in1 = 8;
int in2 = 7;
// правая
int enB = 3;
int in3 = 5;
int in4 = 4;
int k = -1;
int r8; 
int r7; 
int r6; 
int r5; 
int l4; 
int l3; 
int l2;
int l1;
const int pTrig = 12;
const int pEcho = 11;
long cm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Sonar_init(pTrig, pEcho);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.begin(9600);
dtchk();
while(l1 < 400) {
  str();
  l1 = analogRead(A7);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
lft();
dtchk();
}

while(l1 < 400) {
  str();
  l1 = analogRead(A7);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
lft();
dtchk();
}

while(r8 < 400) {
  str();
  r8 = analogRead(A0);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
rght();
dtchk();
}

while(r8 < 400) {
  str();
  cm = Sonar(200);
  if (cm <= 20) {
    boost();
  }
  r8 = analogRead(A0);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
rght();
dtchk();
}

while(r8 < 400) {
  str();
  r8 = analogRead(A0);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
rght();
dtchk();
}

while(l1 < 400) {
  str();
  cm = Sonar(200);
  if (cm <= 20) {
    boost();
  }
  l1 = analogRead(A7);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
lft();
dtchk();
}

while(l1 < 400) {
  str();
  l1 = analogRead(A7);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
lft();
dtchk();
}

while(r8 < 400) {
  str();
  cm = Sonar(200);
  if (cm <= 20) {
    boost();
  }
  r8 = analogRead(A0);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
rght();
dtchk();
}

while(r5 > 400 and l4 > 400) {
  str();
 r5 = analogRead(A3); 
 l4 = analogRead(A4);  
}
if (r5 < 400 and l4 < 400) {
  stop();
}

while(r8 < 400) {
  bck();
  r8 = analogRead(A0);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
rght();
dtchk();
}

while(l1 < 400) {
  str();
  cm = Sonar(200);
  if (cm <= 20) {
    boost();
  }
  l1 = analogRead(A7);
}
while(l1 > 400 or l2 < 400 or r5 < 400 or l4 < 400 or r6 < 400 or r8 > 400) {
lft();
dtchk();
}

if(r5 > 400 and l4 > 400) {
  str();
 r5 = analogRead(A3); 
 l4 = analogRead(A4); 
}

stop();
}


void loop() {

}

void dtchk() {
 r8 = analogRead(A0); 
 r7 = analogRead(A1); 
 r6 = analogRead(A2); 
 r5 = analogRead(A3); 
 l4 = analogRead(A4); 
 l3 = analogRead(A5); 
 l2 = analogRead(A6); 
 l1 = analogRead(A7);
}

void str() {
analogWrite(enA, 100);   
analogWrite(enB, 100);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

void rght() {
analogWrite(enA, 250);   
analogWrite(enB, 250);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

}
void lft() {
analogWrite(enA, 250);   
analogWrite(enB, 250);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

void stop() {
analogWrite(enA, 0);   
analogWrite(enB, 0);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(10000);
}

void bck() {
analogWrite(enA, 100);   
analogWrite(enB, 100);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);  
}

void boost() {
analogWrite(enA, 255);   
analogWrite(enB, 255);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
delay(3500);
}
