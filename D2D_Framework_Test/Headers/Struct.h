#pragma once

typedef struct tagTexturePath
{
	wstring wstrRelativePath;
	wstring wstrObjectKey;
	wstring wstrStateKey;
	DWORD	dwCount;
}TEXPATH;

typedef struct tagTexInfo
{
	LPDIRECT3DTEXTURE9	pTexture; 
	D3DXIMAGE_INFO		tImageInfo; 
}TEXINFO;

typedef struct tagTile
{
	tagTile()
		: dwIndex(0), vPos(_vec3(0.f, 0.f, 0.f)), byOption(0), dwExtra(0), bDraw(FALSE), wstrStateKey(L"")
	{}

	DWORD dwIndex;
	_vec3 vPos;				// Left-Top
	BYTE byOption;			// NoOption, NoEnter, MapChange, MapChange(Door), Grass, Hill, EventTrigger
	DWORD dwExtra;			// MapChange -> ���� �� id, EventTrigger-> �߻���ų �̺�Ʈ
	BOOL bDraw;				
	wstring wstrStateKey;	// Draw StateKey
}TILE;

typedef struct tagFrame
{
	BYTE byCurFrame;
	BYTE byEndFrame;
	float fCurFrameTime;
	float fResetFrameTime;
}FRAME;

typedef struct tagBackgroundObj
{
	OBJ::BGOBJ eID;
	_vec3 vPos;
	FRAME tFrame;
}BGOBJ;

typedef struct tagPokemonSkill
{
	BYTE byID;				// ID
	POKeMON::TYPE eType;	// Ÿ�� (���ݽ� ����)
	BYTE byClass;			// 0 : ������ų, 1 : ��ȭ��ų, 2 : Ư����ų(�̻��)
	DWORD dwAtk;			// ����
	DWORD dwHit;			// ����
	DWORD dwPP;				// Power Point
	DWORD dwMaxPP;			// Max PP
	wstring skillName;		// ��ų �̸�

}POKeSKILL;

typedef struct tagPokemonInfo
{
	enum { MAX_SKILL_CNT = 4 };
	enum { STAT_STR, STAT_DEF, STAT_HIT, STAT_END };

	///////////////////////////////////////////////////

	tagPokemonInfo()
		: byID(0)
		, rcBattleFront()
		, rcBattleRear()
		, rcInven()
		, bMale(true)
		, dwLevel(1)
		, dwExp(0)
		, dwMaxExp(999)
		, dwHP(999)
		, dwMaxHP(999)
		, dwStr(0)
		, dwDef(0)
		, eType(POKeMON::TYPE::NORMAL)
		, iStatRank()
		, tSkill()
		, pokeName(L"")
	{}

	///////////////////////////////////////////////////

	void Set_Rect(const LONG centerX, const LONG centerY)
	{
		rcBattleFront.left = centerX - 63;
		rcBattleFront.top = centerY - 63;
		rcBattleFront.right = centerX - 1;
		rcBattleFront.bottom = centerY - 1;

		rcBattleRear.left = centerX - 63;
		rcBattleRear.top = centerY + 2;
		rcBattleRear.right = centerX - 1;
		rcBattleRear.bottom = centerY + 64;

		rcInven[0].left = centerX - 35;
		rcInven[0].top = centerY - 88;
		rcInven[0].right = centerX - 1;
		rcInven[0].bottom = centerY - 66;

		rcInven[1].left = centerX + 1;
		rcInven[1].top = centerY - 88;
		rcInven[1].right = centerX + 35;
		rcInven[1].bottom = centerY - 66;
	}

	void Reset_Rank()
	{
		iStatRank[STAT_STR] = 0;
		iStatRank[STAT_DEF] = 0;
		iStatRank[STAT_HIT] = 0;
	}

	///////////////////////////////////////////////////

	BYTE byID;				// ID
	RECT rcBattleFront;		// Battle Front Rect. 3�� Ű�� �׸� ��.
	RECT rcBattleRear;		// Battle Rear Rect. 3�� Ű�� �׸� ��.
	RECT rcInven[2];		// �κ��丮�� ��� ��Ʈ. �����ư��鼭 �׸�.
	BOOL bMale;				// true�� ���� flase�� ����
	DWORD dwLevel;			// Level
	DWORD dwExp;			// ���� ����ġ
	DWORD dwMaxExp;			// �ִ� ����ġ
	DWORD dwHP;				// Hp
	DWORD dwMaxHP;			// Max HP
	DWORD dwStr;			// ���ݷ�
	DWORD dwDef;			// ����
	POKeMON::TYPE eType;	// Ÿ�� (���� ����)
	int iStatRank[STAT_END];	// ��ȭ ��ų�� ���� ���� ����. ����� ���, ������ ����. ��Ʋ ������ 0���� �ʱ�ȭ
	POKeSKILL tSkill[MAX_SKILL_CNT];	// ���
	wstring pokeName;		// ���ϸ� �̸�

}POKeINFO;

typedef struct tagItem
{
	DWORD dwID;
	ITEM::CLASS eClass;
	wstring itemName;
	wstring itemDesc[3];
	DWORD dwIconID;
	DWORD dwCount;
}ITEMINFO;

////////////////////////////////////////////////////////////////////////////////

// Ŭ�󿡼� �Ⱦ���

typedef struct tagUnitInfo
{
#ifdef _AFX
	CString strName;
#else
	wstring strName;
#endif // _AFX
	
	int iAtk;
	int iDef;
	BYTE byJob;
	BYTE byItem;

}UNITINFO;

/*
typedef struct tagInfo
{
	D3DXVECTOR3 vPos; // ��ġ�� ǥ���ϱ� ���� ����. 
	D3DXVECTOR3 vDir; // ������ ǥ���ϱ� ���� ���⺤��.
	D3DXVECTOR3 vSize; // 
	D3DXVECTOR3 vLook; // �׳� ������ �Ǵ� ��. 

}INFO;
*/