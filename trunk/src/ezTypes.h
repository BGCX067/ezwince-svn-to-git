//////////////////////////////////////////////////////////////////////////
// 文件名称: ezTypes.h
// 文件表示: ezWindow所使用的类型定义
// 摘    要: 
// License:  GNU Lesser General Public License V 2.1
//	     http://www.opensource.org/licenses/lgpl-2.1.php
//
// 当前版本: 0.1.1
// 作    者: 尹曙光( kevdmx@sina.com )
// 完成日期: 2007-05-06
// 修订原因: 新建，按照ezWinCE整体规划 0.1版本改进
//////////////////////////////////////////////////////////////////////////

#ifndef __EZ_WINDOWS_TYPES_H__
#define __EZ_WINDOWS_TYPES_H__

#include <windows.h>
#include "ezDefines.h"
#include "ezMath.h"

class ezSize;
class ezRealPoint;
class ezPoint;
//class ezRect;

//////////////////////////////////////////////////////////////////////////////
//ezSize

class ezSize : public tagSIZE
{
public:

	// Constructors
	// construct an uninitialized size
	ezSize();
	// create from two integers
	ezSize(long initCX, long initCY);
	// create from another size
	ezSize(SIZE initSize);
	// create from a point
	ezSize(POINT initPt);
	// create from a DWORD: cx = LOWORD(dw) cy = HIWORD(dw)
	ezSize(DWORD dwSize);

	// Operations
	BOOL operator==(SIZE size) const;
	BOOL operator!=(SIZE size)  const;

	ezSize operator+(const SIZE& size) const;
	ezSize operator-(const SIZE& size) const;
	ezSize operator/(long i) const;
	ezSize operator*(long i) const;

	// Operators returning CSize values
	ezSize& operator+=(const SIZE& size);
	ezSize& operator-=(const SIZE& size);
	/*CSize operator-() const throw();*/
	ezSize& operator/=(const long i) ;
	ezSize& operator*=(const long i) ;
	
	// Operators returning CPoint values
	ezPoint operator+(POINT &point) const;
	ezPoint operator-(POINT &point) const;

	/*// Operators returning CRect values
	ezRect operator+(const RECT* lpRect) const throw();
	ezRect operator-(const RECT* lpRect) const throw();*/

	void IncTo(const SIZE& size);
	void DecTo(const SIZE& size);

	void IncBy(long dx, long dy);
	void IncBy(const SIZE& size);
	void IncBy(long d);

	void DecBy(long dx, long dy);
	void DecBy(const SIZE& size);
	void DecBy(long d) ;


	ezSize& Scale(float xscale, float yscale);
	// accessors
	void SetValue(long CX, long CY);
	void SetWidth(long w) ;
	void SetHeight(long h);

	long GetWidth() const;
	long GetHeight() const;
};

//////////////////////////////////////////////////////////////////////////////
//ezRealPoint

class ezRealPoint
{
public:
	double x;
	double y;

	ezRealPoint();
	ezRealPoint(double initX, double initY);

	ezRealPoint operator+(const ezRealPoint& pt) const ;
	ezRealPoint operator-(const ezRealPoint& pt) const ;

	BOOL operator==(const ezRealPoint& pt) const;
	BOOL operator!=(const ezRealPoint& pt) const;
};


/////////////////////////////////////////////////////////////////////////////
// CPoint - A 2-D point, similar to Windows POINT structure.

class ezPoint : public tagPOINT
{
public:
	// create an uninitialized point
	ezPoint();
	// create from two integers
	ezPoint(long initX, long initY);
	// create from another point
	ezPoint(POINT initPt);
	// create from a size
	ezPoint(SIZE initSize);
	// create from an LPARAM: x = LOWORD(dw) y = HIWORD(dw)
	ezPoint(LPARAM dwPoint);


	// comparison
	BOOL operator==(const POINT& p) const;
	BOOL operator!=(const POINT& p) const;

	// arithmetic operations (component wise)
	// Operators returning CPoint values
	ezPoint operator+(const POINT& p) const;
	ezPoint operator-(const POINT& p) const;
	ezPoint operator+(const SIZE &sz) const;
	ezPoint operator-(const SIZE &sz) const;

	ezPoint& operator+=(const POINT& p);
	ezPoint& operator-=(const POINT& p);

