#include <Servo.h>

Servo meuServo;          // Cria um objeto para o servo
const int botaoPin1 = 2; // Pino onde o botão está conectado.
const int botaoPin2 = 4; // Pino onde o botão está conectado
bool estadoBotao1;       // Variável para armazenar o estado do botão
bool estadoBotao2;       // Variável para armazenar o estado do botão
int forcereading;        // leitura do sensor de pressão


void setup() {
  meuServo.attach(9);  // Conecta o servo ao pino 9
  pinMode(botaoPin1, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up
  pinMode(botaoPin2, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up
  Serial.begin(9600);
}

void loop() {
  estadoBotao1 = digitalRead(botaoPin1); // Lê o estado do botão
  estadoBotao2 = digitalRead(botaoPin2); // Lê o estado do botão
  forcereading = analogRead(A0);

  Serial.println(forcereading); 

  if (estadoBotao1 == LOW) { // Verifica se o botão foi pressionado
    Serial.println("botão1");
    meuServo.write(30);    // Gira o servo para 90 graus
  }
  if (estadoBotao2 == LOW) { // Verifica se o botão foi pressionado
    Serial.println("botão2");
    meuServo.write(0);    // Gira o servo para 90 graus
    delay(1000);           // Aguarda 2 segundos
  }
}
