#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int j = 1; // integer used in scanning the array designating column number
//2-dimensional array for asigning the buttons and there high and low values
int Button[21][3] = {{2, 834, 838}, // button 1  *up
                     {3, 734, 738}, // button 2  *down
                     {1, 605, 611}, // button 3  *left
                     {4, 314, 320}, // button 4  *right
                     {5, 174, 179}, // button 5  *A
                     /*{6, 87, 92}, // button 6    *B
                     {7, 892, 897}, // button 1 + button 2
                     {8, 870, 878}, // button 1 + button 3
                     {9, 847, 852}, // button 1 + button 4
                     {10, 840, 845}, // button 1 + button 5
                     {11, 836, 841}, // button 1 + button 6
                     {12, 815, 822}, // button 2 + button 3
                     {13, 765, 770}, // button 2 + button 4
                     {14, 749, 754}, // button 2 + button 5
                     {15, 741, 746}, // button 2 + button 6
                     {16, 670, 675}, // button 3 + button 4
                     {17, 639, 644}, // button 3 + button 5
                     {18, 623, 627}, // button 3 + button 6
                     {19, 404, 409}, // button 4 + button 5
                     {20, 359, 364}, // button 4 + button 6
                     {21, 239, 243}*/}; // button 5 + button 6
int analogpin = 5; // analog pin to read the buttons
int label = 0;  // for reporting the button label
int counter = 0; // how many times we have seen new value
long time = 0;  // the last time the output pin was sampled
int debounce_count = 50; // number of millis/samples to consider before declaring a debounced input
int current_state = 0;  // the debounced input value
int ButtonVal;
int x = 0;
int y = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(x,y);
  lcd.write(255);
}

void loop()
{
   // If we have gone on to the next millisecond
  if (millis() != time)
  {
    // check analog pin for the button value and save it to ButtonVal
    ButtonVal = analogRead(analogpin);
    if(ButtonVal == current_state && counter >0)
    { 
      counter--;
    }
    if(ButtonVal != current_state)
    {
      counter++;
    }
    // If ButtonVal has shown the same value for long enough let's switch it
    if (counter >= debounce_count)
    {
      counter = 0;
      current_state = ButtonVal;
      //Checks which button or button combo has been pressed
      if (ButtonVal > 0)
      {
        ButtonCheck();
      }
    }
    time = millis();
  }
}

void ButtonCheck()
{
  // loop for scanning the button array.
  for(int i = 0; i <= 21; i++)
  {
    // checks the ButtonVal against the high and low vales in the array
    if(ButtonVal >= Button[i][j] && ButtonVal <= Button[i][j+1])
    {
      // stores the button number to a variable
      label = Button[i][0];
      Action();      
    }
  }
}

void Action()
{
  // mover cursor up
  if(label == 1 && y > 0)
  {
    y = y - 1;
  }
  // move cursor down
  if(label == 2 && y < 1)
  {
    y = y + 1;
  }
  // move cursor left
  if(label == 3 && x > 0)
  { 
    x = x - 1;
  }
  // move cursor right
  if(label == 4 && x < 15)
  {
    x = x + 1;
  }
  
  if(label == 5)
  {
    // action button A
  }
 
  if(label == 6)
  {
    // action button B
  }
  // move cursor left and up
  if(label == 8 && x > 0 && y > 0)
  {
    x = x - 1;
    y = y - 1;
  }
  // move cursor right and up
  if(label == 9 && x < 15 && y > 0)
  {
    x = x + 1;
    y = y - 1;
  }
  // move cursor left and down
  if(label == 12 && x > 0 && y < 1)
  {
    x = x - 1;
    y = y + 1;
  }
  // move cursor right and down
  if(label == 13 && x < 15 && y < 1)
  {
    x = x + 1;
    y = y + 1;
  }
  
  if(label == 21)
  {
    // action button A + Bk
  }
  else
  {
    lcd.clear();
    lcd.setCursor(x, y);
    lcd.write(255);
  }  
}

