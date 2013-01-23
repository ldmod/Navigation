#pragma once
#include "DShow.h"
#include <InitGuid.h>
#include "FilterUIDs.h"
#include <atlcomcli.h>

#ifndef WM_GRAPHNOTIFY
#define WM_GRAPHNOTIFY (WM_APP + 100)
#endif

class CDXFilterGraphTea
{
public:
	CDXFilterGraphTea();

	HRESULT Create();
	HRESULT BuildGraph(BOOL bDisplay);
	HRESULT SetDisplayWindow(HWND windowHandle);
	HRESULT SetNotifyWindow(HWND windowHandle);
	

	HRESULT Run();
	HRESULT Stop();

	IMediaEventEx * GetEventHandle();

	HRESULT Destroy();

	//
	// --- ITrackingControl Interface --
	//
	HRESULT StartTracking();
	HRESULT StopTracking();

private:
	HRESULT init();

	CComPtr<IGraphBuilder> m_pGraphBuilder;
	CComPtr<IMediaControl> m_pMediaControl;
	CComPtr<IMediaEventEx> m_pMediaEvent;
	CComPtr<IVideoWindow> m_pVideoWindow;
	CComPtr<IBasicVideo> m_pBasicVideo;
	CComPtr<ITrackingControl> m_pTrackingControl;

	HWND m_hDisplayWnd;
	BOOL m_bDisplay;
};