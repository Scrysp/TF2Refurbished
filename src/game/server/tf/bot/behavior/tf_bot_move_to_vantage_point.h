#ifndef TF_BOT_MOVE_TO_VANTAGE_POINT_H
#define TF_BOT_MOVE_TO_VANTAGE_POINT_H
#ifdef _WIN32
#pragma once
#endif


#include "NextBotBehavior.h"

class CTFBotMoveToVantagePoint : public Action<CTFBot>
{
public:
	CTFBotMoveToVantagePoint( float max_cost );
	virtual ~CTFBotMoveToVantagePoint();

	virtual const char *GetName() const OVERRIDE;

	virtual ActionResult<CTFBot> OnStart( CTFBot *me, Action<CTFBot> *priorAction ) OVERRIDE;
	virtual ActionResult<CTFBot> Update( CTFBot *me, float dt ) OVERRIDE;

	virtual EventDesiredResult<CTFBot> OnMoveToSuccess( CTFBot *me, const Path *path ) OVERRIDE;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure( CTFBot *me, const Path *path, MoveToFailureType fail ) OVERRIDE;
	virtual EventDesiredResult<CTFBot> OnStuck( CTFBot *me ) OVERRIDE;

private:
	float m_flMaxCost;                // +0x0034
	PathFollower m_PathFollower;      // +0x0038
	CountdownTimer m_recomputePathTimer; // +0x480c
	CTFNavArea *m_VantagePoint;       // +0x4818
};

#endif
