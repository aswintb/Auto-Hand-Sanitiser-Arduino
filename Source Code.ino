#define trigPin 2
#define echoPin 3
#define relayPin 10
#define distancethreshold 10


// Define variables:
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  //set default relay state to off
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}


void loop()
{
 
 distance=distance_calc();

if (distance<distancethreshold)
 {
  pump(1000);  //run the pump, for the duration given in paranthesis
 }


}


int distance_calc()
{
digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
  return distance;

}

void pump(int pumpdelay)
{
   digitalWrite(relayPin, LOW);
   delay(pumpdelay);
   digitalWrite(relayPin, HIGH);
}
