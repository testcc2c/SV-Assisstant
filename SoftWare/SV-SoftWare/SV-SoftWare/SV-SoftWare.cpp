// SV-SoftWare.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SV-SoftWare.h"
#include "Origin/Power Management.h"
#include "Origin\service.h"
#include "Origin\startup.h"
#include "Origin\TaskScheduler.h"
#include "Origin\CConnect.h"
using namespace SV_ASSIST::Software;

class UnCopyable
{
protected:
	UnCopyable() {}
	~UnCopyable() {}

private:
	UnCopyable(const UnCopyable& x);
	UnCopyable& operator=(const UnCopyable& x);
};

class SV_Software : private UnCopyable
{
public:
	static SV_Software* Instance();
	SV_Software() {}
	~SV_Software() {}

	BOOL PowerManagement();
	BOOL ChangeBlueCrash(BOOL AutoReboot);
	BOOL FireWall(BOOL EnableFireWall);
	BOOL EnumService(std::list<Service_Struct>& data);
	BOOL AutoList(std::vector<RegKeyDetail>& ListEnumKeyValue);
	BOOL EnumFolderTaskScheduler(std::list<TaskScheduler_Struct>& data);
	BOOL EnumRuningTaskScheduler(std::list<TaskScheduler_Struct>& data);
	CConnect cont;
};

SV_Software * SV_Software::Instance()
{
	return new SV_Software();
}

BOOL SV_Software::PowerManagement()
{
	return Origin::PowerManagement();
}

BOOL SV_Software::ChangeBlueCrash(BOOL AutoReboot)
{
	return Origin::ChangeBlueCrash(AutoReboot);
}

BOOL SV_Software::FireWall(BOOL EnableFireWall)
{
	return Origin::FireWall(EnableFireWall);
}


BOOL SV_Software::EnumService(std::list<Service_Struct>& data)
{
	Origin::Enumservice(data);
	return TRUE;
}

BOOL SV_Software::AutoList(std::vector<RegKeyDetail>& ListEnumKeyValue)
{
	Origin::ShowAutoRunList(ListEnumKeyValue);
	return TRUE;
}

BOOL SV_Software::EnumFolderTaskScheduler(std::list<TaskScheduler_Struct>& data)
{
	return Origin::EnumFolderTaskScheduler(data);
}

BOOL SV_Software::EnumRuningTaskScheduler(std::list<TaskScheduler_Struct>& data)
{
	return Origin::EnumRuningTaskScheduler(data);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::PowerManagement()
{
	return SV_Software::Instance()->PowerManagement();
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::ChangeBlueCrash(BOOL AutoReboot)
{
	return SV_Software::Instance()->ChangeBlueCrash(AutoReboot);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::FireWall(BOOL EnableFireWall)
{
	return SV_Software::Instance()->FireWall(EnableFireWall);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::EnumService(std::list<Service_Struct>& data)
{
	return SV_Software::Instance()->EnumService(data);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::AutoList(std::vector<RegKeyDetail>& ListEnumKeyValue)
{
	return SV_Software::Instance()->AutoList(ListEnumKeyValue);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::EnumFolderTaskScheduler(std::list<TaskScheduler_Struct>& data)
{
	return SV_Software::Instance()->EnumFolderTaskScheduler(data);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::EnumRuningTaskScheduler(std::list<TaskScheduler_Struct>& data)
{
	return SV_Software::Instance()->EnumRuningTaskScheduler(data);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::GetTcpConnect(std::vector<ConnInfo>& connInfo)
{
	return SV_Software::Instance()->cont.GetTcpConnect(connInfo);
}

SV_SOFTWAREDLL_API BOOL SV_ASSIST::Software::GetUdpConnect(std::vector<ConnInfo>& connInfo)
{
	return  SV_Software::Instance()->cont.GetUdpConnect(connInfo);
}