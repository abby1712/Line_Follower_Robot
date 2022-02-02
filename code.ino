int  LMT1=5,LMT2=3,RMT1=11,RMT2=6;
int  LS=A1, CS=A2, RS=A3,CSV,LSV,RSV,EXRSV,EXLSV;
void setup()
{
  pinMode(CS,INPUT);
  pinMode(LS,INPUT);
  pinMode(RS,INPUT);
  pinMode(A4,INPUT);
  pinMode(A0,INPUT);

  pinMode(LMT1,OUTPUT);
  pinMode(LMT2,OUTPUT);
  pinMode(RMT1,OUTPUT);
  pinMode(RMT2,OUTPUT);

}
void loop()
{
  EXRSV=digitalRead(A4);
  EXLSV=digitalRead(A0);
  CSV=digitalRead(A2);
  LSV=digitalRead(A1);
  RSV=digitalRead(A3);

  if(EXLSV==HIGH&&EXRSV==LOW)
  {
    left();
  } 

  else if(EXLSV==LOW&&EXRSV==HIGH)
  {
    right();
  } 
  else if(EXLSV==LOW&&EXRSV==LOW)
  {
    if(LSV==LOW&&CSV==HIGH&&RSV==LOW)
    {
      fwd();
    } 

    else if(LSV==HIGH&&CSV==LOW&&RSV==LOW)
    {
      stopleft();
    }
    else if(LSV==LOW&&CSV==LOW&&RSV==HIGH)
    {
      stopright();
    }
    else if(LSV==LOW&&CSV==HIGH&&RSV==HIGH)
    {
      slowright();
    }
    else if(LSV==HIGH&&CSV==HIGH&&RSV==LOW)
    {
      slowleft();

    }
    else if(LSV==HIGH&&CSV==LOW&&RSV==HIGH)
    {

      right();

    }

    else if(LSV==LOW&&CSV==LOW&&RSV==LOW)
    {
      fwd();
    }
    else if(LSV==HIGH&&CSV==HIGH&&RSV==HIGH)
    {
      fwd();
    }


  }  
}
void fwd()
{
  analogWrite(LMT1,255);
  analogWrite(LMT2,0);
  analogWrite(RMT1,255);
  analogWrite(RMT2,0);
}
void back()
{
  analogWrite(LMT1,0);
  analogWrite(LMT2,255);
  analogWrite(RMT1,0);
  analogWrite(RMT2,255);
}
void left()
{
  analogWrite(LMT1,0);
  analogWrite(LMT2,255);
  analogWrite(RMT1,255);
  analogWrite(RMT2,0);
}
void right()
{
  analogWrite(LMT1,255);
  analogWrite(LMT2,0);
  analogWrite(RMT1,0);
  analogWrite(RMT2,255);
}
void stopleft()
{
  analogWrite(LMT1,0);
  analogWrite(LMT2,0);
  analogWrite(RMT1,255);
  analogWrite(RMT2,0);
}
void stopright()
{
  analogWrite(LMT1,255);
  analogWrite(LMT2,0);
  analogWrite(RMT1,0);
  analogWrite(RMT2,0);
}
void slowright()
{
  analogWrite(LMT1,125);
  analogWrite(LMT2,0);
  analogWrite(RMT1,0);
  analogWrite(RMT2,255);
}
void slowleft()
{
  analogWrite(LMT1,125);
  analogWrite(LMT2,0);
  analogWrite(RMT1,255);
  analogWrite(RMT2,0);
}



