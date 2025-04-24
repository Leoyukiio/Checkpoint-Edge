const int sensorLuz = A0;
const int ledVerde = 12;
const int ledAmarelo = 11;
const int ledVermelho = 10;
const int buzzer = 9;
const int limiarIdeal = 400;  
const int limiarAlerta = 600;
const int limiarProblema = 800;

void setup() {
  pinMode(sensorLuz, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorLuz = analogRead(sensorLuz);
  Serial.print("luminosidade:");
  Serial.println(valorLuz);

 
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  noTone(buzzer);


  if (valorLuz < limiarAlerta) {

    digitalWrite(ledVerde, HIGH);
  } 
  else if (valorLuz < limiarProblema) {

    digitalWrite(ledAmarelo, HIGH);
  } 
  else {

    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 3000);
  }

  delay(300);
}