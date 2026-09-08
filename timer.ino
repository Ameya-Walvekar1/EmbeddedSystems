volatile unsigned long overflowCount = 0;
volatile unsigned int msCount = 0;

volatile unsigned long frequency = 0;
volatile bool newReading = false;

void setup()
{
  Serial.begin(9600);

  pinMode(5, INPUT);       // D5 = T1 external counter input

  // ---------------- TIMER1 ----------------
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // Enable Timer1 overflow interrupt
  TIMSK1 |= (1 << TOIE1);

  // External clock on T1 pin (D5), rising edge
  TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);

  // CS12 CS11 CS10 = 111
  // External clock source on T1 pin, rising edge

  // ---------------- TIMER2 ----------------
  // Timer2 creates accurate 1 ms timing interval

  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  // CTC mode
  TCCR2A |= (1 << WGM21);

  // For 1 ms:
  // 16 MHz / 64 = 250 kHz
  // Timer period = 4 us
  // 250 counts = 1 ms
  OCR2A = 249;

  // Timer2 prescaler = 64
  TCCR2B |= (1 << CS22);

  // Enable Timer2 compare interrupt
  TIMSK2 |= (1 << OCIE2A);

  Serial.println("External Frequency Counter");
  Serial.println("Connect signal to D5 (T1 pin)");
}

ISR(TIMER1_OVF_vect)
{
  overflowCount++;
}

ISR(TIMER2_COMPA_vect)
{
  msCount++;

  if (msCount >= 1000)
  {
    TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));

    frequency =
        (overflowCount * 65536UL) + TCNT1;

    TCNT1 = 0;
    overflowCount = 0;
    msCount = 0;

    newReading = true;

    TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);
  }
}

void loop()
{
  if (newReading)
  {
    noInterrupts();

    unsigned long f = frequency;
    newReading = false;

    interrupts();

    Serial.print("Frequency = ");
    Serial.print(f);
    Serial.println(" Hz");
  }
}