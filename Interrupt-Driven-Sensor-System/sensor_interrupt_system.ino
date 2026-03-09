#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t sampleFlag = 0;
volatile uint8_t manualMode = 0;

// -------- TIMER1 INIT (200ms) --------
void timer1_init() {
  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 << WGM12);                 // CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);    // Prescaler 1024
  OCR1A = 3124;                           // 200ms
  TIMSK1 |= (1 << OCIE1A);                // Enable interrupt
}

// -------- ADC INIT --------
void adc_init() {
  ADMUX = (1 << REFS0);
  ADCSRA = (1 << ADEN)
         | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// -------- ADC READ --------
uint16_t adc_read(uint8_t channel) {
  ADMUX = (1 << REFS0) | (channel & 0x0F);
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC));
  return ADC;
}

// -------- TIMER ISR --------
ISR(TIMER1_COMPA_vect) {
  sampleFlag = 1;
}

// -------- BUTTON ISR --------
ISR(INT1_vect) {
  manualMode ^= 1;
}

void setup() {
manualMode = 1;   // Start in sensor mode
  Serial.begin(9600);
  delay(500);   // Allow Serial to stabilize

  DDRB |= (1 << 5);        // LED output

  DDRD &= ~(1 << 3);       // Button input
  PORTD |= (1 << 3);       // Pull-up

  // External interrupt setup
  EICRA = (1 << ISC11);
  EIMSK = (1 << INT1);

  adc_init();
  timer1_init();

  sei();   // Enable global interrupts AFTER everything
}

void loop() {

  if (sampleFlag) {

    sampleFlag = 0;

    uint16_t temp = adc_read(0);
    uint16_t light = adc_read(1);

    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print("  Light: ");
    Serial.print(light);
    Serial.print("  Mode: ");
    Serial.println(manualMode);

   // ---- LED CONTROL LOGIC ----

// ---- LED CONTROL ----

if (manualMode == 0) {
    // Blink mode
    PORTB ^= (1 << 5);
}
else {
    // Sensor mode

    if (light >20 || temp > 5) {   // adjust threshold if needed
        PORTB |= (1 << 5);          // LED ON
    }
    else {
        PORTB &= ~(1 << 5);         // LED OFF
    }
}
}
    }
  
