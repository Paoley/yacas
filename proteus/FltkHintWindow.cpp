
#include <FL/Fl.H>
#include <FL/fl_draw.h>
#include "FltkHintWindow.h"

FltkHintWindow::FltkHintWindow(int aTextSize)
    : iNrLines(0), iNrDescriptions(0), iMaxWidth(0), iTextSize(aTextSize)
{
}
void FltkHintWindow::AddLine(LispCharPtr aText)
{
    iText[iNrLines] = aText;

    fl_font(FL_HELVETICA,iTextSize);
    int width = (int)fl_width(iText[iNrLines]);
    if (width>iMaxWidth)
        iMaxWidth = width;
    iNrLines++;
}

void FltkHintWindow::AddDescription(LispCharPtr aText)
{
    iDescription[iNrDescriptions] = aText;

    fl_font(FL_HELVETICA_BOLD,iTextSize);
    int width = (int)fl_width(iDescription[iNrDescriptions]);
    if (width>iMaxWidth)
        iMaxWidth = width;
    iNrDescriptions++;
}


void FltkHintWindow::draw(int x, int y)
{
    int ix = x;
    int iy = y;
    int w = 5+iMaxWidth;
    int h;

    fl_font(FL_HELVETICA,iTextSize);
    iy -= iNrLines*fl_height();
    h = iNrLines*fl_height()+2;

    if (iNrDescriptions)
    {
      fl_font(FL_HELVETICA_BOLD,iTextSize);
      h += iNrDescriptions*fl_height()+2;
      iy -= iNrDescriptions*fl_height();

      // space for line
      h+=7;
      iy -= 7; 
    }
    fl_color(FL_YELLOW);
    fl_rectf(ix,iy,w,h);
    fl_color(FL_BLUE);
    fl_rect(ix,iy,w,h);

    int i;
    fl_font(FL_HELVETICA,iTextSize);
    for (i=0;i<iNrLines;i++)
    {
        fl_draw(iText[i],ix+2,iy+(i+1)*fl_height()-fl_descent());
    }

    if (iNrDescriptions)
    {
      int offset = (iNrLines+1)*fl_height()+7;
      
      fl_line(ix+6,iy+offset-4-fl_height(),ix+w-6,iy+offset-4-fl_height());
      
      fl_font(FL_HELVETICA_BOLD,iTextSize);
      for (i=0;i<iNrDescriptions;i++)
      {
          fl_draw(iDescription[i],ix+2,iy+offset+(i)*fl_height()-fl_descent());
      }
    }
}

