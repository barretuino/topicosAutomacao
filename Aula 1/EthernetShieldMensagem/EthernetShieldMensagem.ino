 #include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x00, 0x9B, 0x36 }; //physical mac address
byte ip[] = { 
  192, 168, 2, 99 }; // ip in lan
byte gateway[] = { 
  192, 168, 2, 1}; // internet access via router
byte subnet[] = { 
  255, 255, 255, 0 }; //subnet mask
EthernetServer server(80); //server port

void setup()
{
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
   if (client) {
    client.println("<html>");
    client.println("<head>"); 
    client.println("Bem Vindo!");
    client.println("</body>");
    client.println("</html>");
  }
}
