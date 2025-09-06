// Estrutura básica para a entrega do arquivo
// Ao concluir, clique na seta SHARE no WOKWI e envie o link como anexo da tarefa.

// Mapeamento de I/Os (sequência esquerda para direita):
#include <DHT.h>

#define DHT22 2
#define DHTTYPE DHT22
#define Pto A0

#define ldAl 3
#define ldVo 4
#define ldAo 5
#define ldVe 6

#define btA 7
#define btB 9
#define btC 11
#define btD 13



void setup() {
pinMode(ldAl, OUTPUT);
pinMode(ldVo, OUTPUT);
pinMode(ldAo, OUTPUT);
pinMode(ldVe, OUTPUT);

pinMode(btA, INPUT_PULLUP);
pinMode(btB, INPUT_PULLUP);
pinMode(btC, INPUT_PULLUP);
pinMode(btD, INPUT_PULLUP);

dht.begin();

Serial.begin(115200);
Serial.println("Esquema iniciado...");
}

void loop() {

  ex01();
  // ex02();
  // ex03();
  // ex04();
  // ex05(); 

}

void ex01(){

}

void ex02(){
  
}

void ex03(){
  
}

void ex04(){
  
}

void ex05(){
  
}

