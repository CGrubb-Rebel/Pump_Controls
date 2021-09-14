// Define stepper motor connections:
#define dirPin 44
#define stepPin 45

#define potPin 0


int freq_range_low = 2000; // 500Hz
int freq_range_high = 50; // 10kHz

int scale = 32;
int pow2 = 5;
static uint16_t rolling_average[32];

void disable_PWM() {
  TCCR5A &= ~(1 << COM5B0); // Disables PWM on pin 45
}

void enable_PWM() {
  TCCR5A |= (1 << COM5B0); // Enables PWM on pin 45
}

void update_frequency_with_pot() {
  uint16_t pot = analogRead(potPin);
  for(int i=0; i < scale-1;i++){
    rolling_average[i] = rolling_average[i+1];
  }
  rolling_average[scale-1] = pot;

  uint16_t average = 0;

  for(int i=0; i < scale-1;i++){
    average += rolling_average[i];
  }
  
  average = average >> pow2;
  //Serial.println(average);
  
  int scaled_value = map(average, 1021, 0, freq_range_low, freq_range_high);
  OCR5A = scaled_value;
}

void setup() {

  Serial.begin(9600);
 // Declare motor pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  // Set the spinning direction CW/CCW:
  digitalWrite(dirPin, LOW);

    // Zero out registers for controlling the timer.
  TCCR5A = 0;
  TCCR5B = 0;

  TCNT5 = 0;  // Sets counter to 0. Will auto-increment in background
  OCR5A = freq_range_low; //MODIFY THIS ONE. The timer will count up to this number and reset.
  // The bigger the number, the slower the frequency.
  // Range is from 0 to 2^16 (65536)
  // Frequency Equation:
  // 16MHz/(2*8*(OCR5A+1))

  TCCR5A |= (1 << COM5B0); // Sets pin 45 to toggle on compare match
  TCCR5B |= (1 << WGM52); // Sets mode to Clear Timer on Compare match (CTC)
  TCCR5B |= (1 << CS51); // Sets prescaler. See pg.157 of datasheet
}

void loop() {
  // put your main code here, to run repeatedly:
  enable_PWM();
  update_frequency_with_pot();
  //Serial.println(OCR5A);
  //Serial.println(TCCR5A);
}
