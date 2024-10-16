#ifndef TF_BOT_GET_AMMO_H
#define TF_BOT_GET_AMMO_H
#ifdef _WIN32
#pragma once
#endif


#include "NextBotBehavior.h"

class CTFBotGetAmmo : public Action<CTFBot>
{
public:
	CTFBotGetAmmo();
	virtual ~CTFBotGetAmmo();

	virtual const char *GetName() const OVERRIDE;

	virtual ActionResult<CTFBot> OnStart( CTFBot *me, Action<CTFBot> *priorAction ) OVERRIDE;
	virtual ActionResult<CTFBot> Update( CTFBot *me, float dt ) OVERRIDE;

	virtual EventDesiredResult<CTFBot> OnContact( CTFBot *me, CBaseEntity *other, CGameTrace *trace ) OVERRIDE;
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess( CTFBot *me, const Path *path ) OVERRIDE;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure( CTFBot *me, const Path *path, MoveToFailureType reason ) OVERRIDE;
	virtual EventDesiredResult<CTFBot> OnStuck( CTFBot *me ) OVERRIDE;

	virtual QueryResultType ShouldHurry( const INextBot *me ) const OVERRIDE;

	static bool IsPossible( CTFBot *actor );

private:
	PathFollower m_PathFollower;
	CHandle<CBaseEntity> m_hAmmo;
	bool m_bUsingDispenser;
};

class CAmmoFilter : public INextBotFilter
{
public:
	CAmmoFilter( CTFPlayer *actor );

	virtual bool IsSelected( const CBaseEntity *ent ) const OVERRIDE;

private:
	CTFPlayer *m_pActor;
	mutable float m_flMinCost;
};

#endif