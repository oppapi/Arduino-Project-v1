int limit_distance=20;

#define echoPin A1
#define trigPin A0
#define left_forward 2
#define left_reverse 3
#define right_forward 4
#define right_reverse 5
#define sweeper_motor 7

long duration;
int actual_distance;

void setup()
{
Serial.begin(9600);
pinMode(sweeper_motor, OUTPUT);
pinMode(left_reverse, OUTPUT);
pinMode(right_forward, OUTPUT);
pinMode(right_reverse, OUTPUT);
pinMode(right_reverse, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void ultrasonic ()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration=pulseIn(echoPin, HIGH);
actual_distance = duration*0.034/2;

Serial.print("Distance: ");
Serial.print(actual_distance);
Serial.print(" cm");

if (actual_distance >= limit_distance)
{
digitalWrite(sweeper_motor, HIGH);
forward();
}

else if (actual_distance < limit_distance)
{
digitalWrite(sweeper_motor, LOW);
stop_me();
delay(500);

reverse();
delay(1000);

stop_me();
delay(500);

turn();
delay(1000);

turn();
delay(1000);

stop_me();
delay(500);

}
}

void forward ()
{
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}

void reverse ()
{
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}

void turn ()
{
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}


void stop_me ()
{
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}


void loop ()
{
ultrasonic();
}
