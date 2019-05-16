
int rows[] = {32, 34, 36, 38};
int cols[] = {33, 35, 37, 39};

void setup() {
  Serial.begin(9600);
}


void initPinModes() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW);
    pinMode(rows[i], INPUT_PULLUP);
//    digitalWrite(rows[i], LOW);
  }
}

void loop() {
  int button = query_keypad();
  if(button != 0) {
  Serial.println(button);
  }
  delay(50);
}

/**
   Reads the keypad and returns a number that is currently pressed

   @return (integer) value of currently pressed key (1-16) (0 for none)
*/
int query_keypad() {
  // Set the mode initially (0-3 output, 4-7 input)
  initPinModes();

  // Short wait for the pins to update
  delay(1);

  /*---------- Scan Columns ----------*/
  /*
    Serial.print(digitalRead(rows[0]));
    Serial.print(" ");
    Serial.print(digitalRead(rows[1]));
    Serial.print(" ");
    Serial.print(digitalRead(rows[2]));
    Serial.print(" ");
    Serial.println(digitalRead(rows[3])); */

  // Grab the state of the IDR
  if (digitalRead(rows[0]) == true && digitalRead(rows[1]) == true && digitalRead(rows[2]) == true && digitalRead(rows[3]) == true) {
    // this is the default, so nothing is pressed
    //Serial.println("\n\n\nDefault\n\n\n");
    return 0;
  }

  
  //  for(int i = 0; i < 4; i++) {
  Serial.print(digitalRead(rows[0]));
  Serial.print(" ");
  Serial.print(digitalRead(rows[1]));
  Serial.print(" ");
  Serial.print(digitalRead(rows[2]));
  Serial.print(" ");
  Serial.print(digitalRead(rows[3]));

  Serial.print("    ");

  
  int magic_row = -1;
  for(int i = 0; i < 4; i++) {
    if(digitalRead(rows[i]) == LOW) {
      magic_row = i;
    }
  }

  // Set the columns to read, and the rows to write
  //gpio_c->MODER &= ~(0xFFFF);
  //gpio_c->MODER |= 0x5500;

  for (int i = 0; i < 4; i++) {
    pinMode(rows[i], OUTPUT);
  }

  delay(1);

  

  // Write the pattern from the IDR back to the ODR
  //gpio_c->ODR &= ~(0xFF);
  //gpio_c->ODR |= idr;


  for (int i = 0; i < 4; i++) {
    digitalWrite(rows[i], digitalRead(rows[i]));
    //digitalWrite(cols[i], digitalRead(cols[i]));
  }

  delay(1);

   for (int i = 0; i < 4; i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }


  Serial.print(digitalRead(cols[0]));
  Serial.print(" ");
  Serial.print(digitalRead(cols[1]));
  Serial.print(" ");
  Serial.print(digitalRead(cols[2]));
  Serial.print(" ");
  Serial.println(digitalRead(cols[3]));
//    }
  /*

    idr = gpio_c->IDR;
    idr ^= 0xFF;
    uint8_t row = idr, col = idr;

    row = row >> 4;
    row = log2(row);

    col &= ~(0xF0);
    col = log2(col);

    // Convert row and col into a button number
    uint8_t button_number = row * 4 + col + 1;

    //  printf("R: %d, C: %d, #: %d\r\n", row, col, button_number);
  */

      for(int c = 0; c < 4; c++) {
        
        if(digitalRead(cols[c]) == false) {
          return (magic_row * 4) + c + 1;
        }
      }
}
