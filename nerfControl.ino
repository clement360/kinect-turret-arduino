#define pushPin 3
#define flyPin 4

int output = 0;

void setup(){
  pinMode(pushPin, OUTPUT);  
  pinMode(flyPin, OUTPUT);  
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  analogWrite(pushPin, 0);
  analogWrite(flyPin, 0);

}

bool checkForInput() {
  int incomingByte = 0;
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.println(incomingByte, DEC);
    // detect enter key
    if (incomingByte == 10) {
      Serial.println("FIREEEEEEE!!!");
      return true;
    }
  } 

  return false;
}

void loop(){
  bool fire = false;
  fire = checkForInput();
  if (fire == true) {
    // start the pusher motor
    Serial.print("SENT: ");
    analogWrite(flyPin, 255);
    delay(800);
    //analogWrite(pushPin, 255);
    //delay(240);
    //analogWrite(pushPin, 0);
    analogWrite(flyPin, 0);
    Serial.println("STOP!!!");
  }
}


