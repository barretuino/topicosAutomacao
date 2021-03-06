/**
   Monitoramento de Luminosidade - Arduino Web
   Uso de hospedagem em Servi192.168.2.1dor Web
   Necessário conhecimento do Plugin
   Prof. Ms. Paulo Barreto
   Aula: 11/10/2014
   Exemplo de atualização de leitura de sensor LDR
**/
#include <SPI.h>
#include <Ethernet.h>

#define ldr_pin A0 //Pino DATA do Sensor ligado na porta Analogica A0

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x9B, 0x36 }; //Mac Adress - Endereço Físico
byte ip[] = { 192, 168, 2, 100 }; //IP da Shield na Rede
byte gateway[] = { 192, 168, 2, 1 }; //IP do Roteador que prôve o acesso
byte subnet[] = { 255, 255, 255, 0 }; //Máscara de SubNet
EthernetServer server(80); //Porta no Servidor

int valorSensor = 0; //variável usada para ler o valor do sensor em tempo real.

void setup(){
  //Instanciando a Ethernet
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  //Definindo a velocidade de comunicação Serial
  Serial.begin(9600);
  Serial.println("Exemplo de Comunicacao via Ethernet Shield"); 
}

void loop(){
  //Lendo o valor do sensor.
  valorSensor = analogRead(ldr_pin);
  EthernetClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK"); //send new page
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html>");
    client.println("<head>"); 
    client.println("<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>");
        client.println("<link href='http://192.168.2.1:8080/Demos/styles.css' rel='stylesheet' />");
        client.println("<script src='http://192.168.2.1:8080/Demos/js/jquery-1.9.1.min.js'></script>");
        client.println("<script src='http://192.168.2.1:8080/Demos/js/knockout-2.2.1.js'></script>");
        client.println("<script src='http://192.168.2.1:8080/Demos/js/globalize.min.js'></script>");
        client.println("<script src='http://192.168.2.1:8080/Demos/js/dx.chartjs.js'></script>");
        client.println("</head><body><script type='text/javascript'>");
        client.println("function grafico(valor)");
        client.println("{");
        client.println("var d=document.formBotoes; //Vai pegar o formulario e adicionar em uma variavél");
        client.println("var valor = valor");
        //client.println("var menor = d.menor.value;");
        client.println("var maior = d.maior.value;");
        client.println("$('#chartContainer').dxCircularGauge({");
        client.println("scale: {");
        client.println("startValue: 0,");
        client.println("endValue: 1023,");
        client.println("majorTick: {");
        client.println("tickInterval: 50");
        client.println("}},");
        client.println("rangeContainer: {");
        client.println("backgroundColor: 'none',");
        client.println("ranges: [");
        client.println("{");
        client.println("startValue: 0,");
        client.println("endValue: 250,");
        client.println("color: '#E19094'");
        client.println("},{");
        client.println("startValue: 250,");
        client.println("endValue: 550,");
        client.println("color: '#A6C567'");
        client.println("},{");
        client.println("startValue: 550,");
        client.println("endValue: 700,");
        client.println("color: '#FCBB69'");
        client.println("},{");
        client.println("startValue: 700,");
        client.println("endValue: 1023,");
        client.println("color: '#FF0000'");
        client.println("}]},");
        client.println("needles: [{value: valor}],");
        client.println("markers: [{value: valor}, { value: maior}]");
        client.println("});");
        client.println("}");
        client.println("</script>");
        client.println("<div class='title'>");	
        client.println("<center><h1>Projeto Arduino</h1>&nbsp;&nbsp;&nbsp;<h2>Medidas de Luminosidade</h2></center>");
        client.println("</div>");
        client.println("<form name='formBotoes'>");
        client.println("<center>");
        //client.println("<input type='text' name='menor' size='4'>");
        client.println("Considerada Adequada: <input type='text' name='maior' size='4'>");
        client.print("<input type='button' value='Atualizar' onClick='grafico(");
        //client.print(map(valorSensor, 504, 950, 0, 100));
        client.print(valorSensor);
        client.println (")'>");
        client.println("</center>");
        client.println("</form>");         
        client.println("<div id='chartContainer' style='width: 100%; height: 440px;'></div>");
        client.println("</div>");        
      while (client.connected()) {
      if (client.available()) {
          valorSensor = analogRead(ldr_pin);
          client.println("<br>Luminosidade do Ambiente ");
          client.print(valorSensor);
          client.print("<input type='button' value='Atualizar' onClick='grafico(");
          client.print(valorSensor);
          client.println (")'>");       
          delay(5000);
      }
    }
    client.println("</body>");
    client.println("</html>");
  }
}
