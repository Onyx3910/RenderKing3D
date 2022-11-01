#pragma once

//***************************************************************************************
//	Code inspired by from d3dApp.h by Frank Luna (C) 2015 All Rights Reserved.
//***************************************************************************************

// Link necessary d3d12 libraries.
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

namespace Renderer
{
	class RENDERKING_API d3dxContext
	{
	public:
		bool Get4xMsaaState() const;
		VOID Set4xMsaaState(bool value);
		VOID CalculateFrameStats(Common::Timer* timer);
		virtual VOID Draw(FLOAT deltaTime);
		virtual VOID OnResize(SIZE size);
		virtual bool Initialize(Win32::Window* window);

	protected:
		Win32::Window* m_Window;

		virtual VOID CreateRtvAndDsvDescriptorHeaps();

	protected:
		bool InitDirect3D();
		VOID CreateCommandObjects();
		VOID CreateSwapChain();

		VOID FlushCommandQueue();

		ID3D12Resource* CurrentBackBuffer() const;
		D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView() const;
		D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView() const;

		VOID LogAdapters();
		VOID LogAdapterOutputs(IDXGIAdapter* adapter);
		VOID LogOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format);

		bool	  m_Initialized = false;

		bool      m4xMsaaState = false;    // 4X MSAA enabled
		UINT      m4xMsaaQuality = 0;      // quality level of 4X MSAA

		Microsoft::WRL::ComPtr<IDXGIFactory4> mdxgiFactory;
		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
		Microsoft::WRL::ComPtr<ID3D12Device> md3dDevice;

		Microsoft::WRL::ComPtr<ID3D12Fence> mFence;
		UINT64 mCurrentFence = 0;

		Microsoft::WRL::ComPtr<ID3D12CommandQueue> mCommandQueue;
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> mDirectCmdListAlloc;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> mCommandList;

		static const INT SwapChainBufferCount = 2;
		INT mCurrBackBuffer = 0;
		Microsoft::WRL::ComPtr<ID3D12Resource> mSwapChainBuffer[SwapChainBufferCount];
		Microsoft::WRL::ComPtr<ID3D12Resource> mDepthStencilBuffer;

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mRtvHeap;
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mDsvHeap;

		D3D12_VIEWPORT mScreenViewport;
		D3D12_RECT mScissorRect;

		UINT mRtvDescriptorSize = 0;
		UINT mDsvDescriptorSize = 0;
		UINT mCbvSrvUavDescriptorSize = 0;

		// Derived class should set these in derived constructor to customize starting values.
		D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;
		DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
		DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

	public:
		bool Initialized() { return m_Initialized; }
	};
}

