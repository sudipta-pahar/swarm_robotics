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
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void transmit(String motion)
{
  if (motion == "For")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    analogWrite(en1, 255);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    analogWrite(en2, 255);
    delay(10);
  }

  if (motion == "Le")
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    analogWrite(en1, 255);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    analogWrite(en2, 255);
    delay(10);
  }
  if (motion == "Rig")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    analogWrite(en1, 255);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    analogWrite(en2, 255);
    delay(10);
  }

  void loop()
  {
    int r = analogRead(A0);
    int l = analogRead(A1);
    Serial.print("right");
    Serial.print(r);
    Serial.print("left");
    Serial.println(l);

    if ((r > 700) && (l > 700))
    {
      transmit("For");
      digitalWrite(B1, HIGH);
      digitalWrite(B2, LOW);
      digitalWrite(B3, HIGH);
      digitalWrite(B4, LOW);

    }
    if ((r < 700) && (l > 700))
    {
      transmit("Rig");
      digitalWrite(B1, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(B3, HIGH);
      digitalWrite(B4, LOW);
    }
    if ((r > 700) && (l < 700))
    {
      transmit("Le");
      digitalWrite(B1, HIGH);
      digitalWrite(B2, LOW);
      digitalWrite(B3, LOW);
      digitalWrite(B4, HIGH);
    }

  }