	ezPoint& operator+=(const SIZE& s);
	ezPoint& operator-=(const SIZE& s);	

	ezPoint operator-() const;

	// Operations
	// translate the point
	void Offset(long xOffset, long yOffset);
	void Offset(POINT point);
	void Offset(SIZE size);

	void SetPoint(long X, long Y);

	/*// Operators returning CRect values
	ezSize operator+(const RECT* lpRect) const throw();
	ezSize operator-(const RECT* lpRect) const throw();*/
};

//////////////////////////////////////////////////////////////////////////
// CRect - A 2-D rectangle, similar to Windows RECT structure.

class ezRect : public tagRECT
{
	// Constructors
public:
	// uninitialized rectangle
	ezRect();
	// from left, top, right, and bottom
	ezRect(long l, long t, long r, long b);
	// copy constructor
	ezRect(const RECT& srcRect) ;
	// from a pointer to another rect
	ezRect(LPCRECT lpSrcRect) ;
	// from a point and size
	ezRect(POINT &point, SIZE &size) ;
	// from two points
	ezRect(POINT &topLeft, POINT &bottomRight);
	ezRect(const SIZE& size);
	
	// Attributes (in addition to RECT members)	
	int GetLeft() const;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetLeft(long l) ;

	int GetTop() const ;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetTop(long t) ;

	int GetBottom() const ;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetBottom(long b) ;

	int GetRight()  const ;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetRight(long r) ;

	int GetWidth() const;
	void SetWidth(long w);

	int GetHeight() const;
	void SetHeight(long h);

	// returns TRUE if rectangle has no area
	BOOL IsRectEmpty() const ;
	// returns TRUE if rectangle is at (0,0) and has no area
	BOOL IsRectNull() const;

	ezPoint GetPosition() const;
	void SetPosition( const ezPoint &p );

	ezSize GetSize() const ;
	void SetSize( const SIZE &s );	

	ezPoint GetTopLeft() const;
	void SetTopLeft(const POINT &p);

	ezPoint GetBottomRight() const;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetBottomRight(const POINT &p) ;

	ezPoint GetTopRight() const;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetTopRight(const POINT &p) ;

	ezPoint GetBottomLeft() const;
	//注：该方法没有有效性校验，可能会破坏矩形的数据正确性
	//调用NormalizeRect()方法可以保证数据的正确性
	void SetBottomLeft(const POINT &p);

	// the geometric center point of the rectangle
	ezPoint GetCenterPoint() const;

	// swap the left and right
	void SwapLeftRight();
	static void WINAPI SwapLeftRight(LPRECT lpRect);

	void SwapTopBottom();
	static void WINAPI SwapTopBottom(LPRECT lpRect);

	//在进行一些设置之后，可能矩形的数据已经是无效的（不是错误，因为任何的两点都能组成一个矩形）
	//调用此方法能保证left<right,top<bottom
	void NormalizeRect();
	
	// return true if the point is (not strcitly) inside the rect
	BOOL Contains(long x, long y) const;
	BOOL Contains(POINT pt) const ;
	// return true if the rectangle is (not strcitly) inside the rect
	BOOL Contains(const RECT& rect) const;

	// set rectangle from left, top, right, and bottom
	void SetRect(long left, long top, long right, long bottom);
	void SetRect(POINT topLeft, POINT bottomRight);
	// empty the rectangle
	void SetRectEmpty();
	// copy from another rectangle
	void CopyRect(LPCRECT lpSrcRect);
	// TRUE if exactly the same as another rectangle
	BOOL EqualRect(LPCRECT lpRect);

	// translate the rectangle by moving its top and left
	void OffsetRect(long x, long y);
	void OffsetRect(SIZE size);
	void OffsetRect(POINT pt);

	// absolute position of rectangle
	void MoveToY(long y);
	void MoveToX(long x) ;
	void MoveToXY(long x, long y);
	void MoveToXY(POINT point);

	ezRect& Union(const RECT& rect);
	ezRect Union(const RECT& rect) const;
	
	// compare rectangles
	BOOL operator==(const RECT& rect) const;
	BOOL operator!=(const RECT& rect) const;
	ezRect operator+(const ezRect& rect) const;

	/*TODO:可参考MFC和wxWidgets设计关于矩形的缩放操作*/
};



#endif //_Z_WINDOWS_TYPES_H__