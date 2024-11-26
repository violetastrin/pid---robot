float kp;
  float kd;
  float error_passado = 0;
  int vbase = 30;

  while (1) {
    kp = 0.2;
    kd = 0.5;

    int leituraDireita = (analogRead(sensor[3])); 
    int leituraEsquerda = (analogRead(sensor[1])); 

    int err = leituraEsquerda - (leituraDireita);  // erro positivo -> robo a direita
    int d = err - error_passado;

    float pwme = 90 + vbase + err * kp + d * kd;
    float pwmd = 90 - vbase + err * kp + d * kd;


    servoDir_f.write(pwmd);
    servoDir_t.write(pwmd);

    servoEsq_f.write(pwme);
    servoEsq_t.write(pwme);


    error_passado = err;

    Serial.print(pwme);
    Serial.print(" / ");
    Serial.println(pwmd); 
    Serial.println(err);

  }
