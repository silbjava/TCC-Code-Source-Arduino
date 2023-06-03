//Programa : Projeto de TCC - Controle de 3 lampadas com Relés
//Autor : Silvano B.
 
//Porta ligada ao pino IN1 do modulo
#define porta_rele1 3
//Porta ligada ao pino IN2 do modulo
#define porta_rele2 4
//Porta ligada ao pino IN3 do modulo
#define porta_rele3 5
char info, comando = 'n';
int contL = 0, contD = 0, conTotal = 0;
void setup() {
  Serial.begin(9600);    // Estabele comunicação serial.
  //Define pinos para o rele como saida
  pinMode(porta_rele1, OUTPUT); 
  pinMode(porta_rele2, OUTPUT);
  pinMode(porta_rele3, OUTPUT);
  digitalWrite(porta_rele1, HIGH);
  digitalWrite(porta_rele2, HIGH);
  digitalWrite(porta_rele3, HIGH);

}

void loop() {
  while (Serial.available()>0) {
    delay(10);
    info = Serial.read();
    //Comandos de controle (Liga/Desliga) e contagem de controles.
    if (info == 'D' && comando != info) {
      conTotal++;
      Serial.print("Numero total de Comandos: ");
       delay(50);
      Serial.println(conTotal);
      comando = info;
    }else if (info == 'L' && comando != info) {
      conTotal++;
      Serial.print("Numero total de Comandos: ");
       delay(50);
      Serial.println(conTotal);
      comando = info;
    }
    //Desligamento das lâmpadas e contagem de desacionamentos
    if (comando =='D' && info != comando) {
      switch (info) {
        case '1':
          digitalWrite(porta_rele1, HIGH);
          comando = info;
          contD++;
          Serial.print("Numero de vezes desligada: ");
          delay(50);
          Serial.println(contD);
          break;
        case '2':
          digitalWrite(porta_rele2, HIGH);
          comando = info;
          contD++;
          Serial.print("Numero de vezes desligada: ");
          delay(50);
          Serial.println(contD);
          break;
        case '3':
          digitalWrite(porta_rele3, HIGH);
          comando = info;
          contD++;
          Serial.print("Numero de vezes desligada: ");
          delay(50);
          Serial.println(contD);
          break;
        case 'T':
          comando = info;
          digitalWrite(porta_rele1, HIGH);
          delay(500);
          digitalWrite(porta_rele2, HIGH);
          delay(500);
          digitalWrite(porta_rele3, HIGH);
          contD++;
          Serial.print("Numero de vezes desligada: ");
          Serial.println(contD);
          break;
      }
    }
    //Ativação das lâmpadas e contagem de acionamentos
    if (comando =='L' && info != comando) {
      switch (info) {
        case '1':
          digitalWrite(porta_rele1, LOW);
          comando = info;
          contL++;
          Serial.print("Numero de vezes ligada: ");
   		  delay(50);
          Serial.println(contL);          
          break;
        case '2':
          digitalWrite(porta_rele2, LOW);
          comando = info;
          contL++;
          Serial.print("Numero de vezes ligada: ");
   		  delay(50);
          Serial.println(contL);
          break;
        case '3':
          digitalWrite(porta_rele3, LOW);
          comando = info;
          contL++;
          Serial.print("Numero de vezes ligada: ");
          delay(50);
          Serial.println(contL);
          break;
        case 'T':
          comando = info;
          digitalWrite(porta_rele1, LOW);
          delay(1000);
          digitalWrite(porta_rele2, LOW);
          delay(1000);
          digitalWrite(porta_rele3, LOW);
          contL++;
          Serial.print("Numero de vezes ligada: ");
          Serial.println(contL);
          break;
      }
    }
    if (info == 'A' && comando !="" ) {
      Serial.print("Numero total de Comandos: ");
      delay(10);
      Serial.println(conTotal);
      Serial.print("Numero de vezes ligada: ");
      delay(10);
      Serial.println(contL);
      delay(10);
      Serial.print("Numero de vezes desligada: ");
      delay(10);
      Serial.println(contD);
    }
  }
}