//FISHBOT

//BIBLIOTECA SERVO
#include <Servo.h>

//DEFININDO PINO DE CONTROLE DO SERVO
#define SERVO 6 // Porta Digital 6 PWM

//VARIAVEL SERVO
Servo s;

//POSICAO SERVO
int pos; 

//RECEBE BLUETOOTH
char comando;

void setup()
{

  //INICIANDO A SERIAL
  Serial.begin(9600);
  s.attach(SERVO);
  pinMode(9, OUTPUT);

  //INICIA O SERVO NA POSICAO ZERO
  s.write(45);  
}

void loop()
{

  //CONTROLE DO PEIXE
  while(Serial.available() > 0)
  {
    comando = Serial.read();
    
    switch (comando) 
    {
    case 'F':
      //MODO AUTONOMO
         autonomo();
      break;
    case 'L':
      //ESQUERDA
     esquerda();
     digitalWrite(9, HIGH);
      break;
    case 'R':
      //DIREITA
     direita();
     digitalWrite(9, LOW);
      break;
    default: 
    //PARAR TUDO
    break;
  }
  }
}

void autonomo()
{
 
 for(pos = 45; pos < 70; pos++)
  {
    s.write(pos);
  delay(5);
  }

  for(pos = 70; pos >= 20; pos--)
  {
    s.write(pos);
    delay(5);
  }
       
}

void esquerda()
{
  for(pos = 45; pos < 90; pos++)
  {
    s.write(pos);
  delay(5);
  }
}

void direita()
{
  for(pos = 90; pos >= 0; pos--)
  {
    s.write(pos);
  delay(5);
  }
}
