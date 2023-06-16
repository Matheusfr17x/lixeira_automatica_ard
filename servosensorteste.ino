#include <Ultrasonic.h>

//Programa: Cancela automática
  
//Carrega as bibliotecas do sensor ultrassonico e do servo
#include "Ultrasonic.h"
#include <Servo.h>
 
// Para o sensor ultrassonico
//Define os pinos para o trigger e echo
#define pino_trigger 8
#define pino_echo 9
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger,pino_echo);
 
// Para o servo motor
Servo meuServo; // Declara o servo motor
 
 
void setup()
{
  // Colocamos a serial para verificar possiveis erros
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
  
void loop()
{
   int dist;
   dist=ultrasonic.Ranging(CM);
   // Colocamos a distancia na serial para ajustarmos o sensor
  Serial.print("Distancia em cm : ");
  Serial.println(dist);
   delay(1000);
  meuServo.attach(6); // Liga o servo motor
 
  // Você pode alterar esse valor de acordo com o funcionamento desejado
  if(dist < 6) // Verifica se o valor do sensor é menor que 5
  {
    // Se o valor for
    meuServo.write(90); // Posiciona o motor em 45
    delay(5000); // Aguarda 1 segundo
    Serial.println("Abriu"); // Envia mensagem pela serial
  }
  else
  {
    // Senão
    meuServo.write(0); // Posiciona o motor em 0
    delay(1000); // Aguarda 0,1 segundo
    Serial.println("Fechou"); // Envia mensagem pela serial
 
  }
   
  //meuServo.detach();// Desliga o servo motor
   

}
