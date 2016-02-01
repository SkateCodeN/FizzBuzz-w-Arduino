// Code was developed to show a basic pogram to show to 
// all the bay area folk that come to N.Star my skills.





int   LED_ARRAY[] = {3,4,5,7,10,11,12,13};

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_ARRAY[7], OUTPUT);  // 128 green 
  pinMode(LED_ARRAY[6], OUTPUT);  //  64 green
  pinMode(LED_ARRAY[5], OUTPUT);   // 32 green
  pinMode(LED_ARRAY[4], OUTPUT);   // 16 green
  
  pinMode(LED_ARRAY[3], OUTPUT);   //   8 green
  pinMode(LED_ARRAY[2], OUTPUT);   //   4 green
  pinMode(LED_ARRAY[1], OUTPUT);   //   2 green
  pinMode(LED_ARRAY[0], OUTPUT);   //   1 green

 pinMode(9, OUTPUT);   // Divisible by 3  white
 pinMode(8, OUTPUT);   // Divisible by 5  violet
 pinMode(2, OUTPUT);   // Prime Number    yellow
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
 for( a = 0; a < 256; a++)
 {
  
  convertToBinary(a);
  if (a % 3 == 0 && a % 5 == 0)
  {
    Serial.print(a);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    delay(700);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    
  }
  else if (a % 3 == 0)
  {
    Serial.print(a);
    digitalWrite(9,HIGH);
    delay(700);
    digitalWrite(9,LOW);
  }
  else if (a % 5 == 0)
  {
    Serial.print(a);
    digitalWrite(8,HIGH);
    delay(700);
    digitalWrite(8,LOW);
  }
 
 }
  
    
}

// Custom function that I develop to turn a number into its
// binary representation. I know Im trying to re-invent the wheel.
void convertToBinary(int number)
  {
    //String binaryArray[8];
    String binaryNumber ="";
    int n;
     for ( n = 7; n >= 0; n--)
            {
                if ( pow(2,n) > number)
                {
                    //binaryStr += "0";
                    binaryNumber += "0";
                } 
                else 
                {
                    if (number == pow(2, n))
                    {
                        //binaryStr += "1";
                        binaryNumber += "1";
                        number = (int)(number - pow(2, n));
                    }
                    else
                    {
                        if (number > pow(2, n))
                        {
                            //binaryStr += "1";
                            binaryNumber += "1";;
                            number = (int)(number - pow(2, n));
                        }
                    }// end else
                }// end else
                
            }// end for
            turnOnLed(binaryNumber);
  }// end function

void turnOnLed (String binary)
{
  
  char binaryArray[9];
  binary.toCharArray(binaryArray,9);
  int a;
 //Serial.print( binary);
 //Serial.print("\n");

  
  //delay(1000);


  
  //int index = binary.indexOf(1);
  //Serial.print("index val " + index);
  
  for(int a = 8; a >= 0; a--)
  {
    if (binaryArray[a] == '1')
    {
      // Serial.print( a );
       digitalWrite(LED_ARRAY[a], HIGH);
       delay(1500);
       //digitalWrite(LED_ARRAY[a], LOW);
    }
    else
    {
      digitalWrite(LED_ARRAY[a], LOW);
    }
  }

  
  
}
