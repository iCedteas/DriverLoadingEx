#pragma once
#include <windows.h>
#include <winioctl.h>
#include <io.h>

#define DRIVER_NAME L"\\\\.\\SLoaderCtl"

#define PATCHCILOAD CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define LOADING CTL_CODE(FILE_DEVICE_UNKNOWN, 0x820, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define LOADINGEX CTL_CODE(FILE_DEVICE_UNKNOWN, 0x830, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define UNLOAD CTL_CODE(FILE_DEVICE_UNKNOWN, 0x840, METHOD_BUFFERED, FILE_ANY_ACCESS)

// PATCHCILOAD ENTRY
typedef struct _PATCHCILOAD_ENTRY
{
	PCWSTR sysName;
	INT loadMode;
}PATCHCILOAD_ENTRY, * PPATCHCILOAD_ENTRY;

class SLoadingEx
{
public:
	SLoadingEx();
	~SLoadingEx();

	VOID Loading(PCTSTR pSys);
	VOID LoadingEx(PCTSTR pSys);
	VOID PatchLoading(PPATCHCILOAD_ENTRY pPatchLoadEntry);
	VOID UnloadDriver(PCWSTR pSysName);

private:
	HANDLE g_hDevice;
	VOID Send(DWORD code, PVOID p, DWORD buffSize);
	VOID InitDriverControls();
};