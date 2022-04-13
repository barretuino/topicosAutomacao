/**************************************************************
   Projeto Arduino sensor de luz.
   @autor Prof. Ms. Paulo Barreto
   @date  13/04/2022
**************************************************************/

//Declaração de variável
int sensor = A0;      //Pino analógico em que o sensor está conectado.
int valorSensor = 0;  //variável usada para ler o valor do sensor em tempo real.

//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
  //Definindo o modo do pino que será adotada na leitura da medida
  pinMode(sensor, INPUT);
}

//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){
 
  //Lendo o valor do sensor.
  int valorSensor = analogRead(sensor);
  //Imprimindo valor na serial
  Serial.print("$");
  Serial.print(valorSensor);
  Serial.println("#");

  if(valorSensor < 400){
     Serial.println("Escuro");
  }
  if(valorSensor > 400 && valorSensor<700){
     Serial.println("Luminosidade Adequada");
  }
  if(valorSensor > 700){
     Serial.println("A caminho de Damasco");
  }
  
  
  //Aguarda 'n' milissegundos  
  delay(1000);
}
