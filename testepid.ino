float kp;
  float kd;
  float error_passado;
  int vbase = 20;
  error_passado = 0;

  while (1) {
    kp = 0, 5;
    kd = 0, 5;

    int leituraDireita = (analogRead(sensor[3]) - 400); 
    int leituraEsquerda = (analogRead(sensor[1]) - 400); 

    int err = leituraDireita - (leituraEsquerda);  // erro positivo -> robo a direita
    int d = err - error_passado;

    float pwme = 90 + vbase + err * kp + d * kd;
    float pwmd = 90 - vbase + err * kp + d * kd;

    Serial.print(err);
    Serial.print(",");
    Serial.println(d);

    // servoDir_f.write(pwmd);
    // servoDir_t.write(pwmd);

    // servoEsq_f.write(pwme);
    // servoEsq_t.write(pwme);


    error_passado = err;

    Serial.print(pwme);
    Serial.print(" / ");
    Serial.println(pwmd); 
    Serial.print(leituraEsquerda);
    Serial.print(" / ");
    Serial.println(leituraDireita); 
  }
