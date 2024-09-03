kp = 0,2;
kd = 0,2;
error_passado = 0;

while (true) {

    int leituraDireita = analogRead(REDIR);
    int leituraEsquerda = analogRead(RESQ);

    int err = leituraDireita - leituraEsquerda; // erro positivo -> robo a direita
    int d = err - error_passado;
    
    float pwme = 90 + vbase + err * kp + d*kd;
    float pwmd = 90 - vbase + err * kp + d*kd;
    
    Serial.print(err);
    Serial.print(",");    Serial.println(d);

    servodf.write(pwmd);
    servodt.write(pwmd);

    servoef.write(pwme);
    servoet.write(pwme);


  error_passado = err;
  }
