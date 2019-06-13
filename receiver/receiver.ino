int m1 = 3;
int m2 = 5;
int m3 = 6;
int m4 = 9;
int en1 = A5;
int en2 = A4;
#define B1 10
#define B2 11
#define B3 12
#define B4 13

void setup()
{
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void transmit(String motion)
{
  if (motion == "St")
  {
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    digitalWrite(B3, LOW);
    digitalWrite(B4, LOW);
    delay(10);
  }
  if (motion == "For")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    analogWrite(en1, 255);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    analogWrite(en2, 255);
  }

  if (motion == "Le")
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    analogWrite(en1, 255);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    analogWrite(en2, 255);
  }
  if (motion == "Rig")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    analogWrite(en1, 255);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    analogWrite(en2, 255);
  }


}


void loop()
{


  int D1 = digitalRead(B1);
  int D2 = digitalRead(B2);
  int D3 = digitalRead(B3);
  int D4 = digitalRead(B4);

  if ((D1 == HIGH) && (D2 == LOW) && (D3 == HIGH) && (D4 == LOW))
  {
    transmit("For");
    Serial.print("Forward");
  }

  else if ((D1 == LOW) && (D2 == HIGH) && (D3 == HIGH) && (D4 == LOW))
  {
    transmit("Rig");
    Serial.print("Right");
  }

  else if ((D1 == HIGH) && (D2 == LOW) && (D3 == LOW) && (D4 == HIGH))
  {
    transmit("Le");
    Serial.print("Left");
  }

  else if ((D1 == LOW) && (D2 == LOW) && (D3 == LOW) && (D4 == LOW))
  {
    transmit("St");
    Serial.print("Stop");
  }
  else
  {
    Serial.print("No data");
  }
  delay(100);
}
