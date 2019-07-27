#include <MicroView.h>

int pin_gruen = 6;
int pin_rot = 5;
int pin_draht = 3;
int pin_alarm = 2;


bool alarm = false;

void setup()
{
  uView.begin();

  Serial.begin(9600);
  Serial.println("Programm begin");
  Serial.println("              ");

  pinMode(pin_gruen, INPUT);
  pinMode(pin_rot, INPUT);
  pinMode(pin_draht, INPUT);
  pinMode(pin_alarm, OUTPUT);

  neues_spiel();

  Serial.println("klappt");
}


void loop()
{
  // wenn alarm, gucke ob taste gedrueckt
  if (alarm == true)
  {
    int rot = digitalRead(pin_rot);
    if (rot == HIGH)
    {
      neues_spiel();
    }
  }

  // wenn kein alarm, gucke ob heißer draht
  if (alarm == false)
  {
    int draht = digitalRead(pin_draht);
    if (draht == HIGH)
    {
      alarm_starten();
    }
  }
}


void alarm_starten()
{
  alarm = true;
  Serial.println("ALARM");
  digitalWrite(pin_alarm, HIGH);

        uView.clear(PAGE);
        uView.setCursor(24, 20);
        uView.setFontType(1);
        uView.print("Verlierer!"); 
        uView.display();
}


void neues_spiel()
{
  alarm = false;
  Serial.println("Neu");
  digitalWrite(pin_alarm, LOW);

        uView.clear(PAGE);
        uView.setCursor(24, 20);
        uView.setFontType(1);
        uView.print("Viel Glueck!"); 
        uView.display();
}
