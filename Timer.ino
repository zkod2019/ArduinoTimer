int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 10;
int D2 = 11;
int D3 = 12;
int D4 = 13;

static int mapping[10][7] = {
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH}, // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW}, // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH}, // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW}, // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW}, // 5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW}, // 6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // 7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW}, // 8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}, // 9
};

void writeDigit(int number, int idx) {
  int* segs = mapping[number];
  digitalWrite(pinA, segs[0]);
  digitalWrite(pinB, segs[1]);   
  digitalWrite(pinC, segs[2]);
  digitalWrite(pinD, segs[3]);
  digitalWrite(pinE, segs[4]);
  digitalWrite(pinF, segs[5]);
  digitalWrite(pinG, segs[6]);

  if (idx == 0) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  } else if (idx == 1) {
    digitalWrite(D2, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  } else if (idx == 2) {
    digitalWrite(D3, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D4, LOW);
  } else if (idx == 3) {
    digitalWrite(D4, HIGH);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
  }
}

// the setup routine runs once when you press reset:
void setup() {  
  Serial.begin(9600);
  Serial.print("Connecting to Clock");              
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

int digit = 0;
// the loop routine runs over and over again forever:
void loop() {
  writeDigit(digit, 0);
  writeDigit(digit, 1);
  writeDigit(digit, 2);
  writeDigit(digit, 3);
  digit = digit + 1 % 9;
  delay(2000);
}
