/* effort */
#include <Q2HX711.h>
int masse;
const byte hx711_data_pin = 23;
const byte hx711_clock_pin = 18;
Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);

/* inductif */
const int capteur_inductif = 13;
bool est_inductif;

/* SETUP */
void setup() {
	Serial.begin(9600);

	pinMode(capteur_inductif, INPUT);
}

/* LOOP */
void loop() {
	while (test_effort() <= 0)
		Serial.println("en attente de ta mere");

	if (test_inductif() == true)
		Serial.println("metal");

	if (test_effort() <= 125)
		Serial.println("plastique");

	else
		Serial.println("verre");

}

int test_effort() {
	masse = ((hx711.read()/100-84406)/10)-666;
	return masse;
}

bool test_inductif() {
	if (digitalRead(capteur_inductif) == 1)
		est_inductif = true;
	else
		est_inductif = false;

	return est_inductif;
}