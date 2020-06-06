
int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)
int estado = 'c';         // inicia detenido


void setup()  { 
  Serial.begin(9600);    // comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  

} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='a'){           // Boton desplazar al Frente
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);       
  }
  if(estado=='b'){          // Boton IZQ 
    analogWrite(derB, vel);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);      
  }
  if(estado=='c'){         // Boton Parar
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0); 
  }
  if(estado=='d'){          // Boton DER
    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);  
  } 

  if(estado=='e'){          // Boton Reversa
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);      
  }
  //---------------------------------------------------------------------
  if(estado=='w'){          // Boton Cuadro
    delay(800);
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);

    delay(800);
    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);
    estado = 'c'; 
  }   

  if(estado=='q'){          // Boton Triangulo
    
   
    
    delay(1000);
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);


    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(800);

    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);
    delay(1000); 
    estado = 'c'; 
  } 

  if(estado=='r'){          // Boton circulo
    
    
    
    analogWrite(derB, 0);     
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel); 
    delay(3000);
    estado = 'c'; 
    
    
  } 
  
  
}
