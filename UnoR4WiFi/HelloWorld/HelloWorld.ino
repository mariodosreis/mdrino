/* HelloWorld: Print the classical "Hello, World!" message to the Serial
 * Monitor. */
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hello, World!");
  delay(10000);
}