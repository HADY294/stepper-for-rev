// defines pins numbers

const int stepPin = 5;

const int dirPin = 2;

const int enPin = 8;

const int LimitSwitch_LEFT_Pin  = 10;

const int LimitSwitch_RIGHT_Pin = 11;



void setup() {



  Serial.begin(9600);



  pinMode(LimitSwitch_LEFT_Pin , INPUT);

  pinMode(LimitSwitch_RIGHT_Pin , INPUT);



  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);



  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);



  // Set Dir to Home switch

  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction





}

void loop() {



    int leftSw  = digitalRead( LimitSwitch_LEFT_Pin);

    int rightSw = digitalRead( LimitSwitch_RIGHT_Pin);

   

    if( (leftSw  == HIGH && (digitalRead(dirPin) == HIGH)) ||

        (rightSw == HIGH && (digitalRead(dirPin) == LOW)) ){

   

        motorStep(1);



    }

    else if( leftSw == LOW && (digitalRead(dirPin) == HIGH) ){

          digitalWrite(dirPin,LOW);

          delay(2000);

    }

    else if( rightSw == LOW && (digitalRead(dirPin) == LOW ) ){

          digitalWrite(dirPin,HIGH);

          delay(2000);

    }

 

}

void motorStep( int MAX){



   for(int x = 0; x < MAX; x++) {

        digitalWrite(stepPin,HIGH);

        delayMicroseconds(500);

        digitalWrite(stepPin,LOW);

        delayMicroseconds(500);

      }

     

}
