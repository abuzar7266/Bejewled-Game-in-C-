#ifndef _SHAPE_H_
#define _SHAPE_H_
#include<iostream>
#include<fstream>
class Shape
{
	protected:
	int sx;
	int sy;
	int GemType;
	public:
	virtual void Draw()
	{

	}
	Shape()
	{
		sx = -1;
		sy = -1;
		GemType = -1;
	}
	void setAxis(int gx,int gy)
	{
		sx = gx;
		sy = gy;
		//WriteAxis(gx,gy);
	}
	int getx()const
	{
		return sx;	
	}
	int gety()const
	{
		return sx;	
	}
	void setx(int gx)
	{
		sx = gx;	
	}
	void sety(int gy)
	{
		sy = gy;	
	}
	int getGemType()const
	{
		return GemType;	
	}
	void setGemType(int i)
	{
		GemType = i;
	}
	void XIncrementAxis(int a)
	{
		sx+=a;
	}
	void XDecrementAxis(int a)
	{
		sx-=a;
	}
	void YIncrementAxis(int a)
	{
		sy+=a;
	}
	void YDecrementAxis(int a)
	{
		sy-=a;
	}
	void WriteAxis(int x,int y)
	{
		fstream Axis;
		Axis.open("SLocate.txt",ios::out|ios::app);
		string A = Num2Str(x) + " " + Num2Str(y) ;		
		Axis << A <<endl;
		Axis.close();
	}
};
class Diamond:public Shape
{
	public:
	virtual void Draw()
	{
		DrawTriangle(sx+2,sy+20,sx+44+2,sy+20,sx+22+2,sy+25+20,colors[BROWN]);
		DrawTriangle(sx+2,sy+20,sx+44+2,sy+20,sx+22+2,sy-25+20,colors[BROWN]);
		DrawTriangle(sx,sy+20,sx+44,sy+20,sx+22,sy+25+20,colors[RED]);
		DrawTriangle(sx,sy+20,sx+44,sy+20,sx+22,sy-25+20,colors[RED]);
		DrawLine(sx+2,sy+20,sx+44-2,sy+20,3,colors[TOMATO]);
		DrawLine(sx+22,sy-22+20,sx+22,sy+22+20,3,colors[TOMATO]);
	}
};
class Circle:public Shape{
	public:
	virtual void Draw()
	{
		DrawCircle(sx+25,sy+22,24,colors[BROWN]);
		int d =rand()%2;
		float *f = colors[GRAY];
		float *e = colors[SILVER];
		if(d==0)
		{
			f = colors[GRAY];
			e = colors[SILVER];
		}
		else
		{
			f = colors[SILVER];
			e = colors[GRAY];
		}
		DrawCircle(sx-1+25,sy+22,22,f);
		DrawCircle(sx-1+25,sy+22,19,e);	
	}
};
class Emerald:public Shape{
	public:
	virtual void Draw()
	{
		int rn = rand()%100+1;
		float *rnt = colors[SKY_BLUE];
		if(rn==7)
		rnt = colors[BLUE];
		DrawRoundRect(sx+2,sy,45,45,colors[BROWN],10);
		DrawRoundRect(sx+2,sy,42,42,colors[BLUE],10);
		DrawRoundRect(sx+2+10,sy+11,21,21,rnt,10);
		DrawTriangle(sx+2+10+3+2,sy+14+3,sx+2+10+3+10+2,sy+14+3,sx+2+10+3+5+2,sy+24+5,colors[BLUE]);
		glutPostRedisplay();
	}
};
class Triangle:public Shape{
	public:
	virtual void Draw()
	{
		DrawTriangle(sx+2,sy,sx+52-2,sy,sx+26-1,sy+48,colors[BROWN]);
		DrawTriangle(sx+2,sy+0,sx+50-2,sy+0,sx+25-1,sy+46,colors[STEEL_BLUE]);
		DrawTriangle(sx+2,sy+0,sx+50-2,sy+0,sx+25-1,sy+44,colors[STEEL_BLUE]);
		DrawTriangle(sx+18+2,sy+24+2-5,sx+32-2,sy+24+2-5,sx+26-1,sy+14-5,colors[DARK_SALMON]);
	}
};
class Asscher:public Shape{
	public:
	virtual void Draw()
	{
		srand(time(NULL));
		DrawTriangle(sx+5,sy+15+5+10+3,sx+45,sy+15+5+10+3,sx+25,sy-40+15+5+10+3,colors[BROWN]);
		DrawRoundRect(sx+5,sy-5+15+5+10+3,40,15,colors[BROWN],7);




		DrawTriangle(sx+5,sy+15+5+10+3,sx+45-4,sy+15+5+10+3,sx+25-2,sy-40+15+5+10+3,colors[MINT_CREAM]);
		DrawRoundRect(sx+5,sy-5+15+5+10+3,40-4,15,colors[MINT_CREAM],7);
		DrawSquare(sx+17,sy-15+15+5+10+3,15,colors[DARK_SALMON]);
		/*for(int i=0;i<15;i++)
		{
			for(int j = 0;j<15;j++)
			{
				int f=rand()%2;
				if(f%2==0)
				DrawSquare(sx+17+i,sy-15+15+j,1,colors[MINT_CREAM]);
			}
		}*/
		/*DrawLine(sx+6,sy+15,sx+41,sy+15,1,colors[GOLD]);
		DrawLine(sx+(41-6)/2+7,sy+15,sx+(41-6)/2+7,sy-38+15,1,colors[GOLD]);
		for(int i=0;i<4;i+=1)
		{
			int d = rand()%3;
			DrawLine(sx+8,sy+i*d+1+15,sx+38,sy+1+i*d+15,1,colors[DARK_GRAY]);
		}*/
	}
};
class HatchRose:public Shape{
	public:
	virtual void Draw()
	{
		cout<<"Draw HatchRose"<<endl;
	}
};
class Square:public Shape{
	public:
		virtual void Draw()
		{
			DrawSquare(sx+1+1,/*Y*/sy,47,colors[BROWN]);
			DrawSquare(sx+1,sy-1,45,colors[MAGENTA]);
			DrawSquare(sx+2+1+1,sy+2,40,colors[DARK_MAGENTA]);
			//DrawTriangle
			DrawTriangle(sx+1+2+10,sy+13,sx+1+20+10+2,sy+13,(1+10+10+2+sx),sy+33,colors[MAGENTA]);
		}

};
#endif
