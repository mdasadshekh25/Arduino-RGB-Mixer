#define R_LED 9
#define G_LED 10
#define B_LED 11

#define R_POT A2
#define G_POT A1
#define B_POT A0

uint16_t r_value = 0, g_value = 0, b_value = 0;

void setup() {
    pinMode(R_LED, OUTPUT);
    pinMode(G_LED, OUTPUT);
    pinMode(B_LED, OUTPUT);

    pinMode(R_POT, INPUT);
    pinMode(G_POT, INPUT);
    pinMode(B_POT, INPUT);

    Serial.begin(115200);
    Serial.println("RGB Light Asad Initialized");

    // //LEDs off initially
    // analogWrite(R_LED, 255);
    // analogWrite(G_LED, 255);
    // analogWrite(B_LED, 255);
    // delay(1000);

    // // Red LED test
    // analogWrite(R_LED, 150);
    // delay(1000);
    // analogWrite(R_LED, 255);

    // // Green LED test
    // analogWrite(G_LED, 150);
    // delay(1000);
    // analogWrite(G_LED, 255);

    // // Blue LED test
    // analogWrite(B_LED, 150);
    // delay(1000);
    // analogWrite(B_LED, 255);
}

void loop() {
    r_value = map(analogRead(R_POT), 0, 1023, 255, 0); // Scale to 0-1023
    g_value = map(analogRead(G_POT), 0, 1023, 255, 0); // Scale to 0-1023
    b_value = map(analogRead(B_POT), 0, 1023, 255, 0); // Scale to 0-1023

    analogWrite(R_LED, r_value);
    analogWrite(G_LED, g_value);
    analogWrite(B_LED, b_value);

    Serial.print("R: ");
    Serial.print(r_value);
    Serial.print(" G: ");
    Serial.print(g_value);
    Serial.print(" B: ");
    Serial.println(b_value);
    delay(20);
}