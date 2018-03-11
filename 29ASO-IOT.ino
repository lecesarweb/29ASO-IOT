 // Trabalho de IoT 29ASO - Equipe Juliana, Ieda, Raul, Claudia e Leandro.
 
#include <Ultrasonic.h> // Carrega a biblioteca externa necessaria para o HC-SR04 

 
#define pino_trigger 11 // pino de trigger do Arduino UNO
#define pino_echo 10 // pino de echo do Arduino UNO
 
// Inicializamos o sensor com os pinos definidos acima
 
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  // Inicializamos a comunicacao serial 
  
  Serial.begin(9600);
 
  // Imprimimos mensagem inicial no monitor serial
  
  Serial.println("Trabalho de IoT - 29ASO");
  Serial.println("Lendo sensor...");
}
 
void loop()
{
  // Lemos as informacoes do sensor e apresentamos o
  // resultado no monitor serial da IDE em centímetros(cm)
  
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  cmMsec = cmMsec/10;
  
  // Apresentamos a distancia em centimetros sem casas decimais.
  
  String cmMsecString = String(cmMsec, 0); // nesta linha pegamos a variavel que armazena os valores em
                                           // centimetros e arrendondamos o valor
                                           
  String cmMsecStringFinal = cmMsecString + " centimetros";
  
  // As informacoes adquiridas e já calculadas são mostradas no serial monitor
  
  Serial.print("Distancia: ");
  Serial.println(cmMsecStringFinal);
  delay(500);
}
