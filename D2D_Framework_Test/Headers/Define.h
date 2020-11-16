#pragma once

#define WINCX 800
#define WINCY 600

#define TILECX 48
#define TILECY 48

#define DLG_SPEED 40.f
#define ATTACK_DELAY_TIME 2.f			// ���� ���� �� �ɸ��� �ð�
#define ATTACK_GAUGE_REDUCE_TIME 1.f	// ���� ���� �� ������ ���� ���� �ð�
#define NEXT_PHASE_TIME 1.f

#define MAX_HP_WIDTH 160
#define MAX_EXP_WIDTH 214

#define DECLARE_SINGLETON(ClassName)						\
public:														\
	static ClassName* Get_Instance()						\
	{														\
		if (nullptr == m_pInstance)							\
			m_pInstance = new ClassName;					\
		return m_pInstance;									\
	}														\
	static void Destroy_Instance()							\
	{														\
		if (m_pInstance)									\
		{													\
			delete m_pInstance;								\
			m_pInstance = nullptr;							\
		}													\
	}														\
private:													\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)						\
ClassName*  ClassName::m_pInstance = nullptr;


#ifdef _AFX
#define  ERR_MSG(MSG) AfxMessageBox(MSG)
#else
#define ERR_MSG(MSG) MessageBox(nullptr, MSG, L"SystemError", MB_OK)
#endif // _AFX


