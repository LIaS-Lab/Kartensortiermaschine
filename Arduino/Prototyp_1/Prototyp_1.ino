int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(12, OUTPUT); //Richtung
  pinMode(9, OUTPUT);  //Bremse
  
  analogWrite(3, 255); //setzt Geschwindigkeit auf max
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incomingByte = Serial.read();

    switch(incomingByte){
      case 'r': //Richtung ändern
        digitalWrite(12, HIGH);
        Serial.println("Richtung geaendert");
        break;

      case 'l': //Richtung ändern
        digitalWrite(12, LOW);
        Serial.println("Richtung geaendert");
        break;
        
      case 's': //Bremse setzen
        digitalWrite(9, HIGH);
        Serial.println("Bremse gesetzt");
        break;
        
      case 'g': //Bremse lösen
        digitalWrite(9, LOW);
        Serial.println("Bremse geloest");
        break;
    }
  }
}
