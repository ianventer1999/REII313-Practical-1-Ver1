#include "xor.h"

clXOR::clXOR(int iXval,int iYval,int iInputCount)
{
    this->setX(iXval);
    this->setY(iYval);
    this->iInputCount = iInputCount;
}

clXOR::~clXOR()
{

}

QRectF clXOR::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void clXOR::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(QRect(5,0,30,50),90*16,-180*16);
    painter->drawArc(QRect(0,0,30,50),90*16,-180*16);
    painter->drawArc(QRect(-40,0,120,50),90*16,-90*16);
    painter->drawArc(QRect(-40,0,120,50),-90*16,90*16);

    painter->drawLine(QLine(80,25,100,25));

    switch (iInputCount)
    {
        case 1:
        {
            painter->drawLine(QLine(0,25,30,25));
        }break;
        case 2:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 3:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,25,30,25));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 4:
        {
            painter->drawLine(QLine(0,10,27,10));
            painter->drawLine(QLine(0,20,29,20));
            painter->drawLine(QLine(0,30,29,30));
            painter->drawLine(QLine(0,40,27,40));
        }break;
        case 5:
        {
            painter->drawLine(QLine(0,5,24,5));
            painter->drawLine(QLine(0,15,28,15));
            painter->drawLine(QLine(0,25,30,25));
            painter->drawLine(QLine(0,35,28,35));
            painter->drawLine(QLine(0,45,24,45));
        }break;
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

bool clXOR::fDetermineOuptut()
{
   int  iTrueCounter = 0;

   for(auto b:clGate::bInputs)
   {
       if (b == true)
       {
            iTrueCounter++;
       }
   }

   if (iTrueCounter == 1) //Mag slegs 1 true he
   {
       return true;
   }
   else
   {
        return false;
   }
}

bool clXOR::fDetermineOuptut()
{
   auto a= this->clGate::bInputs;
    //Vir een of ander rede het die bInputs wat n Qlist is 10 Items wat nie waar is nie ??? gebruik maar net static sizes wat 2 iterasies tell
   for(int i= 0;i<a.size();++i)
    {
        for(int j= 0;j<a.size();++j)
        {
          if ((a[i]==a[j])&&(i!=j))
          {
             // clGate::bInputs.clear();
              return false;
          }
        }
    }
    /*for(int i= 0;i<2;++i)
        {
            for(int j= 0;j<2;++j)
            {
              if ((a[i]==a[j])&&(i!=j))
              {
                  return false;
              }
            }
        }*/
   // clGate::bInputs.clear();
    return true;

}


