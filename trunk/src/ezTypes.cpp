
#include "ezTypes.h"

//////////////////////////////////////////////////////////////////////////

ezSize::ezSize()
{
	this->cx = 0;
	this->cy = 0;

}

ezSize::ezSize(long initCX, long initCY)
{
	this->cx = initCX;
	this->cy = initCY;
}

ezSize::ezSize(SIZE initSize) 
{	
	this->cx = initSize.cx;
	this->cy = initSize.cy;
}

ezSize::ezSize(POINT initPt)
{
	this->cx = initPt.x;
	this->cy = initPt.y;
}

// create from a DWORD: cx = LOWORD(dw) cy = HIWORD(dw)
ezSize::ezSize(DWORD dwSize) 
{ 
	this->cx = LOWORD(dwSize);
	this->cy = HIWORD(dwSize);
}


BOOL 
ezSize::operator==(SIZE size) const
{
	return this->cx == size.cx && this->cy == size.cy; 
}

BOOL 
ezSize::operator!=(SIZE size) const
{ 
	return cx != size.cx || cy != size.cy; 
}

ezSize 
ezSize::operator+(const SIZE& size)  const
{ 
	return ezSize(cx + size.cx, cy + size.cy);
}

ezSize 
ezSize::operator-(const SIZE& size) const
{ 
	return ezSize(cx - size.cx, cy - size.cy); 
}

ezSize 
ezSize::operator/(long i) const
{ 
	return ezSize(cx / i, cy / i); 
}

ezSize 
ezSize::operator*(long i) const
{ 
	return ezSize(cx * i, cy * i); 
}

ezSize& 
ezSize::operator+=(const SIZE& size) 
{ 
	cx += size.cx;
	cy += size.cy; 
	return *this;
}

ezSize& 
ezSize::operator-=(const SIZE& size) 
{ 
	cx -= size.cx; 
	cy -= size.cy; 
	return *this; 
}

ezSize& 
ezSize::operator/=(const long i) 
{ 
	cx /= i; 
	cy /= i; 
	return *this; 
}

ezSize& 
ezSize::operator*=(const long i) 
{ 
	cx *= i; 
	cy *= i; 
	return *this; 
}

ezPoint 
ezSize::operator+(POINT &point) const
{
	return ezPoint(cx + point.x, cy + point.y); 
}

ezPoint 
ezSize::operator-(POINT &point) const
{
	return ezPoint(cx - point.x, cy - point.y); 
}

void 
ezSize::IncTo(const SIZE& size)
{ 
	if ( size.cx > cx ) 
		cx = size.cx; 
	if ( size.cy > cy ) 
		cy = size.cy; 
}

void 
ezSize::DecTo(const SIZE& size)
{ 
	if ( size.cx < cx ) 
		cx = size.cx; 
	if ( size.cy < cy ) 
		cy = size.cy;
}

void 
ezSize::IncBy(long dx, long dy) 
{ 
	cx += dx; 
	cy += dy; 
}

void 
ezSize::IncBy(const SIZE& size)
{ 
	IncBy(size.cx, size.cy); 
}

void 
ezSize::IncBy(long d) 
{ 
	IncBy(d, d); 
}

void 
ezSize::DecBy(long dx, long dy) 
{ 
	IncBy(-dx, -dy); 
}

void 
ezSize::DecBy(const SIZE& size) 
{ 
	DecBy(size.cx, size.cy); 
}

void 
ezSize::DecBy(long d) 
{ 
	DecBy(d, d); 
}


ezSize& 
ezSize::Scale(float xscale, float yscale)
{ 
	cx = (long)(cx*xscale); 
	cy = (long)(cy*yscale);
	return *this; 
}

// accessors
void 
ezSize::SetValue(long CX, long CY) 
{ 
	cx = CX; 
	cy = CY; 
}

void 
ezSize::SetWidth(long w) 
{ 
	cx = w; 
}

void 
ezSize::SetHeight(long h) 
{ 
	cy = h;
}

long 
ezSize::GetWidth() const
{ 
	return cx; 
}

long 
ezSize::GetHeight() const
{ 
	return cy; 
}


