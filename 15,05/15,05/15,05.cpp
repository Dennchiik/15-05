#include <iostream>
using namespace std;

class House
{
public:
    virtual ~House() = default;
};

class PanelHouse : public House
{
public:
    PanelHouse()
    {
        cout << "Panel house built\n";
    }
};

class WoodHouse : public House
{
public:
    WoodHouse()
    {
        cout << "Wooden house built\n";
    }
};

class GamingPC
{
public:
    virtual ~GamingPC() = default;
};

class HighEndGamingPC : public GamingPC
{
public:
    HighEndGamingPC()
    {
        cout << "High-end gaming PC built\n";
    }
};

class MidRangeGamingPC : public GamingPC
{
public:
    MidRangeGamingPC()
    {
        cout << "Mid-range gaming PC built\n";
    }
};

class Developer
{
public:
    virtual ~Developer() = default;
    virtual House* CreateHouse() = 0;
};

class PCDeveloper
{
public:
    virtual ~PCDeveloper() = default;
    virtual GamingPC* CreatePC() = 0;
};

class PanelDeveloper : public Developer
{
public:
    House* CreateHouse() override
    {
        return new PanelHouse;
    }
};

class WoodDeveloper : public Developer
{
public:
    House* CreateHouse() override
    {
        return new WoodHouse;
    }
};

class HighEndPCDeveloper : public PCDeveloper
{
public:
    GamingPC* CreatePC() override
    {
        return new HighEndGamingPC;
    }
};

class MidRangePCDeveloper : public PCDeveloper
{
public:
    GamingPC* CreatePC() override
    {
        return new MidRangeGamingPC;
    }
};

House* ClientHouse(Developer* pDev)
{
    return pDev->CreateHouse();
}

GamingPC* ClientPC(PCDeveloper* pDev)
{
    return pDev->CreatePC();
}

int main()
{
    Developer* pDev = new PanelDeveloper();
    House* pHouse = ClientHouse(pDev);
    delete pHouse;
    delete pDev;

    pDev = new WoodDeveloper();
    pHouse = ClientHouse(pDev);
    delete pHouse;
    delete pDev;

    PCDeveloper* pcDev = new HighEndPCDeveloper();
    GamingPC* pPC = ClientPC(pcDev);
    delete pPC;
    delete pcDev;

    pcDev = new MidRangePCDeveloper();
    pPC = ClientPC(pcDev);
    delete pPC;
    delete pcDev;
}
