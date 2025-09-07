// Estrutura básica para a entrega do arquivo
// Ao concluir, clique na seta SHARE no WOKWI e envie o link como anexo da tarefa.

// Mapeamento de I/Os (sequência esquerda para direita):
#include <DHT.h>
#define DHTpino 2
#define DHTtipo DHT22
DHT dht(DHTpino, DHTtipo);

#define Pto A0

#define ldAl 3
#define ldVo 4
#define ldAo 5
#define ldVe 6

#define btA 7
#define btB 9
#define btC 11
#define btD 13

int contador = 0;
int sttcontador = 0;
boolean statusbtA, flagA; 
boolean statusbtB, flagB; 
boolean statusbtC, flagC; 
boolean statusbtD, flagD;

void piscarLd(int pino, int vezes) {
      for(int i = 0; i < vezes; i++){
        digitalWrite(pino, HIGH);
        delay(200);
        digitalWrite(pino, LOW);
        delay(200);
      }
    }

void setup() {
pinMode(ldAl, OUTPUT);
pinMode(ldVo, OUTPUT);
pinMode(ldAo, OUTPUT);
pinMode(ldVe, OUTPUT);

pinMode(btA, INPUT_PULLUP);
pinMode(btB, INPUT_PULLUP);
pinMode(btC, INPUT_PULLUP);
pinMode(btD, INPUT_PULLUP);
pinMode(A0, INPUT);

statusbtA = digitalRead(btA);
statusbtB = digitalRead(btB);
statusbtC = digitalRead(btC);
statusbtD = digitalRead(btD);

dht.begin();
Serial.begin(115200);
Serial.println("Esquema iniciado...");

}

void loop() {
  ex01();
}


  void ex01(){
    statusbtA = digitalRead(btA);
    delay(10); 
    if(statusbtA == 0 && flagA == 0){
          contador ++;
          flagA = 1;
    if(contador > 5) contador = 5;    
    }
    if(statusbtA == 1 && flagA == 1){     
      flagA = 0;
    }
    if(contador >= 1 && contador <= 5) {  
    }
    if (contador != sttcontador) {
      sttcontador = contador;

      Serial.print("Botão pressionado ");
      Serial.print(contador);
      Serial.println(contador == 1 ? " vez." : " vezes.");

      switch(contador) {
        case 1:
          piscarLd(ldAl, 1);
        break;

        case 2:
          piscarLd(ldAl, 2);
        break;
        
        case 3:
          piscarLd(ldAl, 3);
        break;
        
        case 4:
        piscarLd(ldAl, 4);
        break;
        
        case 5:
          digitalWrite(ldAl, HIGH);
          Serial.println("Meta atingida!");
        break;
      } 
    }
  }




void ex02(){
  
}

void ex03(){
  
}

void ex04(){
  
}

void ex05(){
  
}

