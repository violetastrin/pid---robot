while (true) {

    int leituraDireita = analogRead(REDIR);
    int leituraEsquerda = analogRead(RESQ);

    int err = leituraDireita - leituraEsquerda; // erro positivo -> robo a direita
    int d = err - error_passado;
    
    float saidaEsquerda = 90 + vbase - err * kp - d*kd;
    float saidaDireita = 90 - vbase - err * kp - d*kd;
    
    Serial.print(err);
    Serial.print(",");    Serial.println(d);

    servodf.write(saidaDireita);
    servodt.write(saidaDireita);

    servoef.write(saidaEsquerda);
    servoet.write(saidaEsquerda);


  error_passado = err;
  }
