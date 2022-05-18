/**
   Monitoramento de Luminosidade - Arduino Web
   Uso da persistência em MicroSDCard
   Prof. Ms. Paulo Barreto
   Aula: 18/10/2014
   Exemplo de atualização de leitura de sensor LDR e MicroSDCard
**/
#include <SPI.h>
#include <SD.h>

#define ldr_pin A0 //Pino DATA do Sensor ligado na porta Analogica A0

int valorSensor = 0; //variável usada para ler o valor do sensor em tempo real.
const int chipSelect = 4;

File medida;

void setup()
{
  //Abertura da porta de Comunicação
  Serial.begin(9600);
  
  Serial.print("Inicializando o SDCard....");
  //Pino utilizado pela SDCard
  pinMode(10, OUTPUT);
   
  //Avalia se foi possível dar inicio a SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha na detecção do SDCard");    
    //Aborta e retorna a função
    return;
  }
  Serial.println("SDCard Inicializado");  
}

void loop()
{
  //Realiza a leitura do sensor LDR
  valorSensor = analogRead(ldr_pin);
  Serial.print("Medida atual é: ");
  Serial.print(valorSensor);
  
  //Abrir arquivo do SDCard
  medida = SD.open("medida.txt", FILE_WRITE);
  
 //Avalia se foi possível dar inicio a SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha na detecção do SDCard");    
    //Aborta e retorna a função
    return;
  }
  
  //Há um arquivo medida disponível?
  if (medida) {
    //Realiza a gravação da medida
    medida.println(valorSensor);
    //Realiza o fechamento do arquivo
    medida.close();
  } else {
   //Caso aconteça uma falha na existencia ou acesso ao arquivo
    Serial.println("Erro ao abrir medida.txt");
  }
  delay(1000);
}