//////////////////////////////////////////////////////////////////////////

ezRealPoint::ezRealPoint() 
{
	this->x = 0.0;
	this->y = 0.0;
}

ezRealPoint::ezRealPoint(double initX, double initY) 
{
	this->x = initX;
	this->y = initY;
}

ezRealPoint 
ezRealPoint::operator+(const ezRealPoint& pt) const
{ 
	return ezRealPoint(x + pt.x, y + pt.y); 
}

ezRealPoint 
ezRealPoint::operator-(const ezRealPoint& pt) const 
{ 
	return ezRealPoint(x - pt.x, y - pt.y); 
}

BOOL 
ezRealPoint::operator==(const ezRealPoint& pt) const
{
	return ezIsSameDouble(x, pt.x) && ezIsSameDouble(y, pt.y);
}

BOOL 
ezRealPoint::operator!=(const ezRealPoint& pt) const 
{ 
	return !(*this == pt); 
}

//////////////////////////////////////////////////////////////////////////
// create an uninitialized point

ezPoint::ezPoint() 
{
	this->x = 0;
	this->y = 0;
}

// create from two integers
ezPoint::ezPoint(long initX, long initY) 
{
	this->x = initX;
	this->y = initY;
}
// create from another point
ezPoint::ezPoint(POINT initPt) 
{
	this->x = initPt.x;
	this->y = initPt.y;
}
// create from a size
ezPoint::ezPoint(SIZE initSize)
{
	this->x = initSize.cx;
	this->y = initSize.cy;
}

// create from an LPARAM: x = LOWORD(dw) y = HIWORD(dw)
ezPoint::ezPoint(LPARAM dwPoint)
{
	this->x = LOWORD(dwPoint);
	this->y = HIWORD(dwPoint);
}


// comparison
BOOL 
ezPoint::operator==(const POINT& p) const 
{ 
	return x == p.x && y == p.y;
}

BOOL 
ezPoint::operator!=(const POINT& p) const 
{ 
	return !(*this == p); 
}

// arithmetic operations (component wise)
// Operators returning CPoint values
ezPoint 
ezPoint::operator+(const POINT& p) const
{ 
	return ezPoint(x + p.x, y + p.y); 
}

ezPoint 
ezPoint::operator-(const POINT& p) const 
{ 
	return ezPoint(x - p.x, y - p.y); 
}

ezPoint 
ezPoint::operator+(const SIZE& sz) const
{ 	
	return ezPoint(x + sz.cx, y + sz.cy); 
}

ezPoint 
ezPoint::operator-(const SIZE& sz) const 
{ 
	return ezPoint(x - sz.cx, y - sz.cy); 
}

ezPoint& 
ezPoint::operator+=(const POINT& p) 
{
	x += p.x; 
	y += p.y; 
	return *this; 
}

ezPoint& 
ezPoint::operator-=(const POINT& p) 
{ 
	x -= p.x; 
	y -= p.y; 
	return *this; 
}

ezPoint& 
ezPoint::operator+=(const SIZE& s) 
{ 
	x += s.cx; 
	y += s.cy; 
	return *this; 
}

ezPoint& 
ezPoint::operator-=(const SIZE& s) 
{ 
	x -= s.cx; 
	y -= s.cy; 
	return *this; 
}


ezPoint 
ezPoint::operator-() const 
{
	return ezPoint(-x, -y); 
}


void 
ezPoint::Offset(long xOffset, long yOffset)
{
	this->x+=xOffset;
	this->y+=yOffset;
}

void
ezPoint::Offset(POINT point)
{
	Offset(point.x,point.y);
}

void 
ezPoint::Offset(SIZE size)
{
	Offset(size.cx,size.cy);
}

void 
ezPoint::SetPoint(long X, long Y)
{
	x=X; 
	y=Y;
}

//////////////////////////////////////////////////////////////////////////
// uninitialized rectangle
ezRect::ezRect() 
{ 
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}

// from left, top, right, and bottom
ezRect::ezRect(long l, long t, long r, long b) 
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}

// copy constructor
ezRect::ezRect(const RECT& srcRect)  
{ 
	left = srcRect.left;
	top = srcRect.top;
	right = srcRect.right;
	bottom = srcRect.bottom;
}

