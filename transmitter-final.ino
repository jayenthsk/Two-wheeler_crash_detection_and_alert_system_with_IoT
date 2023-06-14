#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int tilt = 4;

int buzzer = 3;

int pushButton = 5;

void setup()
{

  pinMode(buzzer, OUTPUT);
  pinMode(tilt, INPUT);
  pinMode(pushButton, INPUT);
  mySwitch.enableTransmit(10);
  mySwitch.setProtocol(1);
  Serial.begin(9600);
}

int start = -1;

void loop()
{
  // put your main code here, to run repeatedly:

  int val = digitalRead(tilt);

  Serial.println(start);

  if (val == LOW)
  {

    if (start == -1)
      start = millis() % 30000;

    if ((millis() % 30000 - start) > 5000)
    {

      start = -1;

      digitalWrite(buzzer, HIGH);

      int buzzSound = millis() % 30000;

      bool flag = false;

      while (millis() % 30000 - buzzSound < 5000)
      {

        Serial.println("buzzer !! ,waiting for push button");

        int pushVal = digitalRead(pushButton);

        Serial.println(pushVal);

        delay(1000);

        if (pushVal)
        {
          digitalWrite(pushButton, LOW);
          // Serial.println("Push button is pressed");
          flag = true;
          // break;
        }
      }

      digitalWrite(buzzer, LOW);

      // if(!flag) {
      sendMessage();
      // }
    }
  }
  else
  {
    start = -1;
  }

  delay(500);
}

void sendMessage()
{
  const char *message = "Hello!";
  mySwitch.send(message);
  Serial.println("Message sent: ");
}
