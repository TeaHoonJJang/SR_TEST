#pragma once
#include "GameObject.h"
class CPessive :
	public CGameObject
{
public:
	CPessive();
	virtual ~CPessive();

	// CGameObject��(��) ���� ��ӵ�
	virtual HRESULT Ready_GameObject() override;
	virtual int Update_GameObject() override;
	virtual void Late_Update_GameObject() override;
	virtual void Render_GameObject() override;
	virtual void Relaese_GameObject() override;
	
public:
	void Image(const wstring& wstrObjectKey, const wstring& wstrStateKey, float EndFrame);
	void Image_Spark(const wstring& wstrObjectKey, const wstring& wstrStateKey, float EndFrame, float _x, float _y, bool _Dir);
	void Image_Spark2(const wstring& wstrObjectKey, const wstring& wstrStateKey, float EndFrame, float _x, float _y, bool _Dir);

public:
	void FrameMove(float fSpeed = 1.f);
	void Ready_Rect();
private:
	_vec3 m_vPlayer;
	float m_fTime;

};