// from a pointer to another rect
ezRect::ezRect(LPCRECT lpSrcRect)  
{ 
	left = lpSrcRect->left;
	top = lpSrcRect->top;
	right = lpSrcRect->right;
	bottom = lpSrcRect->bottom;
}

// from a point and size
ezRect::ezRect(POINT &point, SIZE &size) 
{
	left = point.x;
	top  = point.y;
	right = point.x+size.cx;
	bottom = point.y+size.cy;
}

// from two points
ezRect::ezRect(POINT &topLeft, POINT &bottomRight)
{
	SetRect(topLeft, bottomRight);
}

ezRect::ezRect(const SIZE& size)
{
	left = 0;
	top = 0;
	right = size.cx;
	bottom = size.cy;
}

int 
ezRect::GetLeft() const 
{ 
	return left; 
}
void 
ezRect::SetLeft(long l) 
{ 
	left = l;
}

int 
ezRect::GetTop() const 
{ 
	return top; 
}

void 
ezRect::SetTop(long t) 
{ 
	top = t; 
}

int 
ezRect::GetBottom() const 
{ 
	return bottom; 
}

void 
ezRect::SetBottom(long b) 
{
	bottom =b; 
}

int 
ezRect::GetRight()  const 
{ 
	return right; 
}

void 
ezRect::SetRight(long r) 
{ 
	right = r; 
}

int 
ezRect::GetWidth() const 
{ 
	return right-left; 
}

void 
ezRect::SetWidth(long w) 
{ 
	right = left+w; 
}

int 
ezRect::GetHeight() const 
{ 
	return bottom-top; 
}

void 
ezRect::SetHeight(long h) 
{ 
	bottom =top + h; 
}

BOOL 
ezRect::IsRectEmpty() const 
{ 
	return (right == left) || (bottom == top);
}

BOOL 
ezRect::IsRectNull() const 
{ 
	return (left == 0) && (top == 0) && IsRectEmpty(); 
}

ezPoint 
ezRect::GetPosition() const 
{ 
	return ezPoint(left, top); 
}

void
ezRect::SetPosition( const ezPoint &p )
{ 
	MoveToXY(p.x,p.y);
}

ezSize 
ezRect::GetSize() const
{ 
	return ezSize(right-left, bottom-top); 
}

void 
ezRect::SetSize( const SIZE &s )
{ 
	right = left + s.cx; 
	bottom = top + s.cy; 
}

ezPoint 
ezRect::GetTopLeft() const 
{ 
	return GetPosition(); 
}

void 
ezRect::SetTopLeft(const POINT &p) 
{ 
	SetPosition(p); 
}

ezPoint 
ezRect::GetBottomRight() const 
{ 
	return ezPoint(GetRight(), GetBottom()); 
}

//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
void 
ezRect::SetBottomRight(const POINT &p) 
{
	SetRight(p.x); 
	SetBottom(p.y); 
}

ezPoint 
ezRect::GetTopRight() const 
{ 
	return ezPoint(GetRight(), GetTop()); 
}

//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
void 
ezRect::SetTopRight(const POINT &p) 
{ 
	SetRight(p.x); 
	SetTop(p.y); 
}

ezPoint 
ezRect::GetBottomLeft() const 
{ 
	return ezPoint(GetLeft(), GetBottom());
}

//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
void 
ezRect::SetBottomLeft(const POINT &p) 
{ 
	SetLeft(p.x); 
	SetBottom(p.y);
}

ezPoint 
ezRect::GetCenterPoint() const
{
	return ezPoint(left + ( right-left) / 2, top + (bottom-top)/2);
}

void 
ezRect::SwapLeftRight()
{
	SwapLeftRight(this);
}

void 
ezRect::SwapLeftRight(LPRECT lpRect)
{
	int mid;
	mid = lpRect->left;
	lpRect->left = lpRect->right;
	lpRect->right = mid;
}

void 
ezRect::SwapTopBottom()
{
	SwapTopBottom(this);
}

