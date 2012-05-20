#define BUTTON 12

int sum_set = 0;
int val = 0; //store the state of input pin
int old_val = 0; //stores previous val
int state = 0; //0 LED off 1 LED on

void calculate(int, int*);

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
   
   old_val = val; // val is now old
   
   calculate(sum_set, &sum_set);
   for(j=2; j<=9; j++)
     digitalWrite(j, LOW); //clear lights that may not need to be on
   
}

//Determine which lights need to be on

void calculate(int sum, int* sum_set){
  if(sum == 100)
    *sum_set = 0;
  
  if( sum >= 80){
    digitalWrite (9, HIGH);
    sum = sum - 80;
  }
  if(sum >= 40){
    digitalWrite (8, HIGH);
    sum = sum - 40;
  }
  if(sum >= 20){
    digitalWrite (7, HIGH);  
    sum = sum - 20;
  }
  if(sum >= 10){
    digitalWrite (6, HIGH);
    sum = sum - 10;
  }
  if(sum >= 8){
    digitalWrite (5, HIGH);
    sum = sum - 8;
  }
  if(sum >= 4){
    digitalWrite (4, HIGH);
    sum = sum -4;
  }
  if(sum >=2){
    digitalWrite (3, HIGH);
    sum = sum - 2;
  }
  if(sum == 1){
    digitalWrite (2, HIGH);
  }
}
