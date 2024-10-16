//========= Copyright � Valve LLC, All rights reserved. =======================
//
// Purpose:		
//
// $NoKeywords: $
//=============================================================================
#ifndef TF_BOT_DELIVER_FLAG__H
#define TF_BOT_DELIVER_FLAG__H
#ifdef _WIN32
#pragma once
#endif


#include "NextBotBehavior.h"

class CTFBotDeliverFlag : public Action<CTFBot>
{
	DECLARE_CLASS( CTFBotDeliverFlag, Action<CTFBot> );
public:
	virtual ~CTFBotDeliverFlag() {}

	virtual const char *GetName() const OVERRIDE;

	virtual ActionResult<CTFBot> OnStart( CTFBot *me, Action<CTFBot> *priorAction ) OVERRIDE;
	virtual ActionResult<CTFBot> Update( CTFBot *me, float dt ) OVERRIDE;
	virtual void OnEnd( CTFBot *me, Action<CTFBot> *newAction ) OVERRIDE;

	virtual QueryResultType ShouldHurry( const INextBot *me ) const OVERRIDE;
	virtual QueryResultType ShouldRetreat( const INextBot *me ) const OVERRIDE;

	virtual EventDesiredResult< CTFBot > OnContact( CTFBot *me, CBaseEntity *other, CGameTrace *result = NULL ) OVERRIDE;

private:
	bool UpgradeOverTime( CTFBot *me );

	PathFollower m_PathFollower;
	CountdownTimer m_recomputePathTimer;
	float m_flTotalTravelDistance;
	CountdownTimer m_upgradeTimer;
	int m_nUpgradeLevel;
	CountdownTimer m_buffPulseTimer;
};


class CTFBotPushToCapturePoint : public Action<CTFBot>
{
	DECLARE_CLASS( CTFBotPushToCapturePoint, Action<CTFBot> );
public:
	CTFBotPushToCapturePoint( Action<CTFBot> *doneAction )
		: m_pDoneAction( doneAction ) {}
	virtual ~CTFBotPushToCapturePoint() {}

	virtual const char *GetName() const OVERRIDE;

	virtual ActionResult<CTFBot> Update( CTFBot *me, float dt ) OVERRIDE;

	virtual EventDesiredResult<CTFBot> OnNavAreaChanged( CTFBot *me, CNavArea *area1, CNavArea *area2 ) OVERRIDE;

private:
	PathFollower m_PathFollower;
	CountdownTimer m_recomputePathTimer;
	Action<CTFBot> *m_pDoneAction;
};

#endif
