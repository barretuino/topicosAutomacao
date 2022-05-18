/**
   Uso da persistência em MicroSDCard
   Prof. Ms. Paulo Barreto
   Aula: 18/10/2014
   Exemplo Básico de utilização do SD Card
   Este exemplo mostra como criar e destruir um arquivo de cartão SD
   Cartões SD ligado ao barramento SPI da seguinte forma:
      MOSI - pin 11
      MISO - pin 12
      CLK - pin 13
      CS - pin 4     
 */
#include <SPI.h>
#include <SD.h>

File myFile;

void setup()
{
 // Abre comunicação serial e esperar para a porta abrir :
  Serial.begin(9600);
   while (!Serial) {
    ; // Esperar por porta serial para conectar . Necessário para Leonardo só
  }


  Serial.print("Initializing SD card...");
  // Na Shield Ethernet, CS é o pino 4 É definido como uma saída por padrão.
  // Note que mesmo que ele não é usado como o pino CS , o pino SS hardware
  // (10 na maioria das placas Arduino , 53 no mega ) deve ser deixado como uma saída
  // ou as funções da biblioteca SD não vai funcionar.
  pinMode(10, OUTPUT);

  if (!SD.begin(4)) {
    Serial.println("Inicialização Falhou!");
    return;
  }
  Serial.println("Inicialização Realizada.");

  if (SD.exists("exemplo.txt")) {
    Serial.println("exemplo.txt existe.");
  }
  else {
    Serial.println("exemplo.txt não existe.");
  }

  // Abre ou Cria o objeto file
  Serial.println("Criando exemplo.txt...");
  myFile = SD.open("exemplo.txt", FILE_WRITE);
  myFile.close();

  // Checa se o objeto file existe
  if (SD.exists("exemplo.txt")) {
    Serial.println("exemplo.txt existe.");
  }
  else {
    Serial.println("exemplo.txt não existe.");  
  }

  // Deletando o objeto file
  Serial.println("Removendo exemplo.txt...");
  SD.remove("exemplo.txt");

  if (SD.exists("exemplo.txt")){ 
    Serial.println("exemplo.txt existe.");
  }
  else {
    Serial.println("exemplo.txt não existe.");  
  }
}

void loop()
{
   // Nada acontece após a conclusão da instalação.
}
