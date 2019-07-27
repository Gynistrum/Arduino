#include <MicroView.h>

int pin_gruen = 6;
int pin_rot = 5;
int pin_draht = 3;
int pin_alarm = 2;


bool alarm = false;

int spiel_start;

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
    int gruen = digitalRead(pin_gruen);
    if (gruen == HIGH)
    {
      neues_spiel();
    }
  }

  // wenn kein alarm, gucke ob heißer draht. Spiel leuft aktuel
  if (alarm == false)
  {
    int draht = digitalRead(pin_draht);
    if (draht == HIGH)
    {
      alarm_starten();
      Serial.println(millis() / 1000);
    }
    else
    {
      zeit_anzeigen();
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
        uView.print("Tja!"); 
        uView.display();

  Serial.print("Dauer ");
  int dauer = millis() / 1000 - spiel_start;
  Serial.println(dauer);
}


void neues_spiel()
{
  alarm = false;
  Serial.println("Neu");
  digitalWrite(pin_alarm, LOW);

        uView.clear(PAGE);
        uView.setCursor(24, 20);
        uView.setFontType(1);
        uView.print("Viel");
        uView.print("Gluck"); 
        uView.display();

               spiel_start = millis() / 1000;
}


void zeit_anzeigen()
{
  int dauer = millis() / 1000 - spiel_start;
  if (dauer > 20)
  {
    alarm_starten();
  }
  else
  {
  Serial.print("spielstart ");
  Serial.print(spiel_start);
  Serial.print(" Aktuel ");
  Serial.println(millis() / 1000);
  uView.clear(PAGE);
  uView.setCursor(24, 20);
  uView.setFontType(1);
  uView.print(dauer);
  uView.display();
  }
 
}
