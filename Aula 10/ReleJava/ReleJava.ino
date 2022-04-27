/**
 * Exemplo de Projeto de Atuação do Arduino
 * Prof. Paulo Barreto
 * Data 27/04/2022
 */
int val;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);   //Rele 1
  pinMode(3, OUTPUT);   //Rele 2
  pinMode(4, OUTPUT);   //Rele 3
  pinMode(5, OUTPUT);   //Rele 4
}

void loop(){
  if (Serial.available()) {
    val = Serial.read();
    //Relé 1
    if (val == 11) {
      digitalWrite(2, HIGH);    //Liga
    } 
    if (val == 10) {
      digitalWrite(2, LOW);     //Desliga
    }
    //Relé 2
    if (val == 21) {
      digitalWrite(3, HIGH);
    } 
    if (val == 20) {
      digitalWrite(3, LOW);
    }
    //Relé 3
    if (val == 31) {
      digitalWrite(4, HIGH);
    } 
    if (val == 30) {
      digitalWrite(4, LOW);
    }
    //Relé 4
    if (val == 41) {
      digitalWrite(5, HIGH);
    } 
    if (val == 40) {
      digitalWrite(5, LOW);
    }
  }else{
    Serial.print(val);
  }
}

