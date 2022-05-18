/**************************************************************
   Projeto Arduino sensor de luminosidade --> integração Serial
   Prof. Ms. Paulo Barreto
   Aula: 11/10/2014
   Exemplo de atualização de leitura de sensor LDR
**************************************************************/
int sensor = 0;      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //variável usada para ler o valor do sensor em tempo real.

//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
}

//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){ 
  //Lendo o valor do sensor.
  int valorSensor = analogRead(sensor);
  //Imprimindo valor na serial
  Serial.print("$");
  Serial.print(valorSensor);
  Serial.println("#");
  //Aguarda 'n' milissegundos
  delay(5000);
}
