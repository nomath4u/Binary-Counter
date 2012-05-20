#define BUTTON 12

int sum_set = 0;
int val = 0; //store the state of input pin
int old_val =0;
void calculate(int);

void setup(){
  int j; //index variable
  for(j=2; j<=9; j++){
    pinMode(j, OUTPUT); //pins 2-9 output
  }
  pinMode(BUTTON, INPUT); //button read
}

void loop(){
  int j; //index variable
  val = digitalRead(BUTTON);  //read input from button to val
   
   // check if button is pressed or not
   
   if(val == HIGH && old_val == LOW){
       sum_set++;
       delay(10); //de-bounce
   }
   
   old_val = val; //val is now old
   
   calculate(sum_set);
   for(j=2; j<=9; j++)
     digitalWrite(j, LOW); //clear lights that may not need to be on
   
}

//Determine which lights need to be on

void calculate(int sum){
  int k; // index variable
  
  int led_calc[9] = {100, 80, 40, 20, 10, 8, 4, 2 ,1};// array for
                                                     // led place
                                                     // value
  
  if(sum == led_calc[0]) //reset once we get to 100
    sum_set = 0;
  
  for(k=1; k<=8; k++){
    if( sum >= led_calc[k]){
      digitalWrite (9-(k-1), HIGH);
      sum = sum - led_calc[k];
    }
  }
}
