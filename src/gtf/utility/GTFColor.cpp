//
//  GTFColor.cpp
//  gtf
//
//  Created by David Gallardo on 30/05/16.
//  Copyright (c) 2016 GTF Development Group. All rights reserved.
//

#include "GTFColor.h"
#include <cmath>

GTFColor::GTFColor()
: r(0.0f)
, g(0.0f)
, b(0.0f)
, a(0.0f)
{
    
}

/*GTFColor::GTFColor(float rgb)
{
    r = g = b = rgb;
    a = 1.0f;
}*/

GTFColor::GTFColor(float red, float green, float blue, float alpha)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

GTFColor::GTFColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    r = red / 255.0f;
    g = green / 255.0f;
    b = blue / 255.0f;
    a = alpha / 255.0f;
}

GTFColor::GTFColor(unsigned int hexARGB)
{
    a = (hexARGB >> 24) / 255.0f;
    r = ((hexARGB >> 16) & 0xFF) / 255.0f;
    g = ((hexARGB >> 8) & 0xFF) / 255.0f;
    b = (hexARGB & 0xFF) / 255.0f;
}

float* GTFColor::asF32A(float* color, bool includeAlpha)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
    
    if (includeAlpha)
        color[3] = a;
    
    return color;
}

unsigned int GTFColor::asHEX( bool includeAlpha)
{
    unsigned int uiR = r * 255, uiG = g * 255, uiB = b * 255, uiA = a * 255;
    
    return (includeAlpha * uiA << 24) + (uiR << 16) + (uiG << 8) + uiB;
}

unsigned char* GTFColor::asU8A(unsigned char* color, bool includeAlpha)
{
    color[0] = floor(r * 255);
    color[1] = floor(g * 255);
    color[2] = floor(b * 255);
    
    if (includeAlpha)
        color[3] = floor(a * 255);
    
    return color;
}