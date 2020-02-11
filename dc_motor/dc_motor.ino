
#define salt1 5
#define salt2 6

#define pepper1 9
#define pepper2 10

#define saltPin 17
#define pepperPin 19

#define MAX 100
#define period 5

int saltOn;
int pepperOn;

int salt_count;
int pepper_count;

int salt_dir;
int pepper_dir;

//This will run only one time.
void setup() {
  
  Serial.begin(9600);
  Serial.print("This program has started");

  //Set pins as outputs
  pinMode(salt1, OUTPUT);
  pinMode(salt2, OUTPUT);
  
  pinMode(pepper1, OUTPUT);
  pinMode(pepper2, OUTPUT);

  pinMode(saltPin, INPUT);
  pinMode(pepperPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);


  saltOn = 0;
  pepperOn = 0;
  salt_count = MAX;
  pepper_count = MAX;

  salt_dir = 0;
  pepper_dir = 0;
}

void loop() {
  saltOn = digitalRead(saltPin);
  pepperOn = digitalRead(pepperPin);

  if (saltOn) {  
    salt_count = 0;
  }

  if (salt_count < MAX) {
    digitalWrite(salt1, salt_dir);
    digitalWrite(salt2, !salt_dir);

    if (salt_count % period == 0) {
      salt_dir = !salt_dir;
    }
    salt_count++;
  }
  else {    
    digitalWrite(salt1, LOW);
    digitalWrite(salt2, LOW);
  }



  if (pepperOn) {  
    pepper_count = 0;
  }

  if (pepper_count < MAX) {
    digitalWrite(pepper1, pepper_dir);
    digitalWrite(pepper2, !pepper_dir);

    if (pepper_count % period == 0) {
      pepper_dir = !pepper_dir;
    }
    pepper_count++;
  }
  else {    
    digitalWrite(pepper1, LOW);
    digitalWrite(pepper2, LOW);
  }
  
  delay(50);
    
}
