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
boolean flagA_ex01 = 0;
boolean flagA_ex02 = 1;
boolean flagB_ex02 = 1;
boolean flagC_ex02 = 1;
boolean flagC_03;

boolean statusbtA_ex01;
boolean statusbtA_ex02, statusbtB_ex02, statusbtC_ex02; 
boolean statusbtC, flagC; //Alterar conforme exercicios 3-5 
boolean statusbtD, flagD; //Alterar confrome exercicios 3-5

unsigned long ultimoTempobtA = 0;
unsigned long ultimoTempobtB = 0;
unsigned long ultimoTempobtC = 0;
const unsigned long debounceInterval = 150;

int placar_1 = 0;
int placar_2 = 0;
int ultPlacar_1 = -1;
int ultPlacar_2 = -1;


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

flagA_ex01 = 0;
flagA_ex02 = 1;
flagB_ex02 = 1;
flagC_ex02 = 1;

statusbtA_ex01 = digitalRead(btA);

statusbtA_ex02 = digitalRead(btA);
statusbtB_ex02 = digitalRead(btB);
statusbtC_ex02 = digitalRead(btC);

ultPlacar_1 = -1;
ultPlacar_2 = -1;

dht.begin();
Serial.begin(115200);
Serial.println("Esquema iniciado...");
}

void loop() {
  //ex01();
  ex02();
}

  void ex01(){
    statusbtA_ex01 = digitalRead(btA);
    delay(10); 
    if(statusbtA_ex01 == 0 && flagA_ex01 == 0){
          contador ++;
          flagA_ex01 = 1;
    if(contador > 5) contador = 5;    
    }
    if(statusbtA_ex01 == 1 && flagA_ex01 == 1){     
      flagA_ex01 = 0;
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
  statusbtA_ex02 = digitalRead(btA);
  statusbtB_ex02 = digitalRead(btB);
  statusbtC_ex02 = digitalRead(btC);

  unsigned long tempoAtual = millis();
  
  if(statusbtA_ex02 == 0 && flagA_ex02 == 1) {
    if(tempoAtual - ultimoTempobtA > debounceInterval){
      if(placar_1 < 10) {
      placar_1 ++;
      }
      flagA_ex02 = 0;
      ultimoTempobtA = tempoAtual;
      }
    } else if(statusbtA_ex02 == 1) {
    if(tempoAtual - ultimoTempobtA > debounceInterval){
      flagA_ex02 = 1;
    }
  }
  if(statusbtB_ex02 == 0 && flagB_ex02 == 1) {
    if(tempoAtual - ultimoTempobtB > debounceInterval){
      if(placar_2 < 10) {
      placar_2 ++;
      }
      flagB_ex02 = 0;
      ultimoTempobtB = tempoAtual;
    } 
  } else if(statusbtB_ex02 == 1) {
    if(tempoAtual - ultimoTempobtB > debounceInterval){
      flagB_ex02 = 1;
    }
  }
  if(statusbtC_ex02 == 0 && flagC_ex02 == 1) {
    if(tempoAtual - ultimoTempobtC > debounceInterval){
      placar_1 = 0;
      placar_2 = 0;
      flagC_ex02 = 0;
      ultimoTempobtC = tempoAtual;
    }
  } else if(statusbtC_ex02 == 1) {
    if(tempoAtual - ultimoTempobtC > debounceInterval){
      flagC_ex02 = 1;
    }
  }
  if(placar_1 != ultPlacar_1 || placar_2 != ultPlacar_2){
    Serial.print(placar_1);
    Serial.print(" ");
    Serial.println(placar_2);
    ultPlacar_1 = placar_1;
    ultPlacar_2 = placar_2;
  }

}

void ex03(){
  
}

void ex04(){
  
}

void ex05(){
  
}

