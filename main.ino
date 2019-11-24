/*
Pino 0 = Clock.
Pino 1 = Latch.
Pino 2 = Serial IN.
*/

void setup()
{
   for (byte i = 0; i < 3; i++)//Declaração dos pinos de saida.
   {
      pinMode(i, OUTPUT);
   }

   int x = 1;
   for (byte i = 0; i < 8; i++)//Ligamos um LED após o outro, permanecendo o estado do anterior.
   {
      s595(x);//Função que faz o gerencimento do registrador.
      x = (x * 2) + 1;//Conta binaria que faz BitShift: 0b001 -> 0b011 -> 0b111...
      delay(150);
   }
}

void loop()
{
   s595(random(0, 256));
   delay(500);
}

void s595(byte data)//O argumento para acender os LEDs pode ser em binario
{
   digitalWrite(1, LOW);//Fecha o Latch para input de dados.
   shiftOut(2, 0, LSBFIRST, data);//Função própria da Arduino IDE.
   digitalWrite(1, HIGH);//Abre o Latch para output dos dados.
}