void 
ezRect::SwapTopBottom(LPRECT lpRect)
{
	int mid;
	mid = lpRect->top;
	lpRect->top = lpRect->bottom;
	lpRect->bottom = mid;
}

void 
ezRect::NormalizeRect()
{
	if (left>right)
		SwapLeftRight();
	if (top>bottom)
		SwapTopBottom();
}

BOOL 
ezRect::Contains(long cx, long cy) const
{
	return ((cx>=left)&&(cx<=right)) 
		&& ((cy>=top)&&(cy<=bottom));
}

BOOL 
ezRect::Contains(POINT pt) const 
{ 
	return Contains(pt.x, pt.y); 
}

BOOL 
ezRect::Contains(const RECT& rect) const
{
	return Contains(rect.left,rect.top) && Contains(rect.right,rect.bottom);
}


void 
ezRect::SetRect(long l, long t, long r, long b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;

}
void 
ezRect::SetRect(POINT topLeft, POINT bottomRight)
{
	if (topLeft.x<bottomRight.x)
	{
		left = topLeft.x;
		right = bottomRight.x;
	}
	else
	{
		left = bottomRight.x;
		right = topLeft.x;
	}

	if(topLeft.y<bottomRight.y)
	{
		top = topLeft.y;
		bottom = bottomRight.y;
	}
	else
	{
		top = bottomRight.y;
		bottom = topLeft.y;
	}
}

void 
ezRect::SetRectEmpty()
{
	left=right=0; 
	top=bottom=0;
}

void 
ezRect::CopyRect(LPCRECT lpSrcRect)
{
	left = lpSrcRect->left;
	right = lpSrcRect->right;
	top = lpSrcRect->top;
	bottom = lpSrcRect->bottom;
}
BOOL 
ezRect::EqualRect(LPCRECT lpRect)
{
	return ( left == lpRect->left)
		&& ( right == lpRect->right)
		&& ( top == lpRect->top)
		&& ( bottom == lpRect->bottom);
}

void 
ezRect::OffsetRect(long x, long y)
{
	left += x;
	right += x;
	top += y;
	bottom += y;
}

void 
ezRect::OffsetRect(SIZE size) 
{ 
	OffsetRect(size.cx,size.cy); 
}

void 
ezRect::OffsetRect(POINT pt) 
{ 
	OffsetRect(pt.x,pt.y); 
}

void 
ezRect::MoveToY(long y) 
{ 
	MoveToXY(left,y); 
}

void 
ezRect::MoveToX(long x) 
{
	MoveToXY(x,top); 
}

void 
ezRect::MoveToXY(long x, long y) 
{
	bottom = y + bottom - top;
	right  = x + right - left;
	left = x; 
	top = y; 
}

void 
ezRect::MoveToXY(POINT point) 
{ 
	MoveToXY(point.x,point.y); 
}

ezRect& 
ezRect::Union(const RECT& rect)
{
	// ignore empty rectangles: union with an empty rectangle shouldn't extend
	// this one to (0, 0)
	if ( !(right-left) || !(bottom-top) )
	{
		*this = rect;
	}
	else if ( (right-left) && (bottom-top) )
	{
		left = (left<rect.left)?left:rect.left;
		top = (top<rect.top)?top:rect.top;
		right = (right>rect.right)?right:rect.right;
		bottom = (bottom>rect.bottom)?bottom:rect.bottom;		
	}
	//else: we're not empty and rect is empty
	return *this;
}

ezRect 
ezRect::Union(const RECT& rect) const
{
	ezRect r = *this;
	r.Union(rect);
	return r;
}

BOOL 
ezRect::operator==(const RECT& rect) const
{
	return ((left == rect.left) &&
		(top == rect.top) &&
		(right == rect.right) &&
		(bottom == rect.bottom));
}

BOOL 
ezRect::operator!=(const RECT& rect) const 
{ 
	return !(*this == rect); 
}

ezRect 
ezRect::operator+(const ezRect& rect) const
{
	return ezRect((left<rect.left)?left:rect.left,
		(top<rect.top)?top:rect.top,
		(right>rect.right)?right:rect.right,
		(bottom>rect.bottom)?bottom:rect.bottom);
}



