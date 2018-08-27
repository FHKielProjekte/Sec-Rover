byte PWM_PIN_HALL_1 = 3;
byte PWM_PIN_HALL_2 = 5;
byte PWM_PIN_HALL_3 = 6;
byte PWM_PIN_HALL_4 = 9;
 
int pwm_value_hall_1;
int pwm_value_hall_2;
int pwm_value_hall_3;
int pwm_value_hall_4;

float geschwindigkeit_1;
float geschwindigkeit_2;
float geschwindigkeit_3;
float geschwindigkeit_4;

int geschwindigkeit;

float umfang = 0.06;
 
void setup() {
  pinMode(PWM_PIN_HALL_1, INPUT);
  pinMode(PWM_PIN_HALL_2, INPUT);
  pinMode(PWM_PIN_HALL_3, INPUT);
  pinMode(PWM_PIN_HALL_4, INPUT);
  Serial.begin(115200);
}
 
void loop() {
  pwm_value_hall_1 = pulseIn(PWM_PIN_HALL_1, HIGH);
  pwm_value_hall_2 = pulseIn(PWM_PIN_HALL_2, HIGH);
  pwm_value_hall_3 = pulseIn(PWM_PIN_HALL_3, HIGH);
  pwm_value_hall_4 = pulseIn(PWM_PIN_HALL_4, HIGH);
  
  geschwindigkeit_1=pwm_value_hall_1*umfang*3.6;
  geschwindigkeit_2=pwm_value_hall_2*umfang*3.6;
  geschwindigkeit_3=pwm_value_hall_3*umfang*3.6;
  geschwindigkeit_4=pwm_value_hall_4*umfang*3.6;
  
  delay(1000);
  Serial.println(pwm_value_hall_1);
  //Serial.println(pwm_value_hall_2);
  //Serial.println(pwm_value_hall_3);
  //Serial.println(pwm_value_hall_4);

  geschwindigkeit=(geschwindigkeit_1+geschwindigkeit_2+geschwindigkeit_3+geschwindigkeit_4)/4;

  Serial.println(geschwindigkeit);
  Serial.write(geschwindigkeit);
  
}
