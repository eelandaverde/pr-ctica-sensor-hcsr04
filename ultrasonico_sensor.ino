//Incluimos liquid crystal y definimos los pines

#include <LiquidCrystal.h>
const int rs=8, en=9, d4=4, d5=5,d6=6,d7=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Programando sensor ultrasonico HCSR04

//declaro las variables
float distance = 0;
long timeDuration ;
//definir constantes
const int echo = 10, trigger = 11, retardoSensor = 10;
const int retardoProgram = 500, serialmonitor = 9600;
const float Vm = 1000/17;

//configuro entradas y salidas
void setup ()
{
    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);
    Serial.begin(serialmonitor);
    lcd.begin(16,2);
    digitalWrite(trigger,LOW);
}

void loop ()
{
    lcd.clear();
  //Presiono el gatillo para rafaga de ultrasonido
    digitalWrite(trigger,HIGH);
    delayMicroseconds(retardoSensor);
    digitalWrite(trigger,LOW);
  
   //Obtengo el tiempo completo en que echo está activado
    timeDuration = pulseIn(echo,HIGH);
    //Calculo la distancia 
    distance = timeDuration/Vm;
    //Imprimo en lcd
    lcd.setCursor(0,0);
    lcd.print("La distancia  es:");
     /*if (distance < 2.0 || distance > 400.0 )
     {
      lcd.clear();
      lcd.home();
      lcd.print("Fuera de rango"); 
     }
     else
     {*/
      lcd.setCursor(4,1); 
      lcd.print(String(distance) + " cm");
     //}
  //Imprimo en monitor serial
    Serial.println(" La distancia es : " + String(distance) + 
                   " cm");
    delay(retardoProgram);
}
