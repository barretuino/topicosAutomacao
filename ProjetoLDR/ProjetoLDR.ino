int sensor = A0;     //Pino analógico em que o sensor está conectado.
int medida;  
void setup()
{  
  Serial.begin(9600);
}

void loop()
{
  //Lendo o valor do sensor.
  medida = analogRead(sensor);

  Serial.print("$");
  Serial.print(medida);
  Serial.println("#");
  delay(1000);
}
